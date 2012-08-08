#include<fstream>
#include<algorithm>
#define inf "cutii.in"
#define outf "cutii.out"
#define NMax 3501
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int N,T;
int best[NMax];
int AIB[NMax][NMax];

struct cutie {
    int x, y, z;
} c[NMax];

inline int bit(int i) { return ( i & (-i) ); }

inline int max(int a, int b) { return ( a>b ? a : b ); }

bool rule(cutie a,cutie b)
{
    if(a.z<b.z)return true;
    else if(a.z==b.z)
    {
        if(a.y<b.y)return true;
        else if(a.y==b.y)
        {
            if(a.x<b.x)return true;
            else return false;
        }
        return false;
    }
    return false;
}

void update(int x, int y, int val) {
    for(int i = x; i<=N; i += bit(i) )
        for(int j = y; j<=N; j += bit(j) )
            AIB[i][j] = max( AIB[i][j], val );
}

void update2(int x, int y, int val) {
    for(int i = x; i<=N; i += bit(i) )
        for(int j = y; j<=N; j += bit(j) )
            AIB[i][j] = val;
}

int query(int x, int y) {
    int rez = 0;
    for(int i = x; i>0; i -= bit(i))
        for(int j = y; j>0; j -= bit(j))
            rez = max(rez, AIB[i][j]);
    return rez;
}

void Rezolva()
{
    int sol=1;
    sort(c+1,c+N+1,rule);

    best[1]=1;
    update(c[1].x, c[1].y, 1);

    for(int i=2; i<=N; i++) {
        best[i] = 1 + query(c[i].x-1, c[i].y-1);
        update(c[i].x, c[i].y, best[i]);
        sol = max(sol, best[i]);
    }

    g<<sol<<"\n";
}

void Citire()
{
    f>>N>>T;
    for(int i=1;i<=T;i++) {
        for(int j=1;j<=N;j++){ f>>c[j].x>>c[j].y>>c[j].z; best[j]=0; }
        Rezolva();
        for(int j=1; j<=N; j++) update2(c[j].x, c[j].y, 0);
    }
}

int main()
{
    Citire();
    f.close();
    g.close();
    return 0;
}

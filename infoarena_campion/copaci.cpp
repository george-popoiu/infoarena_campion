#include<stdio.h>
#define inf "copaci.in"
#define outf "copaci.out"
#define NMax 100100
using namespace std;

//fstream f(inf,ios::in),g(outf,ios::out);

struct punct { int x,y; };
punct P[NMax];

int N;

void read()
{
    //f>>N;
    scanf("%d",&N);
    for(int i=1; i<=N; i++) //f>>P[i].x>>P[i].y;
        scanf("%d%d",&P[i].x,&P[i].y);
    P[N+1] = P[1];
}

int cmmdc(int a,int b)
{
    int r;
    while( b )
    {
        r = a%b ;
        a = b;
        b = r;
    }
    return a;
}

inline int modul(int a) { return ( a<0 ? -a : a ); }

void solve()
{
    double area = 0.0; int b = 0;
    for(int i=1; i<=N; i++) area += ( (P[i+1].x-P[i].x)*(P[i].y+P[i+1].y) / (2.0) );
    area = ( area<0 ? -area : area );
    for(int i=1; i<=N; i++) b += ( cmmdc( modul(P[i+1].x-P[i].x), modul(P[i+1].y-P[i].y) ) + 1 ); b -= N;
    //g<< (long long)(area) + 1 - (b/2) ;
    printf("%lld", (long long)(area) + 1 - (b/2) );
}

int main()
{
    freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	//f.close(); g.close();
	return 0;
}

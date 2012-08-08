#include<fstream>
#include<algorithm>
#include<bitset>
#include<vector>
#include<list>
#define inf "oite.in"
#define outf "oite.out"
#define CMax 1100
#define DMax 1100000
#define MOD 666013
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int L,C;
int v[CMax];
int nr,rez;
//bitset<SMax> b;
vector<int> b[MOD];

struct suma { int t,a,b; };

suma s[DMax];

void read()
{
f>>C>>L;
for(int i=1; i<=C; i++) f>>v[i];
}

struct cmp
{
bool operator () (const suma &x, const suma &y)
    {
    if( x.t < y.t ) return true;
    return false;
    }
};

int cauta(int val,int st,int dr)
{
int m;
while( st<=dr )
    {
    m = (st+dr)/2 ;
    if( s[m].t == val ) return m;
    else if( s[m].t < val ) st = m+1 ;
    else if( s[m].t > val ) dr = m-1;
    }
return -1;
}

inline int merge(int i,int j)
{
if ( (s[i].a!=s[j].a) && (s[i].a!=s[j].b) && (s[i].b!=s[j].a) && (s[i].b!=s[j].b) ) return 1;
return 0;
}

inline int h(int a,int b,int c,int d)
{
int A[4];
A[0] = a; A[1]=b; A[2]=c; A[3]=d;
sort( A, A+3 );
return (A[0]*A[0]*A[0]*A[0])%MOD + (A[1]*A[1]*A[1]*A[1])%MOD + (A[2]*A[2]*A[2]*A[2])%MOD + (A[3]*A[3]*A[3]*A[3])%MOD;
}

/*inline void print(int i,int j)
{
g<<s[i].a<<" "<<s[i].b<<" "<<s[j].a<<" "<<s[j].b<<"\n";
}*/

/*void solve()
{
int p;
//toate sumele de 2 cifre
for(int i=1; i<C; i++)
    for(int j=i+1; j<=C; j++) s[++nr].t = v[i]+v[j] , s[nr].a = i , s[nr].b = j;
//sortez sumele
sort( s+1, s+nr+1, cmp() );
//for(int i=1; i<=nr; i++) g<<s[i].t <<" "<< s[i].a <<" "<< s[i].b <<"\n";
//rezolv
for(int i=1; i<nr; i++)
    {
    if( L-s[i].t < 0 ) break;
    p = cauta( L-s[i].t , i+1, nr ) ;
    if( p!=-1 )
        {
        if( merge(i,p) && !b[ h(s[i].a,s[i].b,s[p].a,s[p].b) ] ) rez++, b[ h(s[i].a,s[i].b,s[p].a,s[p].b) ] = 1;
        int j=p-1;
        while( s[j].t == L-s[i].t && j!=i )
            {
            if( merge(i,j) && !b[ h(s[i].a,s[i].b,s[j].a,s[j].b) ] ) rez++ , b[ h(s[i].a,s[i].b,s[j].a,s[j].b) ] = 1;
            j--;
            }
        j = p+1;
        while( s[j].t == L-s[i].t && j<=nr )
            {
            if( merge(i,j) && !b[ h(s[i].a,s[i].b,s[j].a,s[j].b) ] ) rez++, b[ h(s[i].a,s[i].b,s[j].a,s[j].b) ] = 1;
            j++;
            }
        }
    }
g<< rez;
}*/

int main()
{
//read(); solve();
f.close(); g.close();
return 0;
}

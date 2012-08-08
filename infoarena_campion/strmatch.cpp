#include<fstream>
#include<string.h>
#define inf "strmatch.in"
#define outf "strmatch.out"
#define Max 2000100
#define ODim 1000
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

char T[Max],P[Max];
int n,m,urm[Max];
int nr,sol[Max];

void read()
{
f.get( P+1, Max-1 ); f.get();
f.get( T+1, Max-1 );
n = strlen( T+1 );
m = strlen( P+1 );
}

void prefix()
{
int k=0;
urm[1]=0;
for(int i=2; i<=m; i++)
    {
    while( k>0 && P[k+1]!=P[i] ) k=urm[k];
    if( P[k+1]==P[i] ) k++;
    urm[i]=k;
    }
}

void solve()
{
prefix();
int k=0;
for(int i=1; i<=n; i++)
    {
    while( k>0 && P[k+1]!=T[i] ) k=urm[k];
    if( P[k+1]==T[i] ) k++;
    if( k==m ) sol[++nr]=i-m;
    }
g<<nr<<"\n";
for(int i=1; i<=nr && i<=ODim; i++) g<<sol[i]<<" ";
}

int main()
{
read(); solve();
f.close(); g.close();
return 0;
}

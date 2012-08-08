#include<stdio.h>
#include<string.h>
#define inf "seti.in"
#define outf "seti.out"
#define LMax 200100
using namespace std;

char T[LMax],P[LMax],op[LMax];
int n,len,nro;
int urm[LMax];

inline void read()
{
scanf("%s", T+1);
scanf("%s", op+1);
n = strlen(T+1);
nro = strlen(op+1);
}

void prefix(char p[],int urm[],int &k,int &poz,int dim)
{
for(int i=poz; i<=dim; i++ )
    {
    while( k>0 && p[k+1]!=p[i] ) k=urm[k];
    if( p[k+1]==p[i] ) k++;
    urm[i]=k;
    }
if( dim>=2 ) poz = dim;
}

int KMP(char T[], char P[], int urm[],int dim,int pdim)
{
int nr=0,k=0;
for(int i=1; i<=dim; i++)
    {
    while( k>0 && P[k+1]!=T[i] ) k=urm[k];
    if( P[k+1]==T[i] ) k++;
    if( k==pdim ) nr++;
    }
return nr;
}

void solve()
{
int poz=2,k=0;
urm[1]=0;
for(int i=1; i<=nro; i++)
    if( op[i]!='?' )
        {
        P[++len] = op[i];
        prefix( P, urm, k, poz, len );
        }
    else printf( "%d\n", KMP( T, P, urm, n, len ) );
}

int main()
{
freopen(inf,"r",stdin);
freopen(outf,"w",stdout);
read(); solve();
return 0;
}

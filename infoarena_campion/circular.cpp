#include<stdio.h>
#define inf "circular.in"
#define outf "circular.out"
#define NMax 20100
using namespace std;

int n;
int urm[NMax];
char T[2*NMax],P[NMax];

void read()
{
scanf("%d",&n);
scanf("%s",T+1);
scanf("%s",P+1);
for(int i=1; i<=n; i++) T[n+i]=T[i];
}

void prefix(char *p,int urm[],int dim)
{
int k=0;
urm[1]=0;
for(int i=2; i<=dim; i++)
    {
    while( k>0 && p[k+1]!=p[i] ) k=urm[k];
    if( p[k+1]==p[i] ) k++;
    urm[i]=k;
    }
}

void solve()
{
prefix( P, urm, n );
int k=0;
for(int i=1; i<=2*n; i++)
    {
    while( k>0 && P[k+1]!=T[i] ) k=urm[k];
    if( P[k+1]==T[i] ) k++;
    if( k==n ) { printf("%d", i-k ); return; }
    }
printf("-1");
}

int main()
{
freopen(inf,"r",stdin);
freopen(outf,"w",stdout);
read(); solve();
return 0;
}

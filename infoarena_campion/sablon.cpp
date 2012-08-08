#include<stdio.h>
#include<string.h>
#define inf "sablon.in"
#define outf "sablon.out"
#define Max 500100
using namespace std;

int n,m,poz;
int urm[Max];
char p[Max];

void read()
{
scanf("%s",p+1);
n = strlen(p+1);
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
    if( k
    }
}

void solve()
{
prefix( p, urm, n );

}

int main()
{
freopen(inf,"r",stdin);
freopen(outf,"w",stdout);
read(); solve();
return 0;
}

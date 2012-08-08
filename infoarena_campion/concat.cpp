#include<stdio.h>
#include<string.h>
#define inf "concat.in"
#define outf "concat.out"
#define Max 110
#define INF 0x3f3f3f3f
using namespace std;

int n,l;
int st[Max];
int m=-INF;
int sol[Max];
char *cuvant=new char[Max];
char *c[Max];

void read()
{
scanf("%s",cuvant+1);
scanf("%d",&n);
for(int i=1; i<=n; i++)
    {
    c[i]=new char[Max];
    scanf("%s",c[i]+1);
    }
l=strlen(cuvant+1);
}

int match(int i,int p)
{
int k=p;
if( p+strlen(c[i]+1)-1 > strlen(cuvant+1) ) return 0;
for(int j=1; j<=strlen(c[i]+1); j++)
    {
    if( c[i][j]==cuvant[k] ) k++;
    else return 0;
    }
return p+strlen(c[i]+1);
}

void back(int k,int p,int t)
{
if( p-1==l )
    {
    if( t-1>m )
        {
        m=t-1;
        for(int i=1; i<=m; i++) sol[i]=st[i];
        }
    }
else
    {
    for(int i=k+1; i<=n; i++)
        {
        int poz=match(i,p);
        if( poz ) { st[t]=i; back(i,poz,t+1); }
        }
    }
}

int main()
{
freopen(inf,"r",stdin);
freopen(outf,"w",stdout);
read();
back(0,1,1);
printf("%d\n",m);
for(int i=1; i<=m; i++) printf("%d ",sol[i]);
return 0;
}

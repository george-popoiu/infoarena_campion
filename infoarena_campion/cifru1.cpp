//#include<stdio.h>
#include<string.h>
#include<fstream>
#define inf "cifru1.in"
#define outf "cifru1.out"
#define Max 100100
#define INF 0x3f3f3f3f
using namespace std;

int n,m;
int s[Max],a[Max];
int su[Max],su2[Max];
int p[Max],d=INF;

fstream f(inf,ios::in),g(outf,ios::out);

void read()
{
//scanf("%d %d",&n,&m);
f>>n>>m;
for(int i=1; i<=n; i++) f>>s[i];
for(int i=1; i<=n; i++) f>>a[i];
}

void prefix(int v[Max],int urm[Max],int dim)
{
int k=0;
urm[1]=0;
for(int i=2; i<=dim; i++)
    {
    while( k>0 && v[k+1]!=v[i] ) k=v[k];
    if( v[k+1]==v[i] ) k++;
    urm[i]=k;
    }
}

inline int modul(int a) { return ( a<0 ? -a : a ) ; }

void solve()
{
int max=-INF,poz1,poz2=0;
//prefix(s,su,n);
prefix(a,su2,n);
/*for(int i=1; i<=n; i++)
    if( su[i]>=max ) max=su[i], poz1=i;
for(int i=1; i<=n; i++)
    if( ru[i]==max && modul(poz1-poz2)<d ) poz2=i;
d = modul(poz1-poz2);
printf("%d",d);*/
}

int main()
{
//freopen(inf,"r",stdin);
//freopen(outf,"w",stdout);
read(); solve();
f.close(); g.close();
return 0;
}

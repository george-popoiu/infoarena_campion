#include<stdio.h>
#define inf "dezastru.in"
#define outf "dezastru.out"
#define Max 30
using namespace std;

int n,k;
float p[Max],s[Max];
float a[Max][Max];
int c[Max][Max];

void read()
{
scanf("%d%d",&n,&k);
for(int i=1; i<=n; i++) scanf("%f",&p[i]) , s[i] = p[i]+s[i-1], a[i][1] = s[i] ;
}

void solve()
{
//matricea a
for(int i=2; i<=n; i++)
    for(int j=2; j<=i && j<=k; j++) a[i][j] = a[i-1][j] + p[i]*a[i-1][j-1];
//combinari
int j;
for(int i=1; i<=n; i++)
    for(c[i][0]=c[i][i]=1 , j=1; j<i; j++) c[i][j]=c[i-1][j]+c[i-1][j-1];
float rez;
rez = a[n][k]/c[n][k] ;
printf("%f",rez);
}

int main()
{
freopen(inf,"r",stdin);
freopen(outf,"w",stdout);
read();
solve();
return 0;
}

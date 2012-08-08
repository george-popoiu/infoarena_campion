#include<stdio.h>
#include<string.h>
#define inf "fat.in"
#define outf "fat.out"
#define Max 110
using namespace std;

char *a,*b,*c;
int n,m,p;
int d[Max][Max][Max];
char st[Max];
int vf;

void read()
{
a=new char[Max]; b=new char[Max]; c=new char[Max];
scanf("%s %s %s",a+1,b+1,c+1);
n=strlen(a+1); m=strlen(b+1); p=strlen(c+1);
}

inline int max(int a,int b){ return ( a>b ? a : b ); }

void solve()
{
for(int i=1; i<=n; i++)
    for(int j=1; j<=m; j++)
        for(int k=1; k<=p; k++)
            if( a[i]==b[j] && a[i]==c[k] ) d[i][j][k]=1+d[i-1][j-1][k-1];
            else d[i][j][k]=max( d[i-1][j][k], max(d[i][j-1][k],d[i][j][k-1]) );
}

void print()
{
int i,j,k,max,v;
i=n; j=m; k=p;
while( i && j && k )
    if( a[i]==b[j] && a[i]==c[k] ) st[++vf]=a[i], i--, j--, k--;
    else
        {
        max=d[i-1][j][k]; v=1;
        if( max<d[i][j-1][k] ) max=d[i][j-1][k], v=2;
        if( max<d[i][j][k-1] ) max=d[i][j][k-1], v=3;
        if( v==1 ) i--;
        else if( v==2 ) j--;
        else if( v==3 ) k--;
        }
while( vf ) printf("%c",st[vf--]);
}

int main()
{
freopen(inf,"r",stdin);
freopen(outf,"w",stdout);
read();
solve();
print();
return 0;
}

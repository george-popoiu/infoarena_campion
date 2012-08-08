#include<stdio.h>
#include<string.h>
#define inf "echilibru.in"
#define outf "echilibru.out"
#define Max 110
#define SMax 250010
using namespace std;

FILE *f, *g ;

int n,m,nr;
int a[Max],b[Max];
short *sa=new short[SMax];
short *sb=new short[SMax];
short *v=new short[SMax];

void read()
{
int i;
f = fopen(inf,"r");
fscanf( f, "%d%d", &n, &m);
for( i=1; i<=n; i++) fscanf(f,"%d",&a[i]);
for( i=1; i<=m; i++) fscanf(f,"%d",&b[i]);
fclose(f);

memset( sa, 0, sizeof(short)*SMax );
memset( sb, 0, sizeof(short)*SMax );
memset( v, 0, sizeof(short)*SMax );
}

inline int max(int a,int b) { return ( a>b ? a : b ) ; }

inline int min(int a,int b) { return ( a<b ? a : b ) ; }

void solve()
{
int i,j,lim=0;
int lim2=0;
for( i=1; i<=n; i++ )
    {
    v[ a[i] ] = 1;
    lim = max( a[i], lim );
    for( j=1; j<=lim; j++ )
        if( sa[j] && !v[ j+a[i] ] ) v[ j+a[i] ] = 1 , lim = max( lim, j+a[i] );
    for( j=1; j<=lim; j++ )
        if( !sa[j] && v[j] ) sa[j]=1 , v[j]=0 ;
        else if( v[j] ) v[j]=0 ;
    }

for( i=1; i<=m; i++ )
    {
    v[ b[i] ] = 1;
    lim2 = max( lim2, b[i] ) ;
    for( j=1; j<=lim2; j++ )
        if( sb[j] && !v[ j+b[i] ] ) v[ j+b[i] ] = 1 , lim2 = max( lim2, j+b[i] ) ;
    for( j=1; j<=lim2; j++ )
        if( !sb[j] && v[j] ) sb[j]=1, v[j]=0;
        else if( v[j] ) v[j]=0;
    }

g = fopen(outf,"w");
int d;
d=min( lim, lim2 );
for( i=1; i<=d; i++ )
    if( sa[i] && sb[i] ) nr++;
fprintf(g,"%d",nr);
fclose(g);
}

int main()
{
read();
solve();
return 0;
}

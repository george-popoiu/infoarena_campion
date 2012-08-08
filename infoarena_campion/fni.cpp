#include<stdio.h>
#include<queue>
#define inf "fni.in"
#define outf "fni.out"
#define Max 110
#define INF 0x3f3f3f3f
using namespace std;

int n;
int m[Max][Max];
int lg[Max][Max];
int a[Max][Max];
int cp[Max][Max];
int dx[]={0,0,1};
int dy[]={-1,1,0};

void read()
{
scanf("%d",&n);
for(int i=1; i<=n; i++)
    for(int j=1; j<=i; j++) scanf("%d",&a[i][j]);
for(int i=0; i<=n+1; i++) m[i][0]=-1 , m[i+1][i+2]=-1 ;
}

struct elem
{
int lin;
int col;
};

queue<elem> c;

void compute(int &smax,int &lung)
{
int linie,coloana;
elem x;
m[1][1]=a[1][1]; lg[1][1]=1;
x.lin=1; x.col=1;
c.push( x );
while( !c.empty() )
    {
    x= c.front(); c.pop();
    for(int i=0; i<3; i++)
        {
        linie=x.lin+dx[i];
        coloana=x.col+dy[i];
        if( m[ linie ][ coloana ]!=-1 )
            if( m[ linie ][ coloana ] < m[x.lin][x.col]+a[linie][coloana] )
                {
                m[ linie ][ coloana ]=m[x.lin][x.col]+a[linie][coloana];
                lg[linie][coloana]=1+lg[x.lin][x.col];
                elem b; b.lin=linie; b.col=coloana;
                c.push( b );
                }
            else if( m[linie][coloana]==m[x.lin][x.col]+a[linie][coloana] && lg[linie][coloana]>lg[x.lin][x.col]+1 )
                {
                lg[linie][coloana]=lg[x.lin][x.col]+1;
                elem b; b.lin=linie; b.col=coloana;
                c.push( b );
                }
        }
    }
int max=-INF,lmin=INF;
for(int i=1; i<=n; i++)
    if( m[n][i]>max ) max=m[n][i], lmin=lg[n][i];
    else if( m[n][i]==max && lg[n][i]<lmin ) lmin=lg[n][i];
smax=max;
lung=lmin;
}

void rotate()
{
for(int i=n; i>=1; i--)
    for(int j=i; j>=1; j--) cp[n-j+1][n-i+1]=a[i][j];
for(int i=1; i<=n; i++)
    for(int j=1; j<=i; j++) a[i][j]=cp[i][j];
}

/*void afis()
{
for(int i=1; i<=n; i++)
    {
    for(int j=1; j<=i; j++) printf("%d",a[i][j]);
    printf("\n");
    }
printf("\n");
}*/

void solve()
{
int c,max=-INF,lmin=INF,l;
/*for(int i=1; i<=3; i++)
    {
    compute(c,l);
    if( c>max ) max=c, lmin=l;
    else if( c==max && l<lmin ) lmin=l;
    //afis();
    rotate();
    }*/
compute(c,l);
printf("%d\n%d",max,lmin);
}

int main()
{
freopen(inf,"r",stdin);
freopen(outf,"w",stdout);
read();
solve();
return 0;
}

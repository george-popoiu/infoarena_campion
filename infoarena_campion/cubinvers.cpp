#include<stdio.h>
#include<vector>
#define inf "cubinvers.in"
#define outf "cubinvers.out"
#define INF 0x3f3f3f3f
#define NMax 30
using namespace std;

int m=-INF;
int N;
vector<int> data;
int fn;
vector<int> freenumbers;
vector<int> invers;
int solution[NMax];
vector<int> config;
int fixnumbers[NMax];
int uz[NMax];


void read()
{
int a;
scanf("%d",&N);
data=vector<int>(N+1);
config=vector<int>(N+1);
for(int i=1; i<=N; i++)
    {
    scanf("%d", &a );
    if( a ) data[i]=a, fixnumbers[a]=1, fn++;
    }
freenumbers=vector<int>(N-fn+1);
int j=0;
for(int i=1; i<=N; i++)
    if( !fixnumbers[i] ) freenumbers[++j]=i;
//for(int i=1; i<=N-fn; i++) printf("%d ",freenumbers[i] );
}

void inverseaza(int a)
{
vector<int> aux(NMax,0);
int j=0;
for(int i=N; i>=N-a+1; i--) aux[++j]=invers[i];
j=0;
for(int i=N-a+1; i<=N; i++) invers[i]=aux[++j];
}

void solve()
{
int a;
int j=0;
int nr=0;
invers=vector<int>(N+1);
invers=data;
for(int i=1; i<=N; i++)
    if( !invers[i] ) invers[i]=solution[++j];
vector<int> copy_invers(N+1);
copy_invers=invers;
while( 1 )
    {
    nr++;
    a=invers[N];
    inverseaza(a);
    if( invers[N]==1 ) break;
    }
if( m<nr )
    {
    m=nr;
    config=copy_invers;
    }
}

void back(int k)
{
if( k-1 == N-fn ) solve();
else
    {
    for(int i=1; i<=N-fn; i++)
        if( !uz[ freenumbers[i] ] )
            {
            uz[ freenumbers[i] ] = 1 ;
            solution[k]=freenumbers[i];
            back(k+1);
            uz[ freenumbers[i] ] = 0;
            }
    }
}

int main()
{
freopen(inf,"r",stdin);
freopen(outf,"w",stdout);
read();
back(1);
printf("%d\n",m);
for(int i=1; i<=N; i++) printf("%d ",config[i] );
return 0;
}

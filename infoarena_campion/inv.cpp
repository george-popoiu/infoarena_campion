#include<fstream>
#include<algorithm>
#define inf "inv.in"
#define outf "inv.out"
#define NMax 100100
#define MOD 9917
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int result;
int n;
int v[NMax];

void read()
{
f>>n;
for(int i=1; i<=n; i++) f>>v[i];
}

void merge(int st,int dr,int m)
{
int a[NMax],b[NMax],i,j,k=0,nr[NMax];
i=st; j=m+1;
while( i<=m && j<=dr )
    {
    if( v[i]<=v[j] ) a[++k]=v[i++], b[k]=1;
    else a[++k]=v[j++], b[k]=2;
    }
if( i<=m )
    for( j=i; j<=m; j++ ) a[++k]=v[j], b[k]=1;
else
    for( i=j; i<=dr; i++ ) a[++k]=v[i], b[k]=2;
nr[0]=0;
for(int t=1; t<=k; t++)
    {
    nr[t]=nr[t-1];
    if( b[t]==2 ) nr[t]++;
    else  result += nr[t-1] , result %= MOD ;
    }
k=1;
for( i=st; i<=dr; i++) v[i]=a[k++];
}

void mergesort(int st,int dr)
{
int m;
if( dr-st <= 1 )
    {
    if( v[st]>v[dr] ) { swap(v[dr],v[st]) ; result++ ; result %= MOD ;}
    }
else
    {
    m = (st+dr)/2;
    mergesort(st,m);
    mergesort(m+1,dr);
    merge(st,dr,m);
    }
}

void solve()
{
mergesort(1,n);
//for(int i=1; i<=n; i++) g<<v[i]<<" ";
g<< result;
}

int main()
{
read(); solve();
f.close(); g.close();
return 0;
}

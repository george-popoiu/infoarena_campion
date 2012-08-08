#include<fstream>
#define inf "permutord.in"
#define outf "permutord.out"
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int n,k;
int p[10],fa[10];

void read()
{
f>>n>>k;
}

void solve()
{
fa[0]=1;
for( int i=1; i<=n; i++ ) fa[i]=i*fa[i-1];
for( int i=1; i<=n ; i++ )
    {
    p[i] = ( k/fa[n-i] ) + 1 ;
    k -= (p[i]-1) * fa[n-i] ;
    }
for( int i=n-1; i>=1 ; i-- )
    for( int j=i+1; j<=n; j++ )
        if( p[j]>=p[i] ) p[j]++;
for(int i=1; i<=n; i++) g<<p[i]<<" ";
}

int main()
{
read();
solve();
f.close();
g.close();
return 0;
}

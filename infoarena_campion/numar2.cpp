#include<fstream>
#include<bitset>
#define inf "numar2.in"
#define outf "numar2.out"
#define NMax 110
#define DIM 100000000
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int n,m;
int v[NMax];
bitset<DIM> a;

void read()
{
f>>n>>m;
for(int i=1; i<=n; i++) f>>v[i];
}

void solve()
{
int nr=0;
for(int i=1; i<=n; i++)
    if( !a[ v[i] ] )
        {
        a[ v[i] ] = 1;
        for(int j = v[i]+v[i] ; j<DIM ; j+=v[i] ) {}//a[j]=1;
        }
/*for(int i=1; i<DIM; i++)
    if( a[i] )
        {
        ++nr;
        if( nr==m )  { g<<i; return; }
        }*/
}

int main()
{
read(); solve();
f.close(); g.close();
return 0;
}

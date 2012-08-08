#include<fstream>
#include<algorithm>
#define inf "orase.in"
#define outf "orase.out"
#define NMax 50100
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int M,N;

struct oras { int d,l; };

oras v[NMax];

void read()
{
f>>M>>N;
for(int i=1; i<=N; i++) f>> v[i].d >> v[i].l ;
}

struct cmp
{
bool operator() ( const oras &a, const oras &b )
    {
    if( a.d<b.d ) return true;
    return false;
    }
};

void solve()
{
sort( v+1, v+N+1, cmp() );
int result,ind;
result = 0 ;
ind = 1;
for(int i=2; i<=N; i++)
    {
    if( v[i].d - v[ind].d + v[i].l + v[ind].l > result ) result = v[i].d - v[ind].d + v[i].l + v[ind].l ;
    if( v[i].l - v[i].d > v[ind].l - v[ind].d ) ind=i;
    }
g<< result;
}

int main()
{
read(); solve();
f.close(); g.close();
return 0;
}

#include<fstream>
#define inf "arb1.in"
#define outf "arb1.out"
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int n;
int st[100],dr[100];

void read()
{
f>>n;
for(int i=1; i<=n; i++) f>>st[i];
for(int i=1; i<=n; i++) f>>dr[i];
}

struct nod
{
int nr;
nod *st,*dr;
};

void svd(int nod)
{
if( nod )
    {
    svd( st[nod] );
    g<<nod<<" ";
    svd( dr[nod] );
    }
}

void vsd(int nod)
{
if( nod )
    {
    g<<nod<<" ";
    vsd( st[nod] );
    vsd( dr[nod] );
    }
}

void sdv(int nod)
{
if( nod )
    {
    sdv( st[nod] );
    sdv( dr[nod] );
    g<<nod<<" ";
    }
}

void solve()
{
svd(1); g<<"\n";
vsd(1); g<<"\n";
sdv(1); g<<"\n";
}

int main()
{
read(); solve();
f.close(); g.close();
return 0;
}

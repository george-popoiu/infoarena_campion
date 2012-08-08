#include<fstream>
#define inf "arb1.in"
#define outf "arb1.out"
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int n;
int st[100],dr[100];
struct Nod { int nr; Nod *st,*dr; };
Nod *v;

void read()
{
f>>n;
for(int i=1; i<=n; i++) f>>st[i];
for(int i=1; i<=n; i++) f>>dr[i];
}

Nod* arb(int nod)
{
if( nod )
    {
    Nod *c = new Nod;
    c->nr = nod;
    c->st = arb( st[nod] );
    c->dr = arb( dr[nod] );
    return c;
    }
return 0;
}

void svd(Nod *s)
{
if( s )
    {
    svd( s->st );
    g<< s->nr <<" ";
    svd( s->dr );
    }
}

void vsd(Nod *s)
{
if( s )
    {
    g<< s->nr <<" ";
    vsd( s->st );
    vsd( s->dr );
    }
}

void sdv(Nod *s)
{
if( s )
    {
    sdv( s->st );
    sdv( s->dr );
    g<< s->nr <<" ";
    }
}

void solve()
{
v = arb(1);
svd(v); g<<"\n";
vsd(v); g<<"\n";
sdv(v);
}

int main()
{
read(); solve();
f.close(); g.close();
return 0;
}

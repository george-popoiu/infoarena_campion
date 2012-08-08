#include<fstream>
#define inf "arb4.in"
#define outf "arb4.out"
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int n;

struct nod
{
int nr;
nod *as,*ad;
nod *p;
};

nod *r;

void insert(nod *&c,nod *t,int val)
{
if(c)
    if( val < c->nr ) insert( c->as, c, val );
    else insert( c->ad, c, val );
else
    {
    c = new nod;
    c->as = c->ad = 0;
    c->nr = val;
    c->p = t;
    }
}

void svd(nod *c)
{
if( c )
    {
    svd( c->as );
    g<< c->nr << " ";
    svd( c->ad );
    }
}

void cmmd(nod *&c,nod *&f)
{
if( f->ad ) cmmd( c, f->ad );
else
    {
    c->nr = f->nr ;
    nod *man = f;
    f = f->as ;
    delete man;
    }
}

void del( nod *&c, int val )
{
if( c )
    if( c->nr == val )
        {
        if( !c->as && !c->ad )
            {
            delete c;
            c=0;
            }
        else if( !c->as && c->ad )
            {
            nod *f = c->ad ;
            f->p = c->p;
            delete c;
            c = f;
            }
        else if( !c->ad && c->as )
            {
            nod *f = c->as ;
            f->p = c->p ;
            delete c;
            c = f;
            }
        else cmmd(c,c->as);
        }
    else
        {
        if( val < c->nr ) del( c->as, val );
        else del( c->ad, val );
        }
}

void caut( nod *c, nod *&man, int val )
{
if( c )
    {
    if( c->nr == val ) man = c;
    else
        {
        if( val < c->nr ) caut( c->as, man, val );
        else caut( c->ad, man, val );
        }
    }
}

void RD( nod *&x )
{
if( !x->as ) return;
nod *y=x->as;
int aux=x->nr;
x->nr = y->nr; y->nr = aux;
nod *m1 = x->ad;
nod *m2 = y->as;
nod *m3 = y->ad ;
x->ad = y; y->p = x;
y->ad = m1; if( m1 ) m1->p = y;
y->as = m3; if( m3 ) m3->p = y;
x->as = m2; if( m2 ) m2->p = x;
}

int main()
{

r = 0;
int a;
f>>n;
for(int i=1; i<=n; i++) f>>a , insert(r,0,a);
svd(r); g<<endl;

nod *b=0;
caut(r,b,7);
if( b ) RD(b);
del( r, 3);
svd(r);

f.close(); g.close();
return 0;
}

#include<fstream>
#define inf "arb3.in"
#define outf "arb3.out"
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int n;

struct nod
{
int nr;
nod *as,*ad,*p;
};

nod *r;

void insert( nod *&c, nod *t, int val )
{
if( c )
    if( val < c->nr ) insert( c->as, c, val );
    else insert( c->ad, c, val );
else {
    c = new nod;
    c->as = c->ad = 0;
    c->p = t;
    c->nr = val; }
}

void SVD(nod *c) { if( c ) SVD( c->as ), g<< c->nr <<" " , SVD( c->ad ) ; }

void caut( nod *c, nod *&adr ,  int val )
{
if( c )
    if( c->nr < val ) caut( c->ad, adr, val );
    else
        if( c->nr > val ) caut( c->as, adr, val);
        else adr = c;
else adr=0;
}

void cmmd( nod *&c, nod *&f )
{
if( f->ad ) cmmd( c, f->ad );
else
    {
    c->nr = f->nr ;
    if( f->p )
        if( f->as )
            {
            nod *man = f->as;
            if( f->p->as == f ) f->p->as = man , man->p=f->p ;
            else f->p->ad = man , man->p = f->p ;
            }
        else
            if( f->p->as == f ) f->p->as = 0;
            else f->p->ad = 0;
    delete f; f=0;
    }
}

void sterge( nod *&c )
{
if( c )
    if( c->as==0 && c->ad==0 )
        {
        if( c->p )
            if( c->p->as == c ) c->p->as = 0;
            else c->p->ad = 0;
        delete c; c=NULL;
        }
    else if( !c->as && c->ad )
        {
        nod *f = c->ad ;
        if( c->p )
            if( c->p->as == c ) c->p->as = f, f->p = c->p , delete c;
            else c->p->ad = f , f->p = c->p , delete c;
        else
            {
            c->nr = f->nr ; c->as = f->as ; c->ad = f->ad ;
            delete f; f=0;
            }
        }
    else if( !c->ad && c->as )
        {
        nod *f = c->as ;
        if( c->p )
            if( c->p->as == c ) f->p->as = f, f->p = c->p , delete c;
            else c->p->ad = f, f->p = c->p , delete c;
        else
            {
            c->nr = f->nr ; c->as = f->as ; c->ad = f->ad ;
            delete f; f=0;
            }
        }
    else cmmd( c, c->as );
}

int main()
{
int a;
f>>n;
for(int i=1; i<=n; i++) f>>a, insert(r,0,a);

SVD(r); g<<endl;

nod *man;
caut(r,man,5);
sterge( man );
SVD(r); g<<endl;

caut(r,man,3);
sterge( man );
g<< r->ad;
//SVD(r); g<<endl;

f.close(); g.close();
return 0;
}

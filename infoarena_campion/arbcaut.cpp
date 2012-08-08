#include<fstream>
#define inf "arbcaut.in"
#define outf "arbcaut.out"
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int n;

struct nod
{
int info;
nod *st,*dr,*p;
};

nod *r;

void insert( nod*& c,nod *t,int val )
{
if( c )
    {
    if( val<c->info ) insert( c->st, c, val );
    else insert( c->dr, c, val );
    }
else
    if( t )
        {
        c = new nod;
        c->st=c->dr=0;
        c->info = val;
        c->p = t;
        }
    else
        {
        c = new nod;
        c->st=c->dr=0;
        c->p = 0;
        c->info = val;
        }
}

nod* maxim(nod *c)
{
while( c->dr ) c = c->dr ;
return c;
}

nod* minim(nod *c)
{
while( c->st ) c = c->st;
return c;
}

void SVD(nod *c)
{
if( c )
    {
    SVD(c->st);
    g<<c->info<<" ";
    SVD(c->dr);
    }
}

nod* caut(nod *c,int val)
{
while( c )
    if( val==c->info ) return c;
    else if( val < c->info ) c = c->st;
    else c = c->dr;
}

nod* succesor( nod *c )
{
if( c->dr ) return minim( c->dr );
nod *x = c;
nod *y = c->p ;
while( y && x == y->dr ) x = y , y = y->p ;
return y;
}

nod* predecesor( nod *c )
{
if( c->st ) return maxim( c->st );
nod *x = c;
nod *y = c->p ;
while( y && x == y->st ) x = y , y = y->p ;
return y;
}

void sterge( nod *&c )
{
if( !c->st && !c->dr ) //nodul nu are fii
    {
    if( c->p )
        if(c->p->dr == c ) c->p->dr = 0;
        else c->p->st = 0;
    delete c;
    return;
    }
if( ( c->st && !c->dr ) || ( !c->st && c->dr ) ) // are 1 fiu
    {
    nod *x;
    if( c->st ) x = c->st ;
    else x = c->dr;
    if( c->p )
        if( c->p->st == c ) c->p->st = x , delete c;
        else c->p->dr = x, delete c;
    else delete r , r = x ;
    return;
    }
//are 2 fii
nod *x = succesor(c);
c->info = x->info ;
c->dr = x->dr ;
delete x;
}

void cmmd( nod *&c, nod *&f )
{
if( f->dr ) cmmd( c, f->dr );
else
    {
    c->info = f->info ;
    nod *man = f;
    f = f->st ;
    delete man;
    }
}

void stergr( nod *&c, int val )
{
if( c )
    if( c->info == val )
        if( c->st==0 && c->dr==0 ) delete c, c=0;
        else if( c->st == 0 )
            {
            nod *f = c->dr ;
            delete c;
            c = f;
            }
        else if( c->dr==0 )
            {
            nod *f = c->st;
            delete c;
            c = f;
            }
        else cmmd( c, c->st );
    else
        if( c->info < val ) stergr( c->dr, val );
        else stergr( c->st, val );
}

int main()
{
int a;
f>>n;
for(int i=1; i<=n; i++) f>>a , insert(r,r,a);
SVD(r); g<<"\n";
stergr(r,5); SVD(r); g<<"\n";
stergr(r,4); SVD(r); g<<"\n";
stergr(r,6); SVD(r); g<<"\n";
f.close(); g.close();
return 0;
}

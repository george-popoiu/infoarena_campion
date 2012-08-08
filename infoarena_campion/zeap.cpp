#include<algorithm>
using namespace std;

#define INF 0x3f3f3f3f
#define DIM 10

struct T
{
int nr,pr,min,max,difmin;
T *as,*ad;
T( int nr, int pr, int min, int max, int difmin, T* as, T* ad )
    {
    this->nr = nr; this->pr = pr; this->min = min; this->max = max; this->difmin = difmin;
    this->as = as; this->ad = ad;
    }
} *r,*nil;

char buff[DIM];
int n;

void update(T* &c)
{
c->min = min( c->min, c->as->min );
c->max = max( c->max, c->ad->max );
c->difmin = min( min( c->as->difmin, c->ad->difmin ) , min( abs( c->nr - c->as->max ), abs( c->nr - c->ad->min ) ) );
}

void rotright(T* &c)
{
T* t = c->as;
c->as = t->ad; t->ad=c;
c=t;
if( c!=nil && c->ad != nil ) update(c->ad);
}

void rotleft(T* &c)
{
T* t = c->ad ;
c->ad = t->as; t->as = c;
c=t;
if( c!=nil && c->as != nil ) update(c->as);
}

void balance(T* &c)
{
if( c->as->pr > c->pr ) rotright(c);
if( c->ad->pr > c->pr ) rotleft(c);
update(c);
}

void insert(T* &c,int val)
{
if( c==nil )
    {
    c = new T(val,rand(),val,val,INF,nil,nil);
    ++n;
    return;
    }
if( val<c->nr ) insert( c->as, val );
else if( val>c->nr ) insert( c->ad, val );
balance(c);
}

int find(T* &c,int val)
{
if( c==nil ) return 0;
if( val == c->nr ) return 1;
else if( val < c->nr ) return find( c->as, val );
else return find( c->ad, val );
}

void erase(T* &c,int val)
{
if( c==nil ) return;
if( val < c->nr ) erase( c->as, val );
else if( val > c->nr ) erase( c->ad, val );
else
    {
    if( c->as==nil && c->ad==nil )
        {
        delete c;
        c=nil;
        }
    else
        {
        ( c->as->pr > c->ad->pr ) ? rotright(c) : rotleft(c);
        erase(c,val);
        }
    }
if( c!=nil ) update(c);
}

int main()
{
srand( time(0) ) ;
freopen("zeap.in","r",stdin);
freopen("zeap.out","w",stdout);
int x;
r = nil = new T(0,0,INF,-INF,INF,NULL,NULL);
for( ; scanf("%s",&buff) != EOF ; )
    {
    if( buff[0]=='I' )
        {
        scanf("%d",&x);
        insert(r,x);
        }
    else if( buff[0]=='C' )
        {
        scanf("%d",&x);
        printf("%d\n",find(r,x));
        }
    else if( buff[0]=='S' )
        {
        scanf("%d",&x);
        if( !find(r,x) ) printf("-1\n");
        else erase(r,x), --n ;
        }
    else if( buff[0]=='M' && buff[1]=='A' )
        {
        if( n<2 ) printf("-1\n");
        else printf("%d\n", r->max - r->min );
        }
    else
        {
        if( n<2 ) printf("-1\n");
        else printf("%d\n", r->difmin);
        }
    }
return 0;
}

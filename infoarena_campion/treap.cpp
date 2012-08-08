#include<fstream>
#include<stdlib.h>
#define inf "treap.in"
#define outf "treap.out"
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

struct T {
int key,priority;
T *left,*right;
T() { }
T( int key, int priority, T* left, T* right )
    {
    this->key = key;
    this->priority = priority;
    this->left = left ;
    this->right = right ;
    }
} *r,*nil;

void init( T* &c ) {
srand( time(0) );
c = nil = new T(0,0,NULL,NULL);
}

bool search(T* c,int val) {
if( c == nil ) return false;
if( c->key == val ) return true;
else {
    if( c->key > val ) search( c->left, val );
    else search( c->right, val ); }
}

void rotright(T* &c) {
T* t = c->left ;
c->left = t->right ; t->right = c;
c=t;
}

void rotleft( T* &c ) {
T* t = c->right;
c->right = t->left ; t->left = c;
c=t;
}

void balance(T* &c) {
if( c->left->priority > c->priority ) rotright(c);
else if( c->right->priority > c->priority ) rotleft(c);
}

void insert(T* &c,int key,int priority)
{
if( c==nil ) { c = new T(key,priority,nil,nil); return; }
if( key < c->key ) insert( c->left, key, priority );
else insert( c->right, key, priority );
balance(c);
}

void erase(T* &c,int val)
{
if( c==nil ) return;
if( val<c->key ) erase( c->left, val );
else if( val>c->key ) erase( c->right, val );
else
    {
    if( c->left==nil && c->right==nil ) delete c, c=nil;
    else
        {
        ( c->left->priority > c->right->priority ) ?  rotright(c) : rotleft(c) ;
        erase(c,val);
        }
    }
}

void svd(T* c)
{
if( c!=nil )
    {
    svd(c->left);
    g<<c->key<<" ";
    svd(c->right);
    }
}

int main()
{
init(r);
int n,a;
f>>n;
for(int i=1; i<=n; i++) f>>a, insert(r,a,rand()+1);
svd(r); g<<endl;
//erase
g<<  rand() << " " << rand() << " " << rand() << " " << rand() << " " << rand() << " " << rand() << " " << rand() << " " << rand() << " " ;
f.close(); g.close();
return 0;
}

sing namespace std;
#include<algorithm>
#include<cstdio>
#include<ctime>
const int DIM = 4*8192, MAX_N = (1<<17);
int N, M, pz;
char vec[DIM];
void cit(int &x)
 {
  x=0;
  while(vec[pz]<'0' || vec[pz]>'9')

    if(++pz==DIM) fread(vec,1,DIM,stdin),pz=0;

    while(vec[pz]>='0' && vec[pz]<='9')
    {
        x=x*10+vec[pz]-'0';
        if(++pz==DIM)fread(vec, 1, DIM, stdin),pz=0;
    }
 }
struct Treap
{
	int key, priority, frecv, nr;
	Treap *left, * right;
	Treap(){}
	Treap(int v, int p, int f, Treap *Ts, Treap *Td)
	{
		left = Ts; right = Td;
		key = v; priority = p; frecv = f; nr = f;
	}
};
Treap *H[MAX_N], *nil, *B[MAX_N];
int Q, Qe, QB, QBe;
void rotleft(Treap* &T)
{
	Treap *t = T->left;
	T->left = t->right;
	t->right = T;
	T = t;
}
inline void rotright(Treap* &T)
{
	Treap *t = T->right;
	T->right = t->left;
	t->left = T;
	T = t;
}
inline void update( Treap* &T)
{
	T->nr = T->frecv;
	T->nr += T->left->nr;
	T->nr += T->right->nr;
}
inline void balance(Treap* &T)
{
	if(T->priority < T->left->priority) rotleft(T), update(T->right);
	else if(T->priority < T->right->priority ) rotright(T), update(T->left);
	update(T);
}
void insert(Treap* &T, int key, int priority, int frecv)
{
	if( T == nil )
	{
		T = new Treap( key, priority, frecv, nil, nil );
		return;
	}
	if( key < T->key ) insert( T->left, key, priority, frecv );
	else if(key > T->key ) insert( T->right, key, priority, frecv );
	else T->frecv += frecv;
	balance(T);
}
inline void go( Treap *T, int key , int &Q, int &Qe)
{
	if( T == nil ) return;
	if(key < T->key ) go(T->left, key, Q, Qe );
	else if( key > T->key )
	{
		Q += T->nr - T->right->nr;
		go(T->right, key, Q, Qe );
	}
	else
	{
		Q += T->nr - T->right->nr;
		Qe += T->frecv;
	}
}
inline void update(int n, int l, int r, int a, int b , int x)
{
	if( a <= l && r <= b )
	{
		insert( H[n], x, rand() + 1, r - l + 1 );
		insert( B[n], x, rand() + 1, 1 );
		return;
	}
	int m = (l+r)>>1;
	if( a <= m ) update( 2*n, l, m, a, b, x);
	if( b > m  ) update(2*n+1, m+1, r, a, b, x);
	if( l <= a && b <= r ) insert( H[n], x, rand() + 1 , b-a+1);
	else if (l <= a && r <= b && r >= a) insert( H[n], x, rand() + 1, r-a+1 );
	else if ( a <= l && b <= r && b >= l) insert( H[n], x, rand() + 1, b-l+1);

}
void query(int n, int l, int r, int a, int b, int x)
{
	if( a <= l && r <= b )
	{
		go(H[n], x, Q, Qe );
		return;
	}
	int m = (r+l)>>1;
	if( a <= m ) query(2*n, l, m, a, b, x);
	if( b > m ) query(2*n+1, m+1, r, a, b, x);
	int tQ = 0, tQe = 0;
	go( B[n], x, tQ, tQe );
	if( l <= a && b <= r ) Q += ( b-a+1 )*tQ, Qe += (b-a+1)*tQe;
	else if (l <= a && r <= b && r >= a) Q += ( r-a+1 )*tQ, Qe += (r-a+1)*tQe;
	else if ( a <= l && b <= r && b >= l) Q += ( b-l+1 )*tQ, Qe += (b-l+1)*tQe;
}
void cb(int a, int b, int K)
{
	int m, st = 1, dr = MAX_N - 1;
	while( st <= dr )
	{
		m = (st+dr)>>1;
		Q = Qe = 0;
		query(1, 1, N, a, b, m );
		if( Q >= K && Q - Qe < K ) { printf("%d\n", m ); return; }
		else if( Q < K ) st = m + 1;
		else dr = m - 1;
	}
	printf("-1\n");
}
int main()
{
	freopen("bile4.in","r",stdin); freopen("bile4.out","w",stdout);
	cit(N), cit(M);
	srand(time(0));
	nil = new Treap(0, 0, 0, NULL, NULL );
	int i, a, b, k, op;
	for(i = 1; i < MAX_N; ++i) H[i] = B[i] = nil;
	for(;M;--M)
	{
		cit(op), (a), cit(b), cit(k);
		if(op == 1)
			update(1, 1, N, a+1, b+1, k);
		else
			cb(a+1, b+1, k);
	}
	return 0;

#include<fstream>
#define inf "cezar.in"
#define outf "cezar.out"
#define NMax 10100
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

struct nod { short info; nod *next; };
nod *a[NMax];

short N,K; int d[NMax];
short H[NMax],hdim;

inline void add(short x,short y)
{
	nod *p = new nod; p->info = y;
	p->next = a[x];
	a[x] = p;
}

void remove(short x,short y)
{
	if( a[x]->info == y )
	{
		nod *c = a[x];
		a[x] = a[x]->next;
		delete c;
		return;
	}

	nod *c = a[x];
	while( c->next->info != y ) c = c->next;
	nod *r = c->next;
	c->next = r->next;
	delete r;
}

void upheap(short n)
{
	short t;
	while( n>1 )
	{
		t = n>>1;
		if( d[ H[t] ] > d[ H[n] ] )
		{
			short aux = H[t]; H[t] = H[n]; H[n] = aux;
			n = t;
		}
		else return;
	}
}

void downheap(short n)
{
	short fiu;
	while( n<hdim )
	{
		fiu = n<<1;
		if( fiu>hdim ) return;

		if( fiu+1<=hdim && d[ H[fiu] ] > d[ H[fiu+1] ] ) fiu++;

		if( d[ H[n] ] > d[ H[fiu] ] )
		{
			short aux = H[fiu]; H[fiu] = H[n]; H[n] = aux;
			n = fiu;
		}
		else return;
	}
}

inline void hAdd(short x)
{
	H[++hdim] = x;
	upheap(hdim);
}

inline short hExtractMin()
{
	short m = H[1];
	H[1] = H[hdim--];
	downheap(1);
	return m;
}

void read()
{
	short x,y;
	f>>N>>K;
	for(short i=1; i<N; i++)
	{
		f>>x>>y;
		add(x,y); add(y,x);
	}
	for(short i=1; i<=N; i++) d[i]=1;
	for(short i=1; i<=N; i++)
		if( !a[i]->next ) hAdd(i);
}

void solve()
{
	int s=0;
	for(short i=1; i<N-K; i++)
	{
		short n = hExtractMin();
		s += d[n];
		d[ a[n]->info ]++;
		remove( a[n]->info , n );
		if( !a[ a[n]->info ]->next ) hAdd( a[n]->info );
	}
	g<< s;
}

int main()
{
	read(); solve();
	f.close(); g.close();
	return 0;
}

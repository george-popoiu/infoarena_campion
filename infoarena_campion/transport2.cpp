#include<stdio.h>
//#include<fstream>
#define inf "transport2.in"
#define outf "transport2.out"
#define NMax 100001
#define INF 0x3f3f3f3f
#define buffSize 32762
using namespace std;

//fstream f(inf, ios::in), g(outf, ios::out);

int N, M;
int D[NMax], poz[NMax];
int H[NMax], hdim;
int i, u, v, w, aux;
char buffer[buffSize];
int ok = 1, ind;

void read(int &x);

struct graf {
	int v, w;
	graf *next;
} *G[NMax];

inline void add(int u, int v, int w) {
	graf *t = new graf;
	t->v = v; t->w = w;
	t->next = G[u];
	G[u] = t;
}

inline int swap(int &a, int &b) { aux = a; a = b; b = aux; }

void read()
{
//	scanf("%d%d", &N, &M);
	//f>>N>>M;
	read(N); read(M);

	for(i=1; i<=M; i++) {
		//scanf("%d%d%d", &u, &v, &w);
		//f>>u>>v>>w;
		read(u); read(v); read(w);
		add(u, v, w); add(v, u, w);
	}
}

void upheap(int n) {
	int f;
	while( n>1 ) {
		f = (n>>1);
		if( D[ H[n] ] > D[ H[f] ] ) {
			swap( poz[ H[n] ], poz[ H[f] ] );
			swap( H[n], H[f] );
			n = f;
		}
		else return;
	}
}

void downheap(int n) {
	int s;
	while( n<hdim ) {
		s = (n<<1);
		if( s<=hdim ) {
			if( s+1<=hdim && D[ H[s+1] ] > D[ H[s] ] ) s++;
			if( D[ H[s] ] > D[ H[n] ] ) {
				swap( poz[ H[s] ], poz[ H[n] ] );
				swap( H[n], H[s] );
				n = s;
			}
			else return;
		}
		else return;
	}
}

inline int min(int a, int b) {
	if( a==-INF ) return b;
	if( b==-INF ) return a;
	return a<b ? a : b;
}

void solve()
{
	for(i=1; i<=N; i++) D[i] = -INF;

	hdim++; H[hdim] = 1;
	poz[1] = 1;

	while( hdim ) {
		u = H[1];
		H[1] = H[hdim]; poz[ H[hdim] ] = 1;
		hdim--; downheap(1);

		graf *t = G[u];
		while( t ) {
			v = t->v, w = t->w;
			if( D[v] < min(D[u], w) ) {
				D[v] = min(D[u], w);
				if( poz[v] ) upheap( poz[v] );
				else {
					hdim++;
					H[hdim] = v; poz[v] = hdim;
					upheap(hdim);
				}
			}
			t = t->next;
		}
	}

	printf("%d", D[N]);
	//g<<D[N];
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
//	f.close(); g.close();
	return 0;
}

void read(int &x) {
    if( ok ) {
        fread( buffer, 1, buffSize, stdin );
        ok = ind = 0;
    }

    x = 0;
    while( buffer[ind]>='0' && buffer[ind]<='9' ) {
        x = x*10 + (buffer[ind]-'0');
        ++ind;
        if( ind==buffSize ) {
            fread( buffer, 1, buffSize, stdin );
            ind = 0;
        }
    }

    while( buffer[ind]<'0' || buffer[ind]>'9' ) {
        ++ind;
        if( ind==buffSize ) {
            fread( buffer, 1, buffSize, stdin );
            ind = 0;
        }
    }
}

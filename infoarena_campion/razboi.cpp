#include<stdio.h>
#include<vector>
#define inf "razboi.in"
#define outf "razboi.out"
#define NMax 502
#define INF 0x3f3f3f3f
using namespace std;

int N, M, X;
vector< pair<int, int> > G[NMax];
int H[NMax], hdim, poz[NMax];
int D[NMax][NMax];

void read()
{
    scanf("%d%d", &N, &M);

    int a, b, c;
    for(int i=1; i<=M; i++) {
        scanf("%d%d%d", &a, &b, &c);
        G[b].push_back( make_pair(a, c) );
    }

    scanf("%d", &X);
}

void upheap(int n, int *d) {
    int f;
    while( n>1 ) {
        f = (n>>1);
        if( d[ H[n] ] < d[ H[f] ] ) {
            swap( poz[ H[n] ], poz[ H[f] ] );
            swap( H[n], H[f] );
            n = f;
        }
        else return;
    }
}

void downheap(int n, int *d) {
    int s;
    while( n<hdim ) {
        s = (n<<1);
        if( s<=hdim ) {
            if( s+1<=hdim && d[ H[s+1] ] < d[ H[s] ] ) s++;
            if( d[ H[s] ] < d[ H[n] ] ) {
                swap( poz[ H[s] ], poz[ H[n] ] );
                swap( H[s], H[n] );
                n = s;
            }
            else return;
        }
        else return;
    }
}

void dijkstra(int s, int *d) {
    for(int i=1; i<=N; i++) { d[i] = INF; poz[i] = 0; }
    hdim = 1; H[hdim] = s; poz[s] = 1; d[s] = 0;

    while( hdim ) {
        int u = H[1];
        H[1] = H[hdim]; poz[ H[hdim] ] = 1; hdim--;
        downheap(1, d);

        for(int i=0; i<G[u].size(); i++) {
            int v = G[u][i].first, w = G[u][i].second;
            if( d[v] > d[u] + w ) {
                d[v] = d[u] + w;
                if( poz[v] ) upheap(poz[v], d);
                else {
                    hdim++; H[hdim] = v; poz[v] = hdim;
                    upheap(hdim, d);
                }
            }
        }
    }
}

inline int max(int a, int b) { return a>b ? a : b; }

void solve()
{
    dijkstra(X, D[X]);

    int sol = 0;
    for(int i=1; i<=N; i++) sol = max( sol, D[X][i] );

    printf("%d\n", sol == INF ? 0 : sol);

    int u = 0, tmin = INF;
    for(int i=1; i<=N; i++) {
        dijkstra(i, D[i]);

        int t = 0;
        for(int j=1; j<=N; j++) t = max( t, D[i][j] );

        if( t<tmin ) { tmin = t; u = i; }
        else if( t==tmin && i<u ) u = i;
    }

    u == 0 ? printf("0") : printf("%d %d", u, tmin);
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

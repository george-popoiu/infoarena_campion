#include<stdio.h>
#include<vector>
#define inf "ubuntzei.in"
#define outf "ubuntzei.out"
#define KMax 15
#define NMax 2001
#define INF 0x3f3f3f3f
using namespace std;

int N, M, K;
int dp[1<<KMax][KMax];
vector< pair<int,int> > G[NMax];

int H[NMax], poz[NMax], hdim;
int C[KMax];
int D[NMax], dist[KMax][NMax];

void read()
{
    scanf("%d%d", &N, &M);

    scanf("%d", &K);
    for(int i=0; i<K; i++) scanf("%d", &C[i]);

    int x, y, z;
    for(int i=1; i<=M; i++) {
        scanf("%d%d%d", &x, &y, &z);
        G[x].push_back( make_pair(y, z) );
        G[y].push_back( make_pair(x, z) );
    }
}

void upheap(int n, int *d) {
    int f;
    while( n>1 ) {
        f = n>>1;
        if( d[ H[n] ] < d[ H[f] ] ) {
            swap( poz[ H[n] ], poz[ H[f] ] ); swap( H[n], H[f] );
            n = f;
        }
        else return;
    }
}

void downheap(int n, int *d) {
    int s;
    while( n<hdim ) {
        s = n<<1;
        if( s<=hdim ) {
            if( s+1<=hdim && d[ H[s+1] ] < d[ H[s] ] ) s++;
            if( d[ H[s] ] < d[ H[n] ] ) {
                swap( poz[ H[s] ], poz[ H[n] ] ); swap( H[s], H[n] );
                n = s;
            }
            else return;
        }
        else return;
    }
}

void dijkstra(int s, int *d) {
    for(int i=1; i<=N; i++) d[i] = INF, poz[i] = 0;

    hdim = 1; H[1] = s; poz[s] = 1; d[s] = 0;
    while( hdim ) {
        int u = H[1];
        H[1] = H[hdim]; poz[ H[hdim] ] = 1; hdim--; downheap(1, d);

        for(int i=0; i<G[u].size(); i++) {
            int v = G[u][i].first, w = G[u][i].second;
            if( d[v] > d[u] + w ) {
                d[v] = d[u] + w;
                if( poz[v] ) upheap( poz[v], d );
                else {
                    hdim++; H[hdim] = v; poz[v] = hdim;
                    upheap(hdim, d);
                }
            }
        }
    }
}

inline int bit(int i, int j) { //intoarce true daca al j-lea bit al lui i este 1
    return (i & (1<<j)) != 0;
}

void solve()
{
    dijkstra(1, D);

    if( K==0 ) {
        printf("%d", D[N]);
        return;
    }

    for(int i=0; i<K; i++) dijkstra(C[i], dist[i]);

    int i, j;
    for(int s=0; s < (1<<K); s++) {

        for(i=0; i<K; i++)
            if( s == (1<<i) ) break;

        if( i<K && s==(1<<i) ) {
            dp[s][i] = D[ C[i] ];
            continue;
        }

        for(i=0; i<K; i++) {
            dp[s][i] = INF;
            if( bit(s, i) )
                for(j=0; j<K; j++)
                    if( bit(s, j) && j!=i ) dp[s][i] = min( dp[s][i], dp[s-(1<<i)][j] + dist[j][ C[i] ] );
        }
    }

    int sol = INF;
    for(int i=0; i<K; i++) sol = min( sol, dp[ (1<<K)-1 ][i] + dist[i][N] );

    printf("%d", sol);
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

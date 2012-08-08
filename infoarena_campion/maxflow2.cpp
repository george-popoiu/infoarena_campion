#include<stdio.h>
#include<vector>
#include<queue>
#include<string.h>
#define inf "maxflow.in"
#define outf "maxflow.out"
#define NMax 1001
#define INF 0x3f3f3f3f
using namespace std;

int N, M, C[NMax][NMax], F[NMax][NMax];
int flow, viz[NMax], T[NMax];
vector<int> G[NMax];

void read()
{
    scanf("%d%d", &N, &M);

    int a, b, c;
    for(int i=1; i<=M; i++) {
        scanf("%d%d%d", &a, &b, &c);
        C[a][b] = c;
        G[a].push_back(b);
        G[b].push_back(a);
    }
}

int BFS() {
    memset( viz, 0, sizeof(viz) );
    queue<int> q; q.push(1); viz[1] = 1;

    while( !q.empty() ) {
        int u = q.front(); q.pop();
        for(int i=0; i<G[u].size(); i++) {
            int v = G[u][i];
            if( C[u][v] == F[u][v] || viz[v] ) continue;
            q.push(v);
            T[v] = u; viz[v] = 1;
        }
    }

    return viz[N];
}

inline int min(int a, int b) { return a<b ? a : b; }

void solve()
{
    while( BFS() ) {
        for(int i=0; i<G[N].size(); i++) {
            int u = G[N][i];
            if( C[u][N]==F[u][N] || !viz[u] ) continue;
            T[N] = u;

            int fmin = INF;

            for( u = N; u!=1; u = T[u] ) fmin = min( fmin, C[T[u]][u] - F[T[u]][u] );

            if( fmin==0 ) continue;

            for( u=N; u!=1; u=T[u] ) {
                F[T[u]][u] += fmin;
                F[u][T[u]] -= fmin;
            }

            flow += fmin;
        }
    }

    printf("%d", flow);
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

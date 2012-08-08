#include<stdio.h>
#include<bitset>
#define inf "pm2.in"
#define outf "pm2.out"
#define NMax 102
using namespace std;

int N, t[NMax], A[NMax][NMax], postord[NMax], nv[NMax], nr, in[NMax], out[NMax];
int earliest[NMax], latest[NMax];
bitset<NMax> viz;

void read()
{
    scanf("%d", &N);
    for(int i=1; i<=N; i++) scanf("%d", &t[i]);

    int m, a;
    for(int i=1; i<=N; i++) {
        scanf("%d", &m);
        for(int j=1; j<=m; j++) {
            scanf("%d", &a);
            A[a][i] = 1;
            out[a]++; in[i]++;
        }
    }
}

void dfs(int i, int level) {
    viz[i] = 1; nv[i] = level;
    for(int j=1; j<=N; j++)
        if( A[i][j] && !viz[j] ) dfs(j, level+1);
    postord[++nr] = i;
}

inline int max(int a, int b) { return ( a>b ? a : b ); }

inline int min(int a, int b) { return ( a<b ? a : b ); }

void solve()
{
    for(int i=1; i<=N; i++)
        if( !viz[i] ) dfs(i, 1);
    postord[++nr] = 0; postord[0] = N+1;

    for(int i=1; i<=N; i++) {
        if( !in[i] ) A[0][i] = 1, in[i]++;
        if( !out[i] ) A[i][N+1] = 1, out[i]++;
    }

    for(int i=N; i>=0; i--) {
        int u = postord[i];
        for(int j=0; j<=N; j++)
            if( A[j][u] ) earliest[u] = max( earliest[u], earliest[j] + t[j] );
    }

    latest[N+1] = earliest[N+1];

    for(int i=1; i<=N+1; i++) {
        int u = postord[i]; latest[u] = 0x3f3f3f3f;
        for(int j=1; j<=N+1; j++)
            if( A[u][j] ) latest[u] = min( latest[u], latest[j]-t[u] );
    }

    printf("%d\n", earliest[N+1]);
    for(int i=1; i<=N; i++) printf("%d %d\n", earliest[i], latest[i]);
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

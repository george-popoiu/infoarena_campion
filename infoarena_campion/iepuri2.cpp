#include<stdio.h>
#include<vector>
#define inf "iepuri2.in"
#define outf "iepuri2.out"
#define NMax 102
#define KMax 104
#define MOD 30011
using namespace std;

int N, K;
int dp[NMax][KMax], in[NMax], viz[NMax];
vector<int> G[NMax];

void read()
{
    scanf("%d%d", &N, &K);

    int a, b;
    for(int i=1; i<N; i++) {
        scanf("%d%d", &a, &b);
        in[b]++;
        G[a].push_back(b);
    }
}

void dfs(int n) {
    viz[n] = 1;
    for(int i=0; i<G[n].size(); i++) {
        int u = G[n][i];
        if( !viz[u] ) dfs(u);
    }

    for(int k=K; k>=1; k--) {
        dp[n][k] = 1;

        for(int i=0; i<G[n].size(); i++) {
            int u = G[n][i], rez = 0;

            dp[u][k+1] += dp[u][k+2]; dp[u][k+1] %= MOD;

            dp[n][k] *= dp[u][k+1]; dp[n][k] %= MOD;
        }
    }
}

void solve()
{
    int root = 1;
    for(int i=1; i<=N; i++)
        if( !in[i] ) { root = i; break; }

    dfs(root);

    int rez = 0;
    for(int i=1; i<=K; i++) {
        rez += dp[root][i];
        rez %= MOD;
    }

    printf("%d", rez);
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

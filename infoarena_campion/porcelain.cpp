//CodeForces Round #105 Div 2 : Problem E (Porcelain)
#include<stdio.h>
#include<string.h>
#define inf "porcelain.in"
#define outf "porcelain.out"
using namespace std;

int n, m;
int w[101], A[101][101], sum[101][101];
int best[101][101], dp[101][10001];

void read()
{
    scanf("%d%d", &n, &m);
    for(int i=1; i<=n; i++) {
        scanf("%d", &w[i]);
        for(int j=1; j<=w[i]; j++) {
            scanf("%d", &A[i][j]);
            sum[i][j] = A[i][j] + sum[i][j-1];
        }
    }
}

inline int max(int a, int b) { return a>b ? a : b; }

void solve()
{
    for(int i=1; i<=n; i++)
        for(int j=1; j<=w[i]; j++)
            for(int k=0; k<=j; k++) best[i][j] = max( best[i][j], sum[i][k] + sum[i][w[i]] - sum[i][w[i]-(j-k)] );

    memset( dp, -1, sizeof(dp) );

    for(int j=1; j<=w[1]; j++) dp[1][j] = best[1][j];
    for(int i=1; i<=n; i++) dp[i][0] = 0;

    for(int i=2; i<=n; i++)
        for(int j=1; j<=m; j++) {
            dp[i][j] = dp[i-1][j];
            for(int k=1; k<=w[i] && k<=j; k++)
                if( dp[i-1][j-k]!=-1 ) dp[i][j] = max( dp[i][j], dp[i-1][j-k] + best[i][k] );
        }

    printf("%d", dp[n][m]);
}

int main()
{
	//freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

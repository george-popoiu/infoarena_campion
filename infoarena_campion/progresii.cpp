#include<stdio.h>
#define inf "progresii.in"
#define outf "progresii.out"
#define NMax 50010
#define XMax 50010
#define INF 0x3f3f3f3f
#define MOD 2011
using namespace std;

int N, X, best[XMax];
int dp[XMax];
int r[NMax], st[NMax];

inline int max(int a, int b) { return a>b ? a : b; }

void read()
{
    scanf("%d%d", &N, &X);

    for(int i=1; i<=X; i++) best[i] = -INF;

    for(int i=1; i<=N; i++) {
        scanf("%d%d", &st[i], &r[i]);
        if( !st[i] ) {
            dp[ r[i] ]++;
            best[ r[i] ] = max( 2, best[ r[i] ] );
        }
    }
}

void solve()
{
    for(int i=1; i<=X; i++)
        for(int j=1; j<=N; j++)
            if( i-r[j]>=0 && i-r[j]>=st[j] ) {
                dp[i] += dp[i-r[j]];
                if( dp[i]>=MOD ) dp[i] -= MOD;
                best[i] = max( best[i], 1+best[i-r[j]] );
            }

    printf("%d %d", dp[X], best[X]);
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

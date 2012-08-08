#include<stdio.h>
#define inf "perm.in"
#define outf "perm.out"
#define NMax 3002
#define MOD 666013
using namespace std;

int N, K;
int dp[2][NMax], n = 1, o = 0;

inline int swap(int &a, int &b) { int aux = a; a = b; b = aux; }

void read()
{
    scanf("%d%d", &N, &K);
}

void solve()
{
    dp[o][0] = 1;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=K; j++) dp[n][j] = ( dp[o][j-1] + (dp[o][j]*(i-j-1))%MOD + (dp[o][j+1]*(j+1))%MOD )%MOD;
        swap(n, o);
    }

    printf("%d", dp[o][K]);
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

#include<stdio.h>
#include<algorithm>
#include<vector>
#define inf "cazare.in"
#define outf "cazare.out"
#define DMax 1001
#define KMax 101
using namespace std;

int B, F, K;
int b[KMax], f[KMax];
int dp[DMax][DMax];
int sol[KMax], s;

void read()
{
    scanf("%d%d%d", &B, &F, &K);

    int i;
    for(i=1; i<=K; ++i) scanf("%d%d", &b[i], &f[i]);
}

void solve()
{
    int t, i, j, k1, k2;

    dp[0][0] = 1;
    for(t=1; t<=K; ++t)
        for(i=B; i>=0; --i)
            for(j=F; j>=0; --j)
                if( dp[i][j] && i+b[t]<=B && j+f[t]<=F && !dp[i+b[t]][j+f[t]] ) dp[i+b[t]][j+f[t]] = t;

    vector<int> v;
    i=B; j=F;
    while( i>0 || j>0 ) {
        sol[++s] = dp[i][j];
        k1 = b[dp[i][j]]; k2 = f[dp[i][j]];
        i -= k1; j-=k2;
    }

    printf("%d\n", s);
    for(i=1; i<=s; ++i) printf("%d\n", sol[i]);
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

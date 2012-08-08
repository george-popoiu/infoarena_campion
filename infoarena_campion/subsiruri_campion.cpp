#include<stdio.h>
#include<vector>
#define inf "subsiruri.in"
#define outf "subsiruri.out"
#define NMax 1001
#define MMax 1001
#define MOD 666013
using namespace std;

int N, M, A, B;
int v[NMax], dp[NMax][MMax];
vector<int> L[NMax];

void read()
{
    scanf("%d%d%d%d", &N, &M, &A, &B);
    for(int i=1; i<=N; i++) {
        scanf("%d", &v[i]);
        dp[i][ v[i]%M ] = 1;
        L[i].push_back( v[i]%M );
    }
}

void solve() // O(N^2 * M)
{
    for(int i=1; i<=N; i++)
        for(int j=1; j<i; j++)
            if( v[j]<=v[i] ) {
                /*for(int r=0, nr; r<M; r++) {
                    nr = (r+v[i])%M;
                    dp[i][nr] += dp[j][r];
                    if( dp[i][nr]>=MOD ) dp[i][nr] -= MOD;
                }*/
                for(int t=0, r, nr; t<L[j].size(); t++) {
                    r = L[j][t];
                    nr = (r+v[i])%M;
                    dp[i][nr] += dp[j][r];
                    L[i].push_back(nr);
                    if( dp[i][nr]>=MOD ) dp[i][nr] -= MOD;
                }
            }

    int ans = 0;
    for(int i=1; i<=N; i++)
        for(int r=A; r<=B; r++) {
            ans += dp[i][r];
            if( ans>=MOD ) ans -= MOD;
        }

    printf("%d", ans);
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

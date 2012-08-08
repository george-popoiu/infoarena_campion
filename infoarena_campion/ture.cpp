#include<stdio.h>
#include<algorithm>
#define inf "ture.in"
#define outf "ture.out"
#define Dim 251
#define ll long long
using namespace std;

int N, M, K, P;
int p[Dim][Dim];
ll dp[2][1<<16];

inline int min(int a, int b) { return ( a<b ? a : b ); }

void read()
{
    scanf("%d%d%d%d", &N, &M, &K, &P);

    int x, y;
    for(int i=1; i<=P; i++) {
        scanf("%d%d", &x, &y);
        N >= M ? p[x-1][y-1] = 1 : p[y-1][x-1] = 1;
    }
}

inline int nr1(int x) {
    int rez = 0;
    for(int i=0; i<32; i++)
        if( x & (1<<i) ) rez++;
    return rez;
}

void solve()
{
    if( N<M ) swap(N,M);

    dp[0][0] = 1;
    for(int i=0; i<N; i++) {
        copy( dp[0], dp[0]+(1<<M), dp[1]);
        for(int j=0; j < 1<<M; j++)
            for(int k=0; k<M; k++) {
                if( p[i][k] || (1<<k) & j ) continue;
                dp[0][j | 1<<k] += dp[1][j];
            }
    }

    ll sol = 0;
    for(int j=0; j < 1<<M; j++)
        if( nr1(j)==K ) sol += dp[0][j];

    printf("%lld", sol);
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

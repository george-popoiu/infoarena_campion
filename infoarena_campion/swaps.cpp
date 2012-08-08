#include<stdio.h>
#include<string.h>
#define inf "swaps.in"
#define outf "swaps.out"
using namespace std;

int T, N, P, A, B;
double p1, p2, dp[101][101];

double f(int i, int j) {
    double & r = dp[i][j];
    if( i==0 ) {
        if( j==A ) r = 1;
        else r = 0;
    }
    else if( r==0 ) {
        r += p2*f(i-1,j);
        for(int t=1; t<=N; t++) r += p1*f(i-1,t);
    }
    return r;
}

void solve()
{
    scanf("%d", &T);
    for(int i=1; i<=T; i++) {
        scanf("%d%d%d%d", &N, &P, &A, &B);

        memset( dp, 0, sizeof(dp) );

        p1 = (double)(2*1.0) / (double)(N*N*1.0);
        p2 = (double)((N-2)*1.0) / (double)(N*1.0);

        printf("%.9lf\n", f(P, B) );
    }
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	solve();
	return 0;
}

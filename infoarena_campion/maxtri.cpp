#include<stdio.h>
#define inf "maxtri.in"
#define outf "maxtri.out"
#define NMax 502
using namespace std;

int N, A[NMax][NMax];
int dp[NMax][NMax][3]; //dp[i][j][r] = costul maxim de a ajunge la (i,j) cu costul maxim si restul r

void read()
{
    scanf("%d", &N);
    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++) scanf("%d", &A[i][j]);
}

inline int max(int a, int b) { return a>b ? a : b; }

void solve()
{
    int k;
    dp[1][1][ A[1][1]%3 ] = A[1][1];

    //prima linie
    for(int i=2; i<=N; i++) {
        int j = max( dp[1][i-1][0], max( dp[1][i-1][1], dp[1][i-1][2] ) );
        dp[1][i][ (j+A[1][i])%3 ] = j+A[1][i];
    }

    //prima coloana
    for(int i=2; i<=N; i++) {
        int j = max( dp[i-1][1][0], max( dp[i-1][1][1], dp[i-1][1][2] ) );
        dp[i][1][ (j+A[i][1])%3 ] = j+A[i][1];
    }

    //restul matricei
    for(int i=2; i<=N; i++)
        for(int j=2; j<=N; j++) {
            if( dp[i-1][j][0]>0 ) {
                k = dp[i-1][j][0] + A[i][j];
                dp[i][j][k%3] = max( k, dp[i][j][k%3] );
            }
            if( dp[i-1][j][1]>0 ) {
                k = dp[i-1][j][1] + A[i][j];
                dp[i][j][k%3] = max( k, dp[i][j][k%3] );
            }
            if( dp[i-1][j][2]>0 ) {
                k = dp[i-1][j][2] + A[i][j];
                dp[i][j][k%3] = max( k, dp[i][j][k%3] );
            }
            if( dp[i-1][j-1][0]>0 ) {
                k = dp[i-1][j-1][0] + A[i][j];
                dp[i][j][k%3] = max( k, dp[i][j][k%3] );
            }
            if( dp[i-1][j-1][1]>0 ) {
                k = dp[i-1][j-1][1] + A[i][j];
                dp[i][j][k%3] = max( k, dp[i][j][k%3] );
            }
            if( dp[i-1][j-1][2]>0 ) {
                k = dp[i-1][j-1][2] + A[i][j];
                dp[i][j][k%3] = max( k, dp[i][j][k%3] );
            }
            if( dp[i][j-1][0]>0 ) {
                k = dp[i][j-1][0] + A[i][j];
                dp[i][j][k%3] = max( k, dp[i][j][k%3] );
            }
            if( dp[i][j-1][1]>0 ) {
                k = dp[i][j-1][1] + A[i][j];
                dp[i][j][k%3] = max( k, dp[i][j][k%3] );
            }
            if( dp[i][j-1][2]>0 ) {
                k = dp[i][j-1][2] + A[i][j];
                dp[i][j][k%3] = max( k, dp[i][j][k%3] );
            }
        }

    printf("%d", dp[N][N][0]);
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

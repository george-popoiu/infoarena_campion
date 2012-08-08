#include<stdio.h>
#define inf "homm.in"
#define outf "homm.out"
#define NMax 102
#define KMax 21
using namespace std;

int N, M, K, x1, y1, x2, y2;
int A[NMax][NMax], dp[KMax][NMax][NMax];

void read()
{
    scanf("%d%d%d", &N, &M, &K);
    for(int i=1; i<=N; i++)
        for(int j=1; j<=M; j++) scanf("%d", &A[i][j]);
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
}

void solve()
{
    dp[0][x1][y1] = 1;
    for(int p=1; p<=K; p++)
        for(int i=1; i<=N; i++)
            for(int j=1; j<=M; j++)
                if( !A[i][j] ) dp[p][i][j] = dp[p-1][i-1][j] + dp[p-1][i][j+1] + dp[p-1][i+1][j] + dp[p-1][i][j-1];

    int rez = 0;
    for(int k=1; k<=K; k++) rez += dp[k][x2][y2];
    if( x1==x2 && y1==y2 ) rez += dp[0][x2][y2];

    printf("%d", rez);
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

#include<stdio.h>
#include<bitset>
#include<string.h>
#define inf "triunghi.in"
#define outf "triunghi.out"
#define NMax 19
#define SMax 1000001
using namespace std;

int N, S, V[NMax], tr[NMax][NMax];
bitset<SMax> dp[2], back[NMax];
int n = 1, o = 0;

void read()
{
    scanf("%d%d", &N, &S);
}

int simulate(int c) {
    int s = 1;
    //memset(tr, 0, sizeof(tr));
    tr[N][c] = 1;
    for(int i=N-1; i>=1; i--)
        for(int j=1; j<=i; j++) {
            s -= tr[i][j];
            tr[i][j] = tr[i+1][j] + tr[i+1][j+1];
            s += tr[i][j];
        }
    return s;
}

void solve()
{
    for(int i=1; i<=N; i++) V[i] = simulate(i);

    dp[o][0] = 1;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=S; j++)
            if( j>=V[i] ) {
                dp[n][j] = dp[n][j-V[i]];
                if( dp[o][j-V[i]] ) { dp[n][j] = 1; back[i][j] = 1; }
            }
        swap(n, o);
    }

    if( dp[o][S]==0 ) {
        printf("imposibil");
        return;
    }

    memset(tr, 0, sizeof(tr));

    int i = N, j = S;
    while( i>0 && j>0 ) {
        tr[N][i]++;
        if( back[i][j] ) j-=V[i], i--;
        else j-=V[i];
    }

    for(i=N-1; i>=1; i--)
        for(j=1; j<=i; j++) tr[i][j] = tr[i+1][j] + tr[i+1][j+1];

    for(i=1; i<=N; i++) {
        for(j=1; j<=i; j++) printf("%d ", tr[i][j]);
        printf("\n");
    }
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

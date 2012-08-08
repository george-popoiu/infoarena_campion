#include<stdio.h>
#include<vector>
#define inf "farfurii.in"
#define outf "farfurii.out"
#define NMax 1001
#define TMax 10001
using namespace std;

int N, T;
int ts[NMax], best[2][TMax], n = 1, o = 0;
int sol, tmin;

void read()
{
    scanf("%d%d", &N, &T);
    for(int i=1; i<=N; i++) scanf("%d", &ts[i]);
}

void solve()
{
    for(int i=1; i<=N; i++) {
        for(int j=i; j<=T; j++) {
            best[n][j] = best[o][j-1];
            if( j>=ts[i] && best[n][j] < 1+best[o][j-ts[i]] ) best[n][j] = 1+best[o][j-ts[i]];
            if( best[n][j]>sol ) { sol = best[n][j]; tmin = j; }
            else if( best[n][j]==sol && j<tmin ) tmin = j;
        }
        swap(n, o);
    }

    printf("%d %d", sol, tmin);
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

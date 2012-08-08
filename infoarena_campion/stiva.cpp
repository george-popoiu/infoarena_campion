#include<stdio.h>
#include<string.h>
#define inf "stiva.in"
#define outf "stiva.out"
#define NMax 510
#define INF 0x3f3f3f3f
using namespace std;

int N;
char S[NMax];
int best[NMax][NMax];

void read()
{
    scanf("%s", S+1);
    N = strlen(S+1);
}

inline int min(int a, int b) { return ( a<b ? a : b ); }

void solve()
{
    for(int i=1; i<=N; i++) best[i][i] = 1;

    for(int k=2; k<=N; k++)
        for(int i=1; i<=N-k+1; i++)
        {
            int j = i+k-1;
            best[i][j] = best[i][j-1] + 1;
            for(int t=i; t<j; t++)
                if( S[t]==S[j] ) best[i][j] = min( best[i][j], best[i][t] + best[t+1][j-1] );
        }

    printf("%d", N + 2*best[1][N]);
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

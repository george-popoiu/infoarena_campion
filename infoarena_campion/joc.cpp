#include<stdio.h>
#define inf "joc.in"
#define outf "joc.out"
#define NMax 1001
#define INF 0x3f3f3f3f
using namespace std;

int N, M, best[NMax][NMax], A[NMax][NMax];
int rez, lin, col;

void read()
{
    scanf("%d%d", &N, &M);
    for(int i=1; i<=N; i++)
        for(int j=1; j<=M; j++) scanf("%d", &A[i][j]);
}

inline int max(int a, int b) { return ( a>b ? a : b ); }

void solve()
{
    for(int i=0; i<=N; i++)
        for(int j=0; j<=N; j++) best[i][j] = -INF;

    best[1][1] = A[1][1];
    rez = best[1][1]; lin = col = 1;
    for(int i=1; i<=N; i++)
        for(int j=1; j<=M; j++) {
            if( i==1 && j==1 ) continue;
            best[i][j] = max( best[i-1][j], best[i][j-1] );
            if( best[i][j] < A[i][j] - max( best[i-1][j], best[i][j-1] ) ) {
                best[i][j] = A[i][j] - max( best[i-1][j], best[i][j-1] );
                if( best[i][j]>rez ) rez = best[i][j], lin = i, col = j;
            }
        }

    printf("%d %d %d", rez, lin, col);
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

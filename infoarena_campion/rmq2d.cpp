#include<stdio.h>
#define inf "rmq2d.in"
#define outf "rmq2d.out"
using namespace std;

int N, M, Q, lg[100];
int rmq[100][100][15][15];

inline int min(int a, int b) { return ( a<b ? a : b ); }

inline int max(int a, int b) { return ( a>b ? a : b ); }

void read()
{
    scanf("%d%d%d", &N, &M, &Q);
    for(int i=1; i<=N; i++)
        for(int j=1; j<=M; j++)
            scanf("%d", &rmq[i][j][0][0]);
}

inline int Query(int i, int j, int k, int l) {
    int dk = lg[k], dl = lg[l];
    return min( rmq[i][j][dk][dl], min( rmq[i+k-(1<<dk)][j+l-(1<<dl)][dk][dl],
                min( rmq[i+k-(1<<dk)][j][dk][dl], rmq[i][j+l-(1<<dl)][dk][dl] ) ) );
}

void solve()
{
    lg[1] = 0;
    for(int i=2; i<=max(N,M); i++) lg[i] = lg[i/2]+1;

    for(int k=1; 1<<k <= N; k++)
        for(int l=1; 1<<l <= M; l++)
            for(int i=1; i+(1<<k)-1<=N; i++)
                for(int j=1; j+(1<<l)-1<=M; j++) rmq[i][j][k][l] = min( rmq[i][j][k-1][l-1], min( rmq[i][j+1<<(l-1)][k-1][l-1],
                                                    min( rmq[i+1<<(k-1)][j][k-1][l-1], rmq[i+1<<(k-1)][j+1<<(l-1)][k-1][l-1] ) ) );

    int i, j, k, l;
    for(int i=1; i<=Q; i++) {
        scanf("%d%d%d%d", &i, &j, &k, &l);
        printf("%d\n", Query(i,j,k,l));
    }
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

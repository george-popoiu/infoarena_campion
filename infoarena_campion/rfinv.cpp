#include<stdio.h>
#define inf "rfinv.in"
#define outf "rfinv.out"
#define NMax 51
#define INF 0x3f3f3f3f
using namespace std;

int T, N, M;
int A[NMax][NMax], R[NMax][NMax], I[NMax][NMax];

void init() {
    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++) {
            A[i][j] = 0;
            R[i][j] = I[i][j] = INF;
        }

    for(int i=1; i<=N; i++) R[i][i] = I[i][i] = 0;
}

inline int min(int a, int b) { return a<b ? a : b ; }

void roy() {
    for(int k=1; k<=N; k++)
        for(int i=1; i<=N; i++)
            for(int j=1; j<=N; j++) R[i][j] = min( R[i][j], R[i][k] + R[k][j] );
}

void solve()
{
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d%d", &N, &M);
        init();

        int a, b;
        for(int i=1; i<=M; i++) {
            scanf("%d%d", &a, &b);
            A[a][b] = A[b][a] = 1;
        }

        for(int i=1; i<=N; i++)
            for(int j=1; j<=N; j++) {
                scanf("%d", &I[i][j]);
                if(A[i][j]) R[i][j] = I[i][j];
            }

        roy();

        int g = 1;
        for(int i=1; i<=N && g; i++)
            for(int j=1; j<=N; j++)
                if( R[i][j] != I[i][j] ) { g = 0; break; }

        g ? printf("DA\n") : printf("NU\n");
    }
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	solve();
	return 0;
}

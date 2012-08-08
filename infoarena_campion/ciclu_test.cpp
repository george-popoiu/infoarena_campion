#include<stdio.h>
#define inf "ciclu_test.in"
#define outf "ciclu_test.out"
#define NMax 100
using namespace std;

int N, M;
int A[NMax][NMax], T[NMax], viz[NMax];

void read()
{
    scanf("%d%d", &N, &M);

    int a, b;
    for(int i=1; i<=M; i++) {
        scanf("%d%d", &a, &b);
        A[a][b] = A[b][a] = 1;
    }
}

void ciclu(int u, int st) {
    int v = u;
    do {
        printf("%d ", u);
        u = T[u];
    } while( u!=st );
    printf("%d\n", st);
}

void dfs(int u) {
    viz[u] = 1;
    for(int i=1; i<=N; i++) {
        if( A[u][i] ) {
            A[i][u] = 0;
            if( !viz[i] ) {
                T[i] = u;
                dfs(i);
            }
            else ciclu(u, i);
        }
    }
}

void solve()
{
    dfs(1);
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

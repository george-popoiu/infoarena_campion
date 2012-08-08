#include<stdio.h>
#define inf "sccm.in"
#define outf "sccm.out"
#define DMax 80001
using namespace std;

int N, M, D;
int A[DMax], B[DMax], ap1[DMax], ap2[DMax], best[DMax];

inline int min(int a, int b) { return a<b ? a : b; }

inline int max(int a, int b) { return a>b ? a : b; }

void read()
{
    scanf("%d%d", &N, &M);
    for(int i=1; i<=N; i++) {
        scanf("%d", &A[i]);
        ap1[ A[i] ] = i;
    }
    for(int i=1; i<=M; i++) {
        scanf("%d", &B[i]);
        ap2[ B[i] ] = i;
    }

    D = min(N, M);
}

void solve()
{
    for(int i=1; i<=D; i++) {
        best[i] = 1;
        for(int j=1; j<i; j++)
            if( ap1[j]<ap1[i] && ap2[j]<ap2[i] ) best[i] = max( best[i], 1 + best[j] );
    }

    int sol = 0;
    for(int i=1; i<=D; i++) sol = max( sol, best[i] );

    printf("%d", sol);
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

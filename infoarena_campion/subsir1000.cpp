#include<stdio.h>
#define inf "subsir1000.in"
#define outf "subsir1000.out"
#define NMax 100001
using namespace std;

int N, A[NMax], best[NMax];

void read()
{
    scanf("%d", &N);
    for(int i=1; i<=N; i++) scanf("%d", &A[i]);
}

inline int max(int a, int b) { return ( a>b ? a : b ); }

void solve()
{

    for(int i=1; i<=N; i++) {
        int val = 0, g = 0;
        int aux = A[i];

        for(int j=2; j*j<=aux; j++)
            if( A[i]%j==0 ) {
                val = max( val, best[j] );
                for( ; aux%j==0; aux /= j );
            }
        if( aux>1 ) val = max( val, best[aux] );

        for(int j=2; j*j<=A[i]; j++)
            if( A[i]%j==0 ) {
                best[j] = max( best[j], val+1 );
                for( ; A[i]%j==0; A[i]/=j );
            }

        if( A[i]>1 ) best[ A[i] ] = max( best[ A[i] ], 1+val );
    }

    int sol = 0;
    for(int i=2; i<=N; i++)
        if( best[i]>sol ) sol = best[i];

    printf("%d", sol);
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

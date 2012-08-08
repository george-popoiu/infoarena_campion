#include<stdio.h>
#define inf "panouri.in"
#define outf "panouri.out"
#define NMax 200001
#define TMax 20001
using namespace std;

int N, T, A[NMax], B[NMax], uz[TMax], fr[TMax];
int start, stop, nr;

void read()
{
    scanf("%d%d", &N, &T);
    for(int i=1; i<=N; i++) scanf("%d", &A[i]);
    for(int i=1; i<=T; i++) {
        scanf("%d", &B[i]);
        uz[ B[i] ] = 1;
    }
}

void solve()
{
    start = stop = 1;
    while( nr<T && stop<=N ) {
        if( uz[ A[stop] ] ) {
             if( !fr[ A[stop] ] ) nr++;
             fr[ A[stop] ]++;
        }
        stop++;
    }
    stop--;

    while(1) {
        if( uz[ A[start] ] ) {
            if( fr[ A[start] ]==1 ) break;
            else { fr[ A[start] ]--; start++; }
        }
        else start++;
    }

    if( nr<T ) {
        printf("-1");
        return;
    }

    int sol = stop-start;

    for(int i = stop+1; i<=N; i++) {
        if( uz[ A[i] ] ) fr[ A[i] ]++;
        while( 1 ) {
            if( uz[ A[start] ] ) {
                if( fr[ A[start] ]==1 ) break;
                else { fr[ A[start] ]--; start++; }
            }
            else start++;
        }
        if( i-start<sol ) sol = i-start;
    }

    printf("%d", sol);
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

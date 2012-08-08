#include<stdio.h>
#define inf "reguli.in"
#define outf "reguli.out"
#define NMax 500001
#define ll long long
using namespace std;

ll N, A[NMax], D[NMax], P[NMax];

void read()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++) scanf("%lld", &A[i]);
}

void prefix() {
    int k = 0; P[1] = 0;
    for(int i=2; i<N; i++) {
        while( k>0 && D[k+1]!=D[i] ) k = P[k];
        if( D[k+1]==D[i] ) k++;
        P[i] = k;
    }
}

void solve()
{
    for(int i=1; i<N; i++) D[i] = A[i] - A[i-1];
    prefix();

    printf("%lld\n", N-1-P[N-1]);
    for(int i=1; i<=N-1-P[N-1]; i++) printf("%lld\n", D[i]);
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

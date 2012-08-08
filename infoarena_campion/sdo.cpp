#include<stdio.h>
#include<algorithm>
#include<time.h>
#define inf "sdo.in"
#define outf "sdo.out"
#define NMax 3000001
using namespace std;

int N, K, A[NMax];

void read()
{
    scanf("%d%d", &N, &K);
    for(int i=1; i<=N; i++) scanf("%d", &A[i]);
}

int part(int li, int ls) {
    int i = li-1, j = ls+1, p = A[li+rand()%(ls-li+1)];

    while(1) {
        do { i++; } while( A[i]<p );
        do { j--; } while( A[j]>p );
        if( i<j ) swap(A[i], A[j]);
        else return j;
    }

    return 0;
}

void qs(int li, int ls, int k) {
    if( li==ls ) return;

    int q = part(li, ls);
    int t = q-li+1;

    if( t>=k ) qs(li, q, k);
    else qs(q+1, ls, k-t);
}

void solve()
{
    srand(time(NULL));
    qs(1, N, K);
    printf("%d", A[K]);
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

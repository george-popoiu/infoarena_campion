#include<stdio.h>
#include<vector>
#define NMax 20001
#define inf "perm2.in"
#define outf "perm2.out"
using namespace std;

int N, P[NMax], A[NMax], uz[NMax], K;

void read()
{
    scanf("%d", &N);
    for(int i=1; i<=N; i++) scanf("%d", &P[i]);
}

void solve()
{
    for(int i=1; i<=N; i++) {
        if( uz[P[i]] ) continue;
        int v = P[i];

        int k = 0;
        while( v!=1 ) { k++; uz[v] = 1; v=P[v]; uz[v] = 1; }

        A[i] = k;

        v = P[i];
        while( v!=1 ) { k++; v=P[v]; A[v] = k; }
    }

    for(int i=1; i<=N; i++) printf("%d ", A[i]);
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

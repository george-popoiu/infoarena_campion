#include<stdio.h>
#include<string.h>
#define inf "diamant.in"
#define outf "diamant.out"
#define MOD 10000
#define Max 44101
using namespace std;

int N, M, X;
int a[Max], b[Max];

void read()
{
    scanf("%d%d%d", &N, &M, &X);
}

inline int mod(int n) { return ( n<0 ? -n : n ); }

void solve()
{
    int XLimit = ( N*(N+1)*M*(M+1) ) / 4;
    if( mod(X) > XLimit ) { printf("0"); return; }
    a[0] = 1;
    for(int i=1; i<=N; i++)
        for(int j=1; j<=M; j++)
        {
            int ij = i*j;
            for(int s=0; s<=XLimit; s++) b[s] = ( a[s+ij] + a[s] + a[ mod(s-ij) ] ) % MOD;
            memcpy( a, b, sizeof(b) );
        }
    printf("%d", a[ mod(X) ] );
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

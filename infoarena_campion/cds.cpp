#include<stdio.h>
#define inf "cds.in"
#define outf "cds.out"
#define NMax 110
#define DIM 700
#define INF 0x3f3f3f3f
using namespace std;

int N, total_dim;
int A[NMax], C[NMax];

void read()
{
    scanf("%d", &N);
    for(int i=1; i<=N; i++)
    {
        scanf("%d", &A[i]);
        total_dim += A[i];
    }
}

void solve()
{
    for(int i=1; i<=N; i++)
    {
        C[i] = A[i];
        for(int j=1; j<i; j++)
            if( C[j] + A[i] <= DIM && C[j] + A[i] > C[i] ) C[i] = C[j] + A[i];
    }
    int max = -INF;
    for(int i=1; i<=N; i++)
        if( C[i]>max && total_dim - C[i] <= DIM ) max = C[i];
    if( max == -INF ) printf("0 0");
    else printf("%d %d", total_dim-max, max);
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

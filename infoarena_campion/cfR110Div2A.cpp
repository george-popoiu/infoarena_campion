#include<stdio.h>
//#define inf "test.in"
//#define outf "test.out"
#define NMax 31
using namespace std;

int N, A[NMax][NMax];
int R[NMax], C[NMax];

void read()
{
    scanf("%d", &N);
    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++) {
            scanf("%d", &A[i][j]);
            R[i] += A[i][j];
            C[j] += A[i][j];
        }
}

void solve()
{
    int ans = 0;
    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++)
            if( C[j]>R[i] ) ans++;

    printf("%d", ans);
}

int main()
{
	//freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

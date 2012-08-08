#include<stdio.h>
#include<algorithm>
#define NMax 5000
using namespace std;

int best[NMax][NMax], back[NMax][NMax];
int N, A[NMax];
int sols[NMax][3], nrs;

void read()
{
    scanf("%d", &N);
    for(int i=1; i<=N; i++) scanf("%d", &A[i]);
}

void getsols(int i, int j) {
    if( j-i+1<3 ) return;
    if( !back[i][j] ) getsols(i+1, j-1);
    else {
        int k = back[i][j];
        sols[++nrs][0] = A[i]; sols[nrs][1] = A[k]; sols[nrs][2] = A[j];
        getsols(i+1, k-1);
        getsols(k+1, j-1);
    }
}

void solve()
{
    sort( A+1, A+N+1 );

    for(int l=3; l<=N; l++)
        for(int i=1; i<=N-l+1; i++) {
            int j = i+l-1;
            best[i][j] = best[i+1][j-1];
            for(int k=i+1; k<j; k++)
                if( A[i]<A[k] && A[k]<A[j] && best[i][j] < 1+best[i+1][k-1] + best[k+1][j-1] ) {
                    best[i][j] = 1 + best[i+1][k-1] + best[k+1][j];
                    back[i][j] = k;
                }
        }

    printf("%d\n", best[1][N]);

    getsols(1, N);

    for(int i=1; i<=nrs; i++) {
        for(int j=2; j>=0; j--) printf("%d ", sols[i][j]);
        printf("\n");
    }
}

int main()
{
    read(); solve();
	return 0;
}

#include<stdio.h>
#define inf "morcovi.in"
#define outf "morcovi.out"
#define PMax 12
#define NMax 1000
using namespace std;

int best[1<<PMax][NMax];
int N, P, A[NMax], Pas[PMax];

void read()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++) scanf("%d", &A[i]);

    scanf("%d", &P);
    for(int i=0; i<P; i++) scanf("%d", &Pas[i]);
}

void solve()
{
    for(int i=0; i<N; i++) best[0][i] = A[i];

    for(int i=1; i < (1<<P); i++)
        for(int j=0; j<N; j++)
            for(int k=0; k<32; k++)
                if( i & (1<<k) ) { //al k-lea bit e de 1
                    if( j-Pas[k] >= 0 && best[i][j] < A[j] + best[i-(1<<k)][j-Pas[k]] ) best[i][j] = A[j] + best[i-(1<<k)][j-Pas[k]];
                    if( j+Pas[k] < N && best[i][j] < A[j] + best[i-(1<<k)][j+Pas[k]] ) best[i][j] = A[j] + best[i-(1<<k)][j+Pas[k]];
                }

    int sol = 0;
    for(int i=0; i<N; i++)
        if( best[(1<<P)-1][i] > sol ) sol = best[(1<<P)-1][i];
    printf("%d", sol);
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

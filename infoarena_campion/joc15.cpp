#include<stdio.h>
#define inf "joc15.in"
#define outf "joc15.out"
#define NMax 5001
#define KMax 11
using namespace std;

int N, K;
int best[NMax][KMax][2], s[NMax][2];

void read()
{
    scanf("%d%d", &N, &K);
    for(int l=0; l<2; l++)
        for(int i=1; i<=N; i++) {
            scanf("%d", &s[i][l]);
            s[i][l] += s[i-1][l];
        }
}

void solve()
{
    for(int k=1; k<=K; k++)
        for(int i=1; i<=N; i++)
            for(int l=0; l<2; l++) {
                best[i][k][l] = s[i][l] - s[i-1][l] + best[i][K][l^1];
                for(int t=1; t<k; t++)
                    if( best[i][k][l] < best[i-t][k-t][l] + best[i-t][k-t][l] + s[i][l] - s[i-t][l] )
                        best[i][k][l] < best[i-t][k-t][l] + best[i-t][k-t][l] + s[i][l] - s[i-t-1][l];
            }
    printf("%d", best[N][K][1]);
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

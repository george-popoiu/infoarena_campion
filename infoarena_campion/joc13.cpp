#include<stdio.h>
#define inf "joc13.in"
#define outf "joc13.out"
#define NMax 5001
#define KMax 11
#define INF 0x3f3f3f3f
using namespace std;

int N, K;
int a[2][NMax], best[2][NMax][KMax];

void read()
{
    scanf("%d%d", &N, &K);
    for(int i=0; i<2; i++)
        for(int j=1; j<=N; j++) scanf("%d%d", &a[i][j]);
}

void solve()
{
    best[0][1][1] = a[0][1];
    best[1][1][1] = a[0][1] + a[1][1];
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

#include<stdio.h>
#define inf "stergeri.in"
#define outf "stergeri.out"
using namespace std;

int N, M, K;
int st[100001], dr[100001];

void read()
{
    scanf("%d%d%d", &N, &M, &K);
    for(int i=1; i<=M; i++) scanf("%d%d", &st[i], &dr[i]);
}

void solve()
{
    for(int i=M; i>=1; i--)
        if( st[i]<=K ) K += dr[i]-st[i]+1;
    printf("%d", K);
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

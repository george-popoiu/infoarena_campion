#include<stdio.h>
#define inf "z.in"
#define outf "z.out"
using namespace std;

int N, K;
int x, y;

int z(int x1, int y1, int x2, int y2) {
}

void solve()
{
    scanf("%d%d", &N, &K);

    for(int i=1; i<=K; i++) {
        scanf("%d%d", &x, &y);
        z(1, 1, 1<<N, 1<<N);
    }
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	solve();
	return 0;
}

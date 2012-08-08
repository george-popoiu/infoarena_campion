#include<stdio.h>
#include<bitset>
#define inf "distincte2.in"
#define outf "distincte2.out"
#define Max 1001000
using namespace std;

int N, M, aib[Max], m, A[100100];
bitset<Max> h;

inline int bit(int i) { return ( i & -i ); }

void update(int x) {
    for(int i=x; i<=1000000; i+=bit(i)) aib[i] += 1;
}

int query(int x) {
    int ans = 0;
    for(int i=x; i>=1; i-=bit(i)) {
        ans += aib[i];
    }
    return ans;
}

inline int max(int a, int b) { return a>b ? a : b; }

void solve()
{
    scanf("%d%d", &N, &M);

    int a;
    for(int i=1; i<=N; i++) {
        scanf("%d", &a);
        if( !h[a] ) {
            h[a] = 1;
            update(a);
        }
    }

    int x, y;
    for(int i=1; i<=M; i++) {
        scanf("%d%d", &x, &y);
        printf("%d", query(y)-query(x-1));
        if( i!=M ) printf("\n");
    }
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	solve();
	return 0;
}

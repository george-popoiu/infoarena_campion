#include<stdio.h>
#define inf "strung.in"
#define outf "strung.out"
#define nmax 1010
#define mmax 110
#define INF 0x3f3f3f3f
using namespace std;

int m, n;
int d[nmax], s[mmax];

void read()
{
    scanf("%d%d", &m, &n);
    for(int i=1; i<=n; i++) scanf("%d", &d[i]);
}

inline int min(int a, int b) { return a<b ? a : b; }

inline int max(int a, int b) { return a>b ? a : b; }

void solve()
{
    //Complexitate - O(3*n*m)

    int i = 1, ans = 0;
    while( i<=n ) {
        for(int j=1; j<=m && i<=n; j++)
            if( !s[j] ) { s[j] = d[i]; i++; }
        if( i>n ) break;

        int a = INF;
        for(int j=1; j<=m; j++)
            if( s[j] ) a = min(a, s[j]);

        ans += a;
        for(int j=1; j<=m; j++)
            if( s[j] ) s[j] -= a;
    }

    int a = -INF;
    for(int j=1; j<=m; j++) a = max(a, s[j]);

    ans += a;
    printf("%d", ans);
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

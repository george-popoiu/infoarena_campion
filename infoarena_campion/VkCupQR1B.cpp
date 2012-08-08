#include<stdio.h>
#define inf "test.in"
#define outf "test.out"
using namespace std;

int n, s[5];

void read()
{
    scanf("%d", &n);

    int a;
    for(int i=1; i<=n; i++) {
        scanf("%d", &a);
        s[a]++;
    }
}

inline int min(int a, int b) { return a<b ? a : b; }

void solve()
{
    int ans = 0;
    ans += s[4];

    while( s[3] ) {
        if( s[1] ) { ans++; s[3]--; s[1]--; }
        else { ans++; s[3]--; }
    }

    while( s[2] ) {
        if( s[2]>=2 ) { s[2]-=2; ans++; }
        else {
            if( s[1]>=2 ) { s[2]--; s[1]-=2; ans++; }
            else if( s[1] ) { s[2]--; s[1]--; ans++; }
            else { s[2]--; ans++; }
        }
    }

    while( s[1] ) {
        s[1] -= min( s[1], 4 );
        ans++;
    }

    printf("%d", ans);
}

int main()
{
	//freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

#include<stdio.h>
#include<string.h>
#define inf "test.in"
#define outf "test.out"
#define NMax 110
#define MOD 1000000007
using namespace std;

int N, t, nr1[NMax], nr2[NMax], dp[NMax];
char s[NMax];

int f(int i) {
    int & r = dp[i];
    if( r!=-1 ) return r;

    r = 0;
    if( i>=N-1 ) { r = 1; return r; }

    if( i<N-1 ) r += f(i+1);
    r += ( (nr1[i]+nr2[i])*1LL*f(i+2) ) % MOD;
    r %= MOD;

    return r;
}

void calc_nrs() {
    char a, b;
    for(int i=0; i<N-1; i++) {
        a = s[i]; b = s[i+1];
        while( a<'z' && b>'a' ) { a++; b--; nr1[i]++; }
        a = s[i]; b = s[i+1];
        while( a>'a' && b<'z' ) { a--; b++; nr2[i]++; }
    }
}

void solve()
{
    scanf("%d", &t);
    for(int k=0; k<t; k++) {
        scanf("%s", s);
        N = strlen(s);

        memset( nr1, 0, sizeof(nr1) );
        memset( nr2, 0, sizeof(nr2) );
        memset( dp, -1, sizeof(dp) );

        calc_nrs();

        printf("%d\n", f(0));
    }
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	solve();
	return 0;
}

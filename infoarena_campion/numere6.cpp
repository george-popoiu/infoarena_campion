#include<stdio.h>
#include<algorithm>
#include<string.h>
#define inf "numere6.in"
#define outf "numere6.out"
#define DMax 9001
#define MOD 9973
using namespace std;

int a, b;
int dp[2][DMax], nl = 1, ol = 0;

void read()
{
    scanf("%d%d", &a, &b);
}

bool prim(int nr) {
    for(int i=2; i<nr; i++)
        if( nr%i==0 ) return false;
    return true;
}

void solve()
{
    for(int i=11; i<=b; i++)
        if( b%i==0 && prim(i) ) {
            printf("0");
            return;
        }

    int divs[DMax], nrd = 0;
    for(int i=1; i<=b; i++)
        if( b%i==0 ) divs[++nrd] = i;

    for(int i=1; i<=9; i++)
        if( b%i==0 ) dp[0][i] = 1;

    for(int i=2; i<=a; i++) {
        for(int j=1; j<=nrd; j++) {
            dp[nl][ divs[j] ] = 0;
            for(int k=1; k<=9; k++)
                if( b%k==0 && divs[j]%k==0 ) dp[nl][ divs[j] ] += dp[ol][ divs[j]/k ], dp[nl][ divs[j] ] %= MOD;
        }
        swap( nl, ol );
    }

    printf("%d", dp[ol][b]);
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

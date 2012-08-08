#include<stdio.h>
#define inf "test.in"
#define outf "test.out"
using namespace std;

int n, x, y;
double p;

void read()
{
    scanf("%d%d%d", &n, &x, &y);
    p = y*1.0/100.0;
}

void solve()
{
    int ans = 0;
    while( (double) (x*1.0 / (n*1.0)) < p ) x++, ans++;
    printf("%d", ans);
}

int main()
{
	//freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

#include<stdio.h>
#define inf "test.in"
#define outf "test.out"
using namespace std;

int a[51], n, k;

void read()
{
    scanf("%d%d", &n, &k);
    for(int i=1; i<=n; i++) scanf("%d", &a[i]);
}

void solve()
{
    int ans = 0;
    for(int i=k; i>=1; i--)
        if( a[i]>0 ) ans++;
    for(int i=k+1; a[i]==a[k] && a[i]>0 && i<=n; i++) ans++;
    printf("%d", ans);
}

int main()
{
	//freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

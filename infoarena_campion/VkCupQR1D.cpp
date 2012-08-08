#include<stdio.h>
#define inf "test.in"
#define outf "test.out"
#define nmax 20001
using namespace std;

int a[nmax], n, ans;

void read()
{
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &a[i]);
        ans += a[i];
    }
}

inline int max(int a, int b) { return a>b ? a : b; }

void solve()
{
    for(int pas=2; pas<=n/3; pas++) {
        if( n%pas==0 && n/pas>2 ) {
            int aux;
            for(int st=0; st<pas; st++) {
                aux = 0;
                for(int i=st; i<n; i+=pas) aux += a[i];
                ans = max( aux, ans );
            }
        }
    }
    printf("%d", ans);
}

int main()
{
	//freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

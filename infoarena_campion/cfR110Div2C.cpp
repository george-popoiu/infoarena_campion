#include<stdio.h>
#include<string.h>
#define inf "test.in"
#define outf "test.out"
#define Max 2010
using namespace std;

int n, m;
char a[Max], b[Max];

void read()
{
    scanf("%s%s", a, b);
    n = strlen(a);
    m = strlen(b);
}

inline int max(int a, int b) { return a>b ? a : b; }

void solve()
{
    int matches = 0;

    for(int i=-m; i<n; i++) {
        int aux = 0;
        for(int j=0; j<m; j++)
            if( i+j>=0 && i+j<n && a[i+j]==b[j] ) aux++;
        matches = max( aux, matches );
    }

    printf("%d", m-matches);
}

int main()
{
	//freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

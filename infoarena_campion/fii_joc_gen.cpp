#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define inf ""
#define outf ""
using namespace std;

void solve()
{
    srand( time(NULL) );

    int n = 20000;
    if( n==0 ) n++;

    freopen("joc.in", "w", stdout);

    printf("%d\n", n);

    int v = rand()%101;
    if( !v ) v++;
    printf("%d %d\n", 0, v);

    for(int i=2; i<=n; i++) {
        int d, p;
        d = rand()%101;
        p = rand()%101;
        if( !d ) d++;
        if( !p ) p++;
        printf("%d %d\n", d, p);
    }
}

int main()
{
	solve();
	return 0;
}

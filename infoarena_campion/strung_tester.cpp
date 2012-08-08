#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define inf "strung.in"
#define outf "strung.out"
using namespace std;

int d[1010];

void read()
{
}

void solve()
{
    srand( time(NULL) );

    int m, n;

    //m = rand() % 101;
    m = 100;
    if( m<2 ) m = 2;

    //n = rand() % 1001;
    n = 1000;
    if( n<1 ) n = 1;

    for(int i=1; i<=n; i++) {
        d[i] = rand()%31;
        if( d[i]<1 ) d[i] = 1;
    }

    freopen("strung21.in", "w", stdout);

    printf("%d %d\n", m, n);
    for(int i=1; i<=n; i++) printf("%d\n", d[i]);
}

int main()
{
	//freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define inf ""
#define outf ""
using namespace std;

void read()
{
}

void solve()
{
    srand( time(NULL) );

    int d, b, t, p;

    b = rand() % 1073741825;
    if( b<1025 ) b = 1025;

    d = rand()%b;
    if( d<1024 ) d = 1024;

    p = rand() % 3601;
    if( !p ) p++;

    t = rand() % 14401;
    if( !t ) t++;

    freopen("video20.in", "w", stdout);
    printf("%d %d %d %d", d, b, t, p);
}

int main()
{
	read(); solve();
	return 0;
}

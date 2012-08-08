#include<stdio.h>
#include<algorithm>
#include<math.h>
//#define inf "test.in"
//#define outf "test.out"
#define NMax 102
using namespace std;

int N, r[NMax];

void read()
{
    scanf("%d", &N);
    for(int i=1; i<=N; i++) scanf("%d", &r[i]);
}

void solve()
{
    double ans = 0.0;
    sort( r+1, r+N+1 );

    for(int i=N; i>=1; i-=2) {
        ans += M_PI * ( (double)(1.0*(r[i]*r[i])) - (double)(1.0*(r[i-1]*r[i-1])) );
    }

    printf("%.15lf", ans);
}

int main()
{
	//freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

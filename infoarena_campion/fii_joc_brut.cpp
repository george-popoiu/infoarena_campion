#include<stdio.h>
#define inf "joc.in"
#define outf "joc.out"
#define NMax 20010
using namespace std;

int N, d[NMax], p[NMax];

void read()
{
    scanf("%d", &N);

    for(int i=1; i<=N; i++) scanf("%d%d", &d[i], &p[i]);
}

inline int min(int a, int b) { return a<b ? a : b; }

void solve()
{
    int ans = 0x3f3f3f3f;

    for(int l=0; l<(1<<N); l++) {
        int v = 100, c = 0;
        for(int bit=0; bit<N; bit++) {
            v += d[bit+1];
            v = min(v, 100);
            if( !(l & (1<<bit)) ) v -= p[bit+1];
            else c++;
            if( v<=0 ) break;
        }
        if( v>0 ) ans = min( ans, c );
    }

    printf("%d", ans);
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

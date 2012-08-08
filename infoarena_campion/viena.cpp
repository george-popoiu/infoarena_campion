#include<stdio.h>
#define inf "viena.in"
#define outf "viena.out"
#define NMax 1001
#define SMax 100001
#define INF 0x3f3f3f3f
using namespace std;

int N, g[NMax], best[SMax], sum;

void read()
{
    scanf("%d", &N);
    for(int i=1; i<=N; i++) scanf("%d", &g[i]), sum += g[i];
}

inline int max(int a, int b) { return ( a>b ? a : b ); }
inline int min(int a, int b) { return ( a<b ? a : b ); }

void solve()
{
    best[0] = 1;
    for(int i=1; i<=N; i++)
        for(int j = sum; j>=0; j--)
        {
            if( best[j] && j+g[i]<=sum ) best[j+g[i]] = 1;
            if( best[j] && g[i]%2==0 && j+(g[i]/2)<=sum ) best[j+(g[i]/2)] = 1;
        }
    int rez = INF;
    for(int i=sum; i>=1; i--)
        if( best[i] ) rez = min( rez, max(i,sum-i) );
    printf("%d",rez);
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

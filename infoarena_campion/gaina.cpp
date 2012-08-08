#include<stdio.h>
#define inf "gaina.in"
#define outf "gaina.out"
#define NMax 10001
using namespace std;

int N;
int h[NMax], hmax[NMax];
int cmin[NMax];

void read()
{
    scanf("%d", &N);
    for(int i=1; i<=N; i++) scanf("%d", &h[i]);
}

void solve()
{
    cmin[N] = 0; hmax[N] = N;
    int m = h[N], poz = N;
    for(int i=N-1; i>=1; i--)
    {
        hmax[i] = poz;
        if( h[i]>=m ) m = h[i], poz = i;
    }

    //for(int i=1; i<=N; i++) printf("%d ", hmax[i]); printf("\n");

    for(int i=N-1; i>=1; i--)
    {
        if( h[i] < h[ hmax[i] ] ) continue;
        if( hmax[i]==i+1 && h[i]==h[ hmax[i] ] ) cmin[i] = cmin[ hmax[i] ];
        else
        {
            int t = (hmax[i]-i-1) - (h[i]-h[ hmax[i] ]) + cmin[hmax[i]];
            if( hmax[i]==i+1 ) t += 1;
            if( t<=0 ) t = 1;
            cmin[i] = t;
        }
    }

    //for(int i=1; i<=N; i++) printf("%d ", cmin[i]); printf("\n");
    printf("%d", cmin[1]);
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

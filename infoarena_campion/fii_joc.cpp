#include<stdio.h>
#include<string.h>
#include<algorithm>
#define inf "joc.in"
#define outf "joc.out"
#define NMax 20010
#define LMax 110
using namespace std;

int N, d[NMax], p[NMax];
int best[2][LMax];
//best[i][j] = nr minim de cuv magice spuse pentru a ramane cu viata j dupa lupta cu monstrul i
//best[i][j] = -1, nu se poate ajunge la monstrul i ca dupa lupta cu el sa ramai cu viata j

void read()
{
    scanf("%d", &N);

    for(int i=1; i<=N; i++) scanf("%d%d", &d[i], &p[i]);
}

inline int min(int a, int b) { return a<b ? a : b; }

void solve()
{
    memset( best, -1, sizeof(best) );

    int n = 1, o = 0;

    best[o][100] = 1; //spun cuvantul magic din prima
    best[o][100-p[1]] = 0; //nu spun cuvantul magic

    for(int i=2; i<=N; i++) {
        for(int ol=1; ol<=100; ol++) {
            if( best[o][ol]==-1 ) continue;

            //trecem de la (i-1, ol) => (i, nl)
            //ol - old life; nl - new life

            int nl = 0;

            //spun cuv magic
            nl = min(100, ol+d[i]);
            if( best[n][nl]==-1 ) best[n][nl] = best[o][ol]+1;
            else best[n][nl] = min(best[n][nl], best[o][ol]+1);

            //nu spun cuv magic
            nl -= p[i];
            if( nl<=0 ) continue;
            if( best[n][nl]==-1 ) best[n][nl] = best[o][ol];
            else best[n][nl] = min( best[n][nl], best[o][ol] );
        }

        swap(n, o);
        for(int j=0; j<=100; j++) best[n][j] = -1;
    }

    int ans = 0x3f3f3f3f; //infinit
    for(int viata=1; viata<=100; viata++)
        if( best[o][viata]!=-1 && best[o][viata]<ans ) ans = best[o][viata];

    printf("%d", ans);
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

#include<stdio.h>
#define inf "fluviu.in"
#define outf "fluviu.out"
#define NMax 50001
#define INF 100000000000000000LL
using namespace std;

int N;
int best[NMax][3];
int cd[NMax][3][3], d[NMax][3];
//0-port, 1-autogara, 2-heliport

void read()
{
    scanf("%d", &N);
    for(int i=1; i<=N; i++) scanf("%d", &cd[i][0][1]), cd[i][1][0] = cd[i][0][1];
    for(int i=1; i<=N; i++) scanf("%d", &cd[i][0][2]), cd[i][2][0] = cd[i][0][2];
    for(int i=1; i<=N; i++) scanf("%d", &cd[i][1][2]), cd[i][2][1] = cd[i][1][2];

    for(int i=1; i<N; i++) scanf("%d", &d[i][0]);
    for(int i=1; i<N; i++) scanf("%d", &d[i][1]);
    for(int i=1; i<N; i++) scanf("%d", &d[i][2]);
}

inline int min(int a, int b) { return ( a<b ? a : b ); }

void solve()
{
    for(int i=1; i<=N; i++)
        for(int j=0; j<3; j++) best[i][j] = INF;

    best[1][0] = 0;
    best[1][1] = cd[1][0][1];
    best[1][2] = min( cd[1][0][2], cd[1][1][2] );
    //for(int j=0; j<3; j++) printf("%d ", best[1][j]); printf("\n");

    for(int i=2; i<=N; i++)
    {
        for(int j=0; j<3; j++) best[i][j] = min( best[i][j], best[i-1][j] + d[i-1][j] );

        for(int j=0; j<3; j++)
            for(int k=0; k<3; k++)
                if( j==k ) continue;
                else best[i][j] = min(best[i][j], best[i][k] + cd[i][k][j]);

       //for(int j=0; j<3; j++) printf("%d ", best[i][j]); printf("\n");
    }

    int rez = best[N][0];
    for(int i=1; i<3; i++) rez = min( rez, best[N][i] );
    printf("%d", rez);
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

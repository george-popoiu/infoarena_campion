#include<stdio.h>
#include<vector>
#include<string.h>
#include<queue>
#define inf "fmcm.in"
#define outf "fmcm.out"
#define NMax 351
#define INF 0x3f3f3f3f
using namespace std;

int N, M, S, D;
vector<int> G[NMax];
int C[NMax][NMax], Cost[NMax][NMax], F[NMax][NMax];
int go;
int D[NMax], From[NMax], viz[NMax];

void read()
{
    scanf("%d%d%d%d", &N, &M, &S, &D);

    int x, y, c, z;
    for(int i=1; i<=M; i++) {
        scanf("%d%d%d%d", &x, &y, &c, &z);
        G[x].push_back(y);
        G[y].push_back(x);

        C[x][y] = c;
        Cost[x][y] = z;
        Cost[y][x] = -z;
    }
}

int BF() {
    for(int i=1; i<=N; i++) { D[i] = INF; From[i] = -1; }

    queue<int> q; memset( viz, 0, sizeof(viz) );
    D[S] = 0;
}

void solve()
{
    go = 1; long long rez = 0;
    while( go ) {
        go = 0;
        rez += BF();
    }

    printf("%lld", rez);
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

#include<stdio.h>
#include<vector>
#define inf "asmax.in"
#define outf "asmax.out"
#define NMax 16100
#define INF 0x3f3f3f3f
using namespace std;

const int T = 1;

int N;
int V[NMax], S[NMax], c[NMax], viz[NMax];

vector<int> LA[NMax];

void read()
{
    scanf("%d", &N);
    for(int i=1; i<=N; i++) scanf("%d", &V[i]);

    int a,b;
    for(int i=1; i<N; i++)
    {
        scanf("%d%d", &a, &b);
        LA[a].push_back(b);
        LA[b].push_back(a);
    }
}

void dfs(int u)
{
    S[u] = V[u]; viz[u] = 1;
    for(int i=0; i<LA[u].size(); i++)
    {
        int v = LA[u][i];
        if( !c[v] && !viz[v] ) dfs(v);
    }
    for(int i=0; i<LA[u].size(); i++)
    {
        int v = LA[u][i];
        if( c[v] && S[v]>0 ) S[u] += S[v];
    }
    c[u] = 1;
}

void solve()
{
    for(int i=1; i<=N; i++) S[i] = INF;

    dfs(1);

    int rez = -INF;
    for(int i=1; i<=N; i++)
        if( S[i] > rez ) rez = S[i];
    printf("%d", rez);

    /*printf("\n");
    for(int i=1; i<=N; i++) printf("%d ", S[i]);*/
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

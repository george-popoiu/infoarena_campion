#include<stdio.h>
#include<vector>
#include<algorithm>
#define inf "kgraf.in"
#define outf "kgraf.out"
#define NMax 301
#define MMax 901
using namespace std;

int N, M, K;
vector< pair<int, int> > G[NMax];
int uz[NMax][NMax];
int sol;
int st[MMax], k, a[MMax];

void read()
{
    scanf("%d%d%d", &N, &M, &K);

    int a, b, c;
    for(int i=1; i<=M; i++) {
        scanf("%d%d%d", &a, &b, &c);
        G[a].push_back( make_pair(b, c) );
    }
}

int test(int v[], int dim) {
    for(int i=1; i<=dim; i++) a[i] = v[i];
    sort( a+1, a+dim+1 );
    int sm = 0, sM = 0;
    for(int i=1; i<=K; i++) sm += a[i], sM += a[dim-i+1];
    return sM - sm;
}

void dfs(int u) {
    if( k>=K ) {
        int r = test(st, k);
        if( r>sol ) sol = r;
    }
    for(int i=0; i<G[u].size(); i++) {
        int v = G[u][i].first, c = G[u][i].second;
        if( uz[u][v] ) continue;
        st[++k] = c; uz[u][v] = 1;
        dfs(v);
        k--; uz[u][v] = 0;
    }
}

void solve()
{
    for(int i=1; i<=N; i++) dfs(i);
    printf("%d", sol);
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

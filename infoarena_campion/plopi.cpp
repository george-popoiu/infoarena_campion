#include<stdio.h>
#include<vector>
#define inf "plopi.in"
#define outf "plopi.out"
#define NMax 100001
using namespace std;

int N, viz[NMax], d[NMax], nri, nrp = 1;
vector< pair<int,int> > G[NMax];

void read()
{
    scanf("%d", &N);

    int a, b, c;
    for(int i=1; i<N; i++) {
        scanf("%d%d%d", &a, &b, &c);
        G[a].push_back( make_pair(b, c) );
        G[b].push_back( make_pair(a, c) );
    }
}

void dfs(int u) {
    viz[u] = 1;
    for(int i=0; i<G[u].size(); i++) {
        int v = G[u][i].first, w = G[u][i].second;
        if( !viz[v] ) {
            d[v] = d[u] + w;
            if( d[v]%2 ) nri++;
            else nrp++;
            dfs(v);
        }
    }
}

void solve()
{
    dfs(1);

    printf("%lld", 1LL*nri*nrp);
}

int main() {
    freopen(inf, "r", stdin); freopen(outf, "w", stdout);
    read(); solve();
    return 0;
}

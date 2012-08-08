#include<stdio.h>
#include<map>
#include<vector>
#include<bitset>
#define inf "egal.in"
#define outf "egal.out"
#define NMax 100001
using namespace std;

int N, key[NMax];
vector<int> G[NMax];
map<int, int> M[NMax];
bitset<NMax> viz;

void read()
{
    scanf("%d", &N);

    int a, b;
    for(int i=1; i<=N; i++) {
        scanf("%d%d", &a, &b);
        G[a].push_back(b);
    }
}

void dfs(int u) {
    viz[u] = 1;

    if( !G[u].size() ) {
        M[u][ key[u] ]++;
        return;
    }

    for(int i=0; i<G[u].size(); i++) {
        int v = G[u][i];
        if( !viz[v] ) dfs(v);
    }

    for(int i=0; i<G[u].size(); i++) {
        int v = G[u][i];

        map<int,int>::iterator it;
        for( it = M[v].begin(); it != M[v].end(); ++it ) M[u][ it->first ] = it->second;
    }

    M[u][ key[u] ]++;
}

void solve()
{
    dfs(1);

    int
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

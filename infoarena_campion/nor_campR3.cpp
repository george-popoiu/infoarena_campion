#include<stdio.h>
#include<vector>
#include<algorithm>
#include<bitset>
#include<queue>
#define inf "nor.in"
#define outf "nor.out"
#define NMax 15010
#define pb push_back
using namespace std;

int N, M;
vector<int> G[NMax], cc;
bitset<NMax> viz;
queue<int> q; int u, v, nviz;

void read()
{
    scanf("%d%d", &N, &M);

    int a, b;
    for(int i=1; i<=M; i++) {
        scanf("%d%d", &a, &b);
        G[a].pb(b); G[b].pb(a);
    }
}

int BFS(int n) {
    q.push(n); viz[n] = 1; nviz = 1;
    while( !q.empty() ) {
        u = q.front(); q.pop();
        for(int i=0; i<G[u].size(); i++) {
            v = G[u][i];
            if( viz[v] ) continue;
            viz[v] = 1; nviz++;
            q.push(v);
        }
    }
    return nviz;
}

void solve()
{
    for(int i=1; i<=N; i++)
        if( !viz[i] ) cc.pb( BFS(i) );

    sort( cc.begin(), cc.end() );

    int C = (N/2) + 1, cnt = 0;
    for(int i=cc.size()-1; i>=0; i--) {
        if( cc[i]<3 ) break;
        cnt += cc[i];
        if( cnt>= C ) {
            printf("%d\n", cc.size()-i);
            for(int j=cc.size()-1; j>=i; j--) printf("%d ", cc[j]);
            return;
        }
    }

    printf("0");
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

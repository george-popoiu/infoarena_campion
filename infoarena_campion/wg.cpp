#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#define inf "wg.in"
#define outf "wg.out"
#define NMax 100100
#define KMax 18
#define INF 0x3f3f3f3f
using namespace std;

int N, M;
int A[NMax], RMQ[KMax][NMax], lg[NMax];

vector< pair<int,int> > LA[NMax];
int viz[NMax];

vector<int> cc[NMax];
int cc_nr;
int cmax = -INF, imin, nr;

void rmq()
{
    lg[1] = 0;
    for(int i=2; i<=N; i++) lg[i] = lg[i/2] + 1;

    for(int i=1; i<=N; i++) RMQ[0][i] = A[i];
    for(int k=1; (1<<k) <= N; k++)
        for(int i=1; i + (1<<k) - 1 <= N; i++)
            if( RMQ[k-1][i] < RMQ[k-1][ i + (1<<(k-1)) ] ) RMQ[k][i] = RMQ[k-1][i];
            else RMQ[k][i] =  RMQ[k-1][ i + (1<<(k-1)) ];
}

inline int query(int i, int j)
{
    int dif = j - i + 1;
    int l = lg[dif];
    int rest = dif - (1<<l);
    return ( RMQ[l][i] < RMQ[l][i+rest] ? RMQ[l][i] : RMQ[l][i+rest] );
}

inline int min(int a,int b) { return ( a<b ? a : b ); }

void read()
{
    scanf("%d", &N);
    for(int i=1; i<=N; i++) scanf("%d", &A[i]);
    rmq();

    scanf("%d", &M);
    int a,b,c;
    for(int i=1; i<=M; i++)
    {
        scanf("%d%d", &a, &b);
        c = query(a,b);
        LA[a].push_back( make_pair(b,c) );
        LA[b].push_back( make_pair(a,c) );
    }
}

void bfs(int s)
{
    viz[s] = 1; cc[++cc_nr].push_back(s);
    queue<int> q; q.push(s);
    while( !q.empty() )
    {
        int u = q.front(); q.pop();
        for(int i=0; i<LA[u].size(); i++)
        {
            int v = LA[u][i].first, c = LA[u][i].second;
            if( viz[v] ) continue;
            viz[v] = 1;
            q.push(v); cc[cc_nr].push_back(v);
            if( c > cmax ) cmax = c, nr = cc_nr, imin = min(u,v);
            else if( c==cmax && imin > min(u,v) ) imin = min(u,v), nr = cc_nr;
        }
    }
}

void solve()
{
    for(int i=1; i<=N; i++)
        if( !viz[i] ) bfs(i);

    vector<int> v;
    v.push_back( cc[nr][0] );
    for(int i=1; i<cc[nr].size(); i++)
        if( cc[nr][i] != cc[nr][i-1] ) v.push_back(cc[nr][i]);
    sort( v.begin(), v.end() );
    printf("%d\n%d\n", cmax, v.size());
    for(int i=0; i<v.size(); i++) printf("%d\n", v[i]);

    /*printf("%d\n%d\n", cmax, cc[nr].size());
    sort( cc[nr].begin(), cc[nr].end() );
    for(int i=0; i<cc[nr].size(); i++) printf("%d\n", cc[nr][i]);*/
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

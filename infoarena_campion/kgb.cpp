#include<stdio.h>
#include<vector>
#include<algorithm>
#define inf "kgb.in"
#define outf "kgb.out"
#define NMax 1100
using namespace std;

int N;
int dfn[NMax], low[NMax], art[NMax], nr, fii, k, e;
vector<int> G[NMax];
vector< vector<int> > C;

struct muchie { int u,tu; } st[ NMax*(NMax-1) / 2 ];

void read()
{
    scanf("%d", &N); int a,b;
    while( scanf("%d%d",&a,&b) != EOF ) { G[a].push_back(b); G[b].push_back(a); }
}

inline int min(int a,int b) { return ( a<b ? a : b ); }

void cache(int u, int tu)
{
    vector<int> v; muchie m;
    do
    {
        m = st[k--];
        v.push_back(m.u); v.push_back(m.tu);
    }
    while( m.u!=u || m.tu!=tu );
    C.push_back(v);
}

void DFS(int u, int tu)
{
    dfn[u] = low[u] = ++nr;
    for(int i=0; i<G[u].size(); i++)
    {
        int v = G[u][i];
        if( v==tu ) continue;
        if( !dfn[v] )
        {
            st[++k].tu = u; st[k].u = v;
            DFS(v,u);
            low[u] = min( low[u], low[v] );
            if( low[v]>=dfn[u] )
            {
                if( !u ) fii++;
                else art[u] = 1, e = 1;
                cache( v, u );
            }
        }
        else low[u] = min( low[u], dfn[v] );
    }
}

void solve()
{
    DFS(0,-1);
    if( fii>1 ) art[0] = 1, e = 1;

    if( !e ) { printf("KGB este forte"); return; }
    printf("KGB nu este forte\n");

    vector<int> A;
    for(int i=0; i<=N; i++)
        if( art[i] ) A.push_back(i);
    sort( A.begin(), A.end() );
    for(int i=0; i<A.size(); i++) printf("%d ", A[i]);

    printf( "\n%d\n", C.size() );
    for(int i=0; i<C.size(); i++)
    {
        vector<int> v = C[i];
        sort( v.begin(), v.end() );
        printf("%d ", v[0] );
        for(int i=1; i<v.size(); i++)
            if( v[i]!=v[i-1] ) printf("%d ", v[i]);
        printf("\n");
    }
}

int main()
{
    freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

#include<fstream>
#include<vector>
#include<queue>
#include<string.h>
#define inf "critice.in"
#define outf "critice.out"
#define NMax 2000
#define MMax 20000
#define INF 0x3f3f3f3f
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int N, M, K;
vector<int> G[NMax];
int C[NMax][NMax], F[NMax][NMax];
int viz[NMax], T[NMax];
int viz1[NMax], viz2[NMax];
int sol[MMax];

struct muchie { int a,b; }; muchie mm[MMax];

void read()
{
    f>>N>>M; int a,b,c;
    for(int i=1; i<=M; i++)
    {
        f>>a>>b>>c;
        mm[i].a = a; mm[i].b = b;
        C[a][b] = C[b][a] = c;
        G[a].push_back(b); G[b].push_back(a);
    }
}

inline int mod(int a) { return ( a<0 ? -a : a ); }

int BFS()
{
    memset( viz, 0, sizeof(viz) ); memset( T, 0, sizeof(T) );
    queue<int> Q; int v;
    viz[1] = 1; Q.push(1);
    while( !Q.empty() )
    {
        v = Q.front(); Q.pop();
        if( v==N ) return 1;
        for(int i=0; i<G[v].size(); i++)
        {
            int u = G[v][i];
            if( C[v][u] == mod(F[v][u]) || viz[u] ) continue;
            viz[u] = 1; Q.push(u); T[u] = v;
        }
    }
    return 0;
}

inline int min(int a,int b) { return ( a<b ? a : b ); }

void flux()
{
    while( BFS() )
    {
        for(int i=0; i<G[N].size(); i++)
        {
            int v = G[N][i];
            if( C[v][N] == mod(F[v][N]) || !viz[v] ) continue;
            T[N] = v;
            int fmin = (1<<30);

            for( int nod=N; nod!=1; nod=T[nod] )
                fmin = min( fmin, C[ T[nod] ][nod] - mod(F[ T[nod] ][nod]) );

            for( int nod=N; nod!=1; nod=T[nod] )
            {
                F[ T[nod] ][nod] += fmin;
                F[nod][ T[nod] ] = F[ T[nod] ][nod];
                //F[nod][ T[nod] ] -= fmin;
            }
        }
    }
}

void BFS2(int s, int vi[])
{
    queue<int> Q;
    Q.push(s); vi[s] = 1;
    while( !Q.empty() )
    {
        int v = Q.front(); Q.pop();
        for(int i=0; i<G[v].size(); i++)
        {
            int u = G[v][i];
            if( C[v][u] == mod(F[v][u]) || vi[u] ) continue;
            vi[u] = 1;
            Q.push(u);
        }
    }
}

void solve()
{
    flux();
    BFS2(1, viz1); BFS2(N, viz2);
    for(int i=1; i<=M; i++)
    {
        int a = mm[i].a, b = mm[i].b;
        if( ( mod(F[a][b]) == C[a][b] )  && ( ( viz1[a]==1 && viz2[b]==1 ) || ( viz2[a]==1 && viz1[b]==1 ) ) ) K++, sol[K] = i;
    }
    g<< K <<"\n";
    for(int i=1; i<=K; i++) g<< sol[i] <<"\n";
}

int main()
{
	read(); solve();
	f.close(); g.close();
	return 0;
}

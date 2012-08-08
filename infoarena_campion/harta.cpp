#include<fstream>
#include<queue>
#include<vector>
#include<string.h>
#define inf "harta.in"
#define outf "harta.out"
#define NMax 110
#define INF 0x3f3f3f3f
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int N, S, D, M;
int C[3*NMax][3*NMax], F[3*NMax][3*NMax], viz[3*NMax], T[3*NMax];
vector<int> G[3*NMax];

void read()
{
    f>>N; int x,y; S = 2*N+1; D = 2*N+2;
    for(int i=1; i<=N; i++)
    {
        f>>x>>y; M += x;
        G[S].push_back(i); G[i].push_back(S); C[S][i] = x;
        G[i+N].push_back(D); G[D].push_back(i+N); C[i+N][D] = y;
        for(int j=1; j<=N; j++)
        {
            if( i==j ) continue;
            G[i].push_back(j+N); G[j+N].push_back(i);
            C[i][j+N] = 1;
        }
    }
}

bool BFS()
{
    memset( viz, 0, sizeof(viz) ); memset( T, 0, sizeof(T) );
    queue<int> Q; Q.push(S); viz[S] = 1;
    while( !Q.empty() )
    {
        int u = Q.front(); Q.pop();
        if( u==D ) continue;
        for(int i=0; i<G[u].size(); i++)
        {
            int v = G[u][i];
            if( C[u][v] == F[u][v] || viz[v] ) continue;
            Q.push(v); viz[v] = 1;
            T[v] = u;
        }
    }
    return ( viz[D] == 1 );
}

inline int min(int a,int b) { return ( a<b ? a : b ); }

void flux()
{
    while( BFS() )
    {
        for(int i=0; i<G[D].size(); i++)
        {
            int u = G[D][i];
            if( C[u][D] == F[u][D] || !viz[u] ) continue;
            T[D] = u;

            int fmin = INF;
            for( int nod=D; nod!=S; nod=T[nod] )
                fmin = min( fmin, C[ T[nod] ][nod] - F[ T[nod] ][nod] );
            if( !fmin ) continue;

            for( int nod=D; nod!=S; nod=T[nod] )
            {
                F[ T[nod] ][nod] += fmin;
                F[nod][ T[nod] ] -= fmin;
            }
        }
    }
}

void solve()
{
    flux();
    g<< M <<"\n";
    for(int i=1; i<=N; i++)
        for(int j=N+1; j<=2*N; j++)
            if( F[i][j] ) g<< i <<" "<< j-N <<"\n";
}

int main()
{
	read(); solve();
	f.close(); g.close();
	return 0;
}

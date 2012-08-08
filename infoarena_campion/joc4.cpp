#include<fstream>
#include<queue>
#include<vector>
#include<string.h>
#define inf "joc4.in"
#define outf "joc4.out"
#define NMax 253
#define MMax 5100
#define INF 0x3f3f3f3f
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

const int S = NMax - 2; const int D = NMax - 1;

int N, M, A, B, fmax;
int C[NMax][NMax], F[NMax][NMax], viz[NMax], T[NMax];
vector<int> G[NMax];

inline int mod(int a) { return ( a<0 ? -a : a ); }

void read()
{
    f>>N>>M>>A>>B; int x,y;
    for(int i=1; i<=M; i++)
    {
        f>>x>>y;
        G[x].push_back(y); G[y].push_back(x);
        C[x][y] = C[y][x] = 1;
    }
    G[S].push_back(A); G[A].push_back(S); C[S][A] = INF;
    G[B].push_back(D); G[D].push_back(B); C[B][D] = INF;
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
            if( C[u][v]== mod(F[u][v]) || viz[v] ) continue;
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
            if( C[u][D] == mod(F[u][D]) || !viz[u] ) continue;
            T[D] = u;

            int fmin = INF;

            for(int nod=D; nod!=S; nod=T[nod])
                fmin = min( fmin, C[ T[nod] ][nod] - mod(F[ T[nod] ][nod]) );

            if( !fmin ) continue;

            for(int nod=D; nod!=S; nod=T[nod])
            {
                F[ T[nod] ][nod] += fmin;
                F[nod][ T[nod] ] = F[ T[nod] ][nod];
                //F[nod][ T[nod] ] -= fmin;
            }

            fmax += fmin;
        }
    }
}

void solve()
{
    flux();
    g<< fmax;
}

int main()
{
	read(); solve();
	f.close(); g.close();
	return 0;
}

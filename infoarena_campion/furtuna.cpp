#include<stdio.h>
#include<vector>
#include<string.h>
#include<queue>
#define inf "furtuna.in"
#define outf "furtuna.out"
#define NMax 410
#define MMax 2010
#define TCMax 110
#define INF 0x3f3f3f3f
using namespace std;

struct cabana { int eticheta,capacitate; };

int N, M, T, C;
int Turist[TCMax]; cabana Cabana[TCMax];
int MA[NMax][NMax]; int D[NMax][NMax];
int COST_MAX = -INF;

int min(int a,int b) { return ( a<b ? a : b ); }

void read()
{
    scanf("%d%d%d%d", &N, &M, &T, &C); int x,y,d;
    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++)
            if( i!=j ) D[i][j] = INF;
    for(int i=1; i<=M; i++)
    {
        scanf("%d%d%d",&x, &y, &d);
        MA[x][y] = MA[y][x] = D[x][y] = D[y][x] = d;
        if( d>COST_MAX ) COST_MAX = d;
    }
    for(int i=1; i<=T; i++) scanf("%d", &Turist[i]);
    for(int i=1; i<=C; i++) scanf("%d%d", &Cabana[i].eticheta, &Cabana[i].capacitate);
}

void RoyFloyd()
{
    for(int k=1; k<=N; k++)
        for(int i=1; i<=N; i++)
            for(int j=1; j<=N; j++)
                if( D[i][j] > D[i][k] + D[k][j] ) D[i][j] = D[i][k] + D[k][j];
}

bool BFS(vector<int> G[NMax], int S, int Dest, int Ca[NMax][NMax], int F[NMax][NMax], int viz[NMax], int Ta[NMax])
{
    for(int i=0; i<=Dest; i++) viz[i] = 0;
    queue<int> Q; Q.push(S); viz[S] = 1;
    while( !Q.empty() )
    {
        int u = Q.front(); Q.pop();
        if( u==Dest ) continue;
        for(int i=0; i<G[u].size(); i++)
        {
            int v = G[u][i];
            if( Ca[u][v] == F[u][v] || viz[v] ) continue;
            Q.push(v); viz[v] = 1;
            Ta[v] = u;
        }
    }
    return ( viz[Dest] == 1 );
}

int flux(int t)
{
    int S = 0, Dest = N+1;
    vector<int> G[NMax]; int Ca[NMax][NMax], F[NMax][NMax]; int viz[NMax], Ta[NMax]; memset( Ta, 0, sizeof(T) ); memset( viz, 0, sizeof(viz) );
    for(int i=0; i<=N+1; i++)
        for(int j=i; j<=N+1; j++) Ca[i][j] = Ca[j][i] = F[i][j] = F[j][i] = 0;
    for(int i=1; i<=T; i++)
    {
        G[S].push_back(Turist[i]); G[ Turist[i] ].push_back(S);
        Ca[S][ Turist[i] ] = 1;
    }
    for(int i=1; i<=C; i++)
    {
        G[ Cabana[i].eticheta ].push_back(Dest); G[Dest].push_back( Cabana[i].eticheta );
        Ca[ Cabana[i].eticheta ][Dest] = Cabana[i].capacitate;
    }
    for(int i=1; i<=T; i++)
        for(int j=1; j<=C; j++)
            if( D[ Turist[i] ][ Cabana[j].eticheta ] <= t )
            {
                G[ Turist[i] ].push_back( Cabana[j].eticheta ); G[ Cabana[j].eticheta ].push_back( Turist[i] );
                Ca[ Turist[i] ][ Cabana[j].eticheta ] = Ca[ Cabana[j].eticheta ][ Turist[i] ] = 1;
            }
    int fmax = 0;
    while( BFS(G, S, Dest, Ca, F, viz, Ta) )
    {
        for(int i=0; i<G[Dest].size(); i++)
        {
            int u = G[Dest][i];
            if( Ca[u][Dest] == F[u][Dest] || !viz[u] ) continue;
            Ta[Dest] = u;

            int fmin = INF;
            for(int nod=Dest; nod!=S; nod=Ta[nod] )
                fmin = min(fmin, Ca[ Ta[nod] ][nod] - F[ Ta[nod] ][nod] );

            if( !fmin ) continue;

            for(int nod=Dest; nod!=S; nod=Ta[nod])
            {
                F[ Ta[nod] ][nod] += fmin;
                F[nod][ Ta[nod] ] -= fmin;
            }

            fmax += fmin;
        }
    }

    return fmax;
}

int binary_search(int dr)
{
    int st = 1;
    int tmin = INF;
    while( st<=dr )
    {
        int m = (st+dr)>>1 ;
        int f = flux(m); //printf("%d\n",f);
        if( f==T ) dr = m-1, tmin = min(tmin, m);
        else st = m+1;
    }
    return tmin;
}

void solve()
{
    RoyFloyd();
    printf("%d", binary_search( M * COST_MAX ) );
}

int main()
{
    freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

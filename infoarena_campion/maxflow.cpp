#include<fstream>
#include<string.h>
#include<vector>
#include<queue>
#define inf "maxflow.in"
#define outf "maxflow.out"
#define NMax 1100
#define MMax 5100
#define INF 0x3f3f3f3f
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int N,M;
vector<int> LA[NMax];
int C[NMax][NMax],F[NMax][NMax];
int viz[NMax],T[NMax];

void read()
{
	f>>N>>M;
	int a,b,c;
	for(int i=1; i<=M; i++)
	{
		f>>a>>b>>c;
		C[a][b] = c;
		LA[a].push_back(b);
		LA[b].push_back(a);
	}
}

int BFS()
{
	memset( viz, 0, sizeof(viz) );

	viz[1] = 1;
	queue<int> q;
	q.push(1);

	while( !q.empty() )
	{
		int x =  q.front(); q.pop();
		if( x==N ) continue;
		for(int i=0; i<LA[x].size(); i++)
		{
			int v = LA[x][i];
			if( C[x][v] == F[x][v] || viz[v] ) continue;
			viz[v] = 1;
			T[v] = x;
			q.push(v);
		}
	}

	return viz[N];
}

inline int min(int a,int b) { return ( a<b ? a : b ); }

void solve()
{
	int flow = 0;

	while( BFS() )
	{
		for(int i=0; i<LA[N].size(); i++)
		{
			int nod = LA[N][i];
			if( F[nod][N] == C[nod][N] || !viz[nod] ) continue;
			T[N] = nod;

			int fmin = INF;

			for( nod = N; nod!=1; nod=T[nod] )
				fmin = min(fmin, C[ T[nod] ][nod] - F[ T[nod] ][nod] );

			if( fmin==0 ) continue;

			for( nod = N; nod != 1; nod = T[nod] )
			{
				F[ T[nod] ][nod] += fmin;
				F[nod][ T[nod] ] -= fmin;
			}

			flow += fmin;
		}
	}

	g<< flow;
}

int main()
{
	read(); solve();
	f.close(); g.close();
	return 0;
}

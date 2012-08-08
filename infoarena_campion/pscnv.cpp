#include<fstream>
#include<vector>
#include<queue>
#define inf "pscnv.in"
#define outf "pscnv.out"
#define NMax 251000
#define MMax 501000
#define KMax 1001
#define INF 0x3f3f3f3f
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int N, M, a, b;
int cost[NMax];
vector< pair<int,int> > LA[NMax];
queue<int> L[KMax];

void read()
{
    f>>N>>M>>a>>b;
    int x,y,z;
    for(int i=1; i<=M; i++)
    {
        f>>x>>y>>z;
        LA[x].push_back( make_pair(y,z) );
    }
}

inline int max(int a,int b) { return ( a>b ? a : b ); }

void solve()
{
    for(int i=1; i<=N; i++) cost[i] = INF;
    cost[a] = 0;
    L[0].push(a); int x,y,z,c;
    for(int i=0; i<KMax; i++)
        while( !L[i].empty() )
        {
            x = L[i].front(); L[i].pop();
            if( x==b ) return;
            if( cost[x]==i )
                for(int j=0; j<LA[x].size(); j++)
                {
                    y = LA[x][j].first; z = LA[x][j].second;
                    c = max( z, cost[x] );
                    if( cost[y] > c ) cost[y] = c, L[c].push(y);
                }
        }
}

int main()
{
	read(); solve();
	g<< cost[b];
	f.close(); g.close();
	return 0;
}

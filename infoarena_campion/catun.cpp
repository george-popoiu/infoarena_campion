#include<fstream>
#include<vector>
#include<queue>
#define inf "catun.in"
#define outf "catun.out"
#define NMax 50000
#define INF 100000000000000000LL
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int N, M, K;
int fort[NMax], inq[NMax], sol[NMax];
long long d[NMax];
vector< pair<int,long long> > LA[NMax];

void read()
{
    int x,y; long long z;
    f>>N>>M>>K;
    for(int i=1; i<=K; i++) f>>fort[i];
    for(int i=1; i<=M; i++)
    {
        f>>x>>y>>z;
        LA[x].push_back( make_pair(y,z) );
        LA[y].push_back( make_pair(x,z) );
    }
}

void solve()
{
    queue<int> q;
    for(int i=1; i<=N; i++) d[i] = INF;
    for(int i=1; i<=K; i++) d[ fort[i] ] = 0, inq[ fort[i] ] = 1, sol[ fort[i] ] = fort[i], q.push( fort[i] );

    int x,y; long long z;
    while( !q.empty() )
    {
        x = q.front(); q.pop(); inq[x] = 0;
        for(int i=0; i<LA[x].size(); i++)
        {
            y = LA[x][i].first; z = LA[x][i].second;
            if( d[x] + z < d[y] )
            {
                d[y] = d[x] + z; sol[y] = sol[x];
                if( !inq[y] ) inq[y] = 1, q.push(y);
            }
            else if( d[x] + z == d[y] && sol[x] < sol[y] ) sol[y] = sol[x];
        }
    }

    for(int i=1; i<=N; i++)
    {
        if( sol[i]==i ) sol[i] = 0;
        g<< sol[i] <<" ";
    }
}

int main()
{
	read(); solve();
	f.close(); g.close();
	return 0;
}

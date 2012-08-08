#include<fstream>
#include<list>
#include<queue>
#define inf "dist.in"
#define outf "dist.out"
#define NMax 100
#define INF 0x3f3f3f3f
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int n,m;
int s,r;
int d[NMax];
bool inqueue[NMax];
list< pair<int,int> > la[NMax];
queue<int> q;

void read()
{
int x,y,c;
f>>n>>m;
f>>s>>r;
for(int i=1;i<=m;i++)
    {
    f>>x>>y>>c;
    la[x].push_back( make_pair(y,c) );
    la[y].push_back( make_pair(x,c) );
    }
}

void init(){ for(int i=1;i<=n;i++)d[i]=INF; }

void solve()
{
int t;
init();
d[s]=0;
q.push(s); inqueue[s]=true;
while( !q.empty() )
    {
    t=q.front();
    q.pop(); inqueue[t]=false;
    for( list< pair<int,int> >::iterator it=la[t].begin(); it!=la[t].end(); it++ )
        if( d[(*it).first] > d[t] + (*it).second )
            {
            d[(*it).first] = d[t] + (*it).second ;
            if(!inqueue[(*it).first]) { q.push( (*it).first ); inqueue[ (*it).first ]=true; }
            }
    }
}

int main()
{
read();
solve();
g<<d[r];
f.close();
g.close();
return 0;
}

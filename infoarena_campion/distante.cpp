#include<fstream>
#include<bitset>
#include<vector>
#include<queue>
#define inf "distante.in"
#define outf "distante.out"
#define NMax 50100
#define INF 0x3f3f3f3f
#define mp make_pair
#define pb push_back
#define FOR( it, C ) for( typeof(C.begin()) it=C.begin(); it!=C.end(); ++it )
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int T;
int N,M,S;
int D[NMax];

void BF( vector< pair<int,int> > LA[NMax] )
{
bitset<NMax> in;
queue<int> coada;
int d[NMax];
for(int i=1; i<=N; i++) d[i]=INF;
d[S]=0;
coada.push(S);
int t;
while( !coada.empty() )
    {
    t = coada.front(); coada.pop();
    FOR( it, LA[t] )
        if( d[ (*it).first ] > d[t] + (*it).second )
            {
            d[ (*it).first ] = d[t] + (*it).second ;
            if( !in[ (*it).first ] ) coada.push( (*it).first ) ;
            }
    }
for(int i=1; i<=N; i++)
    if( D[i]!=d[i] ) { g<<"NU\n"; return; }
g<<"DA\n";
}

void read_solve()
{
int a,b,c;
vector< pair<int,int> > LA[NMax];
for(int i=1; i<=M; i++)
    {
    f>>a>>b>>c;
    LA[a].pb( mp(b,c) );
    LA[b].pb( mp(a,c) );
    }
BF( LA );
}

int main()
{
f>>T;
for( ; T; T-- )
    {
    f>>N>>M>>S;
    for(int i=1; i<=N; i++) f>>D[i];
    read_solve();
    }
f.close(); g.close();
return 0;
}

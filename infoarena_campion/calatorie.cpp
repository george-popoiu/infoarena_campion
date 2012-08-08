#include<fstream>
#include<bitset>
#define inf "calatorie.in"
#define outf "calatorie.out"
#define NMax 60
#define HMax 510
#define ll long long
#define INF 100000000000000000LL
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int T,n;
ll c[NMax][HMax];
ll N[NMax],H[NMax];

inline ll p4(ll a) { return ( (a)*(a)*(a)*(a) ); }

inline ll min(ll a, ll b) { return ( a<b ? a : b ) ; }

void solve()
{
for(int i=2; i<=n; i++)
    for(int j=0; j<=HMax; j++)
        {
        c[i][j]=c[i-1][j]+N[i-1];
        if(  j-H[i-1]>=0 && c[i][j] > c[i-1][ j-H[i-1] ] - p4(j-H[i-1]) + p4(j) ) c[i][j] = c[i-1][ j-H[i-1] ] - p4(j-H[i-1]) + p4(j) ;
        }
ll min=INF;
for(int j=0; j<=HMax; j++)
    if( c[n][j]<min ) min=c[n][j];
g<<"Consumul minim = "<<min<<".\n";
}

void read()
{
f>>T;
for( int j=1; j<=T; j++ )
    {
    f>>n;
    for(int i=1; i<n; i++) f>>N[i]>>H[i];
    solve();
    }
}

int main()
{
read();
f.close(); g.close();
return 0;
}

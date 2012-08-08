#include<fstream>
#include<queue>
#define inf "arb_h.in"
#define outf "arb_h.out"
#define INF 0x3f3f3f3f
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int n,rad;
int A[100][100],niv[100],s[100];
queue<int> coada;

void read()
{
int a,b;
f>>n>>rad;
for(int i=1; i<n; i++) f>>a>>b , A[a][b]=A[b][a]=1;
}

void solve()
{
int t;
coada.push(rad); s[rad]=1;
while( !coada.empty() )
    {
    t = coada.front(); coada.pop();
    for(int k=1; k<=n; k++)
        if( A[t][k] && !s[k] ) s[k]=1 , niv[k]=1+niv[t] , coada.push(k) ;
    }
int max=-INF;
for(int i=1; i<=n; i++)
    {
    g<<niv[i]<<" ";
    if( niv[i]>max ) max=niv[i];
    }
g<<"\n"<<max;
}

int main()
{
read();
solve();
f.close();
g.close();
return 0;
}

#include<fstream>
#define inf "arb_rad.in"
#define outf "arb_rad.out"
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int n,k;
int A[100][100],T[100],s[100];

void read()
{
int a,b;
f>>n>>k;
for(int i=1; i<n; i++) f>>a>>b , A[a][b]=A[b][a]=1;
}

void dfs(int nod)
{
s[nod]=1;
for(int k=1; k<=n; k++)
    if( A[nod][k] && !s[k] )
        {
        T[k]=nod;
        dfs(k);
        }
}

void solve()
{
dfs(k);
for(int i=1; i<=n; i++) g<<T[i]<<" ";
}

int main()
{
read();
solve();
f.close();
g.close();
return 0;
}

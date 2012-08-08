#include<fstream>
#define inf "cicl_elem.in"
#define outf "cicl_elem.out"
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int A[100][100],T[100],s[100];
int n,m;
int gasit,nrc;
int st;

void read()
{
int a,b;
f>>n>>m;
for(int i=1; i<=m; i++)
    {
    f>>a>>b;
    A[a][b]=A[b][a]=1;
    }
}

void ciclu(int nod)
{
while( nod!=st )
    {
    g<<nod<<" ";
    nod=T[nod];
    }
g<<st<<"\n";
}

void dfs(int nod)
{
s[nod]=1;
for(int k=1; k<=n; k++)
    if( A[nod][k]==1 )
        {
        A[k][nod]=0;
        if( s[k]==0 )
            {
            s[k]=1;
            T[k]=nod;
            dfs(k);
            }
        else
            {
            gasit=1; nrc++;
            g<<"Ciclul "<<nrc<<" : "<<k<<" ";
            st=k;
            ciclu(nod);
            }
        }
}

void solve() { dfs(1); }

int main()
{
read();
solve();
if( !gasit ) g<<"Nu are cicluri elementare.";
f.close();
g.close();
return 0;
}

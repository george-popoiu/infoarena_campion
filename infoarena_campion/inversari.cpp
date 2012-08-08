#include<fstream>
#define inf "inversari.in"
#define outf "inversari.out"
#define NMax 10000
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int n,m;
int v[NMax];
int nri[NMax][NMax];

void read()
{
f>>n>>m;
for(int i=1; i<=n; i++) f>>v[i];
//compute
for(int i=1; i<n; i++)
    for(int j=i+1; j<=n; j++)
        {
        nri[i][j] += nri[i][j-1];
        if( v[j]<v[i] ) nri[i][j]++;
        for(int k=i-1; k>=1; k--) nri[k][j] += nri[i][j];
        }
//answer queries
int x,y;
for(int i=1; i<=m; i++)
    {
    f>>x>>y;
    g<< nri[x][y] <<"\n";
    }
}

int main()
{
read();
f.close(); g.close();
return 0;
}

#include<fstream>
#define inf "ccomb.in"
#define outf "ccomb.out"
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int n,m;
int *c[100];

void read()
{
f>>n>>m;
}

void solve()
{
for(int i=1; i<=n; i++)
    {
    c[i] = new int[i+1];
    c[i][0]=c[i][i]=1;
    for(int j=1; j<i; j++) c[i][j]=c[i-1][j]+c[i-1][j-1];
    delete c[i-1];
    }
g<<c[n][m];
}

int main()
{
read();
solve();
f.close();
g.close();
return 0;
}

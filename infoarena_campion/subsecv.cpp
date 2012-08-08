#include<fstream>
#define inf "subsecv.in"
#define outf "subsecv.out"
#define INF 0x3f3f3f3f
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int n,m;
int a[100],b[100],c[100][100];
int s=-INF;

void read()
{
f>>n;
for(int i=1; i<=n; i++) f>>a[i];
f>>m;
for(int i=1; i<=m; i++) f>>b[i];
}

void solve()
{
for(int i=1; i<=n; i++)
    for(int j=1; j<=m; j++)
        if( a[i]==b[j] )
            {
            c[i][j]=1+c[i-1][j-1];
            if( c[i][j] > s ) s=c[i][j];
            }
g<<s;
}

int main()
{
read();
solve();
f.close();
g.close();
return 0;
}

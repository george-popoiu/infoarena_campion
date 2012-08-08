#include<fstream>
#define inf "diagonala.in"
#define outf "diagonala.out"
#define NMax 10100
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int n;
int dp[NMax][NMax];
int dm[NMax][NMax];
int result;

struct coord { int x,y; };

coord c[NMax];

void read()
{
int a,b;
f>>n;
for(int i=1; i<=n; i++)
    {
    f>>a>>b;
    c[i].x = a; c[i].y = b;
    }
}

void solve()
{
//initializare
for(int i=c[1].x; i<=c[1].y; i++) dp[1][i]=1 , dm[1][i]=1;
//initializare
for(int i=2; i<=n; i++)
    for(int j=c[i].x; j<=c[i].y ; j++)
        {
        dm[i][j] = dp[i][j] = 1;
        if( j <= c[i-1].y + 1 && j > c[i-1].x ) dp[i][j] = dp[i-1][j-1] + 1;
        if( j < c[i-1].y && j>=c[i-1].x - 1 ) dm[i][j] = dm[i-1][j+1] + 1;
        if( dp[i][j]>result ) result=dp[i][j];
        if( dm[i][j]>result ) result=dm[i][j];
        }
g<< result;
}

int main()
{
read(); solve();
f.close(); g.close();
return 0;
}

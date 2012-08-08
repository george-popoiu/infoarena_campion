#include<fstream>
#define inf "nr_part2.in"
#define outf "nr_part2.out"
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int n,k;
int s[100][100];

void read()
{
f>>n>>k;
}

void solve()
{
for(int i=1; i<=n; i++)
    {
    s[i][1] = s[i][i] = 1 ;
    for( int j=2; j<i; j++ )
        for(int t=1; t<=j; t++) s[i][j] += s[i-j][t] ;
    }
g<< s[n][k] ;
}

int main()
{
read();
solve();
f.close();
g.close();
return 0;
}

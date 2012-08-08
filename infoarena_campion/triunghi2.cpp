#include<stdio.h>
#define inf "triunghi2.in"
#define outf "triunghi2.out"
#define nmax 1000
using namespace std;

int n, t[nmax][nmax];
int banda[nmax][nmax][2];
int ct[nmax][nmax][2];

void read()
{
    scanf("%d", &n);
    int lin = n;
    while( lin )
    {
        for(int i=1; i<=n-lin+1; i++) scanf("%d", &t[lin][i]);
        lin--;
    }
}

void compute_banda()
{
    for(int i=2; i<=n; i++)
        for(int j=1; j<=n-i+1; j++)
        {
            banda[i][j][0] = t[i][j] + t[i-1][j] + banda[i-1][j][0];
            banda[i][j][1] = t[i][j] + t[i-1][j+1] + banda[i-1][j+1][1];
        }
    for(int i=2; i<=n; i++)
        for(int j=1; j<=n-i+1; j++)
        {
            ct[i][j][1] = ct[i-1][j+1][1] + t[i][j] + t[i-1][j];
            ct[i][j][0] = ct[i-1][j][0] + t[i][j] + t[i-1][j+1];
        }
}

inline int min(int a, int b) { return ( a<b ? a : b ); }

void solve()
{
    compute_banda();

    for(int i=1; i<=n; i++) t[1][i] = 0;
    for(int i=2; i<=n; i++)
        for(int j=1; j<=n-i+1; j++)
            t[i][j] = min( t[i-1][j] + banda[i][j][1] + ct[i][j][1]*(i-1),
                            t[i-1][j+1] + banda[i][j][0] + ct[i][j][0]*(i-1) );
    printf("%d", t[n][1]);
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

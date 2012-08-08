#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define inf "siruri2.in"
#define outf "siruri2.out"
#define lmax 502
using namespace std;

int n, m;
char a[lmax], b[lmax];
int best[lmax][lmax];
//best[i][j] = nr. minim de operatii necesare transformarii prefixului de lungime i din sirul a in prefixul de lungime j din sirul b
//best[i][0] = i, V i = 1,...,n
//best[0][j] = j, V j = 1,...,m
//sol <- best[n][m]

void read()
{
    gets(a+1); gets(b+1);
    n = strlen(a+1); m = strlen(b+1);
}

inline int min(int a, int b) { return ( a<b ? a : b ); }

void solve()
{
    for(int i=1; i<=n; i++) best[i][0] = i;
    for(int j=1; j<=m; j++) best[0][j] = j;

    int cost;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
        {
            cost = 1;
            if( tolower(a[i])==tolower(b[j]) ) cost = 0;
            best[i][j] =  min( best[i-1][j]+1, min(best[i][j-1]+1, best[i-1][j-1]+cost) );
        }
    printf("%d", best[n][m]);
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

#include<stdio.h>
#include<vector>
#include<algorithm>
#define inf "sant.in"
#define outf "sant.out"
#define SMax 101
#define NMax 51
#define CMax 11
#define INF 0x3f3f3f3f
using namespace std;

int S, N, C;
int L[CMax], P[CMax];
int best[NMax][SMax], pre[NMax][SMax];

void read()
{
    scanf("%d%d%d", &S, &N, &C);
    for(int i=1; i<=C; i++) scanf("%d%d", &L[i], &P[i]);
}

void solve()
{
    for(int i=0; i<=N; i++)
        for(int j=0; j<=S; j++) best[i][j] = INF;

    for(int j=1; j<=S; j++)
        for(int k=1; k<=C; k++)
            if( L[k]==j && P[k]<best[1][j] ) best[1][j] = P[k];

    best[0][0] = 0;
    for(int i=1; i<=N; i++)
        for(int j=1; j<=S; j++)
        {
            best[i][j] = best[i-1][j];
            for(int k=1; k<=C; k++)
                if( j>=L[k] && best[i][j] > best[i-1][j-L[k]] + P[k] ) best[i][j] = best[i-1][j-L[k]] + P[k], pre[i][j] = k;
                else if( j>=L[k] && best[i][j] == best[i-1][j-L[k]] + P[k] && k<pre[i][j] ) pre[i][j] = k;
        }

    if( best[N][S]==INF ) printf("0");
    else
    {
        printf("%d\n", best[N][S]);
        int i = N, j = S; vector<int> v;
        while( j && i )
        {
            v.push_back(pre[i][j]);
            j -= L[pre[i][j]];
            i--;
        }
        sort( v.begin(), v.end() );
        for( i=0; i<v.size(); i++ ) printf("%d ", v[i]);
    }
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

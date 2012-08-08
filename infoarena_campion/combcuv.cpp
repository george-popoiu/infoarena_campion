#include<stdio.h>
#include<string.h>
#define inf "combcuv.in"
#define outf "combcuv.out"
#define LMax 210
#define NMax 110
#define DMax 40
using namespace std;

int N, M, dp[DMax][DMax], l[NMax], sol;
char S[LMax], C[NMax][DMax];

//dp[i][j] = 1, daca primele i+j caractere ale secventei de testat
//              se pot forma cu i caract din primul cuv si j caract din al doilea
//dp[i][j] = max { dp[i-1][j] <=> C[a][i] == s[i+j],
//                 dp[i][j-1] <=> C[b][j] == s[i+j] }

void read()
{
    scanf("%s", S+1); M = strlen(S+1);
    scanf("%d", &N);
    for(int i=1; i<=N; i++) {
        scanf("%s", C[i]+1);
        l[i] = strlen(C[i]+1);
    }
}

inline int max(int a, int b) { return ( a>b ? a : b ); }

int merge(int a, int b, int st) {
    int n = l[a], m = l[b], dr = st+n+m-1;
    memset(dp, 0, sizeof(dp));

    dp[0][0] = 1;
    for(int i=1; i<=n; i++)
        if( C[a][i]==S[st+i-1] ) dp[i][0] = max( dp[i][0], dp[i-1][0] );

    for(int i=1; i<=m; i++)
        if( C[b][i]==S[st+i-1] ) dp[0][i] = max( dp[0][i], dp[0][i-1] );

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++) {
            if( C[a][i]==S[st+i+j-1] ) dp[i][j] = max( dp[i][j], dp[i-1][j] );
            if( C[b][j]==S[st+i+j-1] ) dp[i][j] = max( dp[i][j], dp[i][j-1] );
        }

    return dp[n][m];
}

void solve()
{
    int go;
    for(int i=1; i<N; i++)
        for(int j=i+1; j<=N; j++) {
            go = 1;
            for(int t=1; t<=M && go; t++)
                if( ( C[i][1]==S[t] || C[j][1]==S[t] ) && t+l[i]+l[j]-1<=M )
                    if( merge(i, j, t) ) { sol++; go = 0; }
        }

    printf("%d", sol);
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

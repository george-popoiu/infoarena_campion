#include<stdio.h>
#include<vector>
#include<algorithm>
#define inf "petsoft.in"
#define outf "petsoft.out"
#define NMax 1001
#define INF 0x3f3f3f3f
using namespace std;

vector<int> G[NMax];
int N, A[NMax][2], viz[NMax];
int C[NMax][NMax];

void read()
{
    scanf("%d", &N);

    int t;
    for(int i=2; i<=N; i++) {
        scanf("%d", &t);
        G[t].push_back(i);
    }

    for(int i=1; i<=N; i++) sort( G[i].begin(), G[i].end() );
}

inline int mod(int x) { return x<0 ? -x : x ; }

inline int max(int a, int b) { return a>b ? a : b; }

void init(int m) {
    for(int i=0; i<m; i++)
        for(int j=0; j<m; j++) C[i][j] = 0;
}

void dfs(int n) {
    viz[n] = 1;

    if( !G[n].size() ) return;

    for(int i=0; i<G[n].size(); i++) {
        int u = G[n][i];
        if( !viz[u] ) dfs(u);
    }

    //det A[n][0]
    int m = G[n].size(); init(m);
    for(int i=0; i<m; i++) {
        int u = G[n][i];
        C[i][i] = max( A[u][0], A[u][1] );
    }

    for(int k=1; k<m;k++)
        for(int i=0; i<m && i+k<m; i++) {
            int j = i+k;
            int u = G[n][i], v = G[n][j];
            C[i][j] = max( max( C[i+1][j], C[i][j-1] ), C[i+1][j-1] + mod(u-v) + A[u][0] + A[v][0] );
        }
    A[n][0] = C[0][m-1];

    if( n==1 ) return;

    //det A[n][1]
    vector<int> a( G[n].begin(), G[n].end() ); a.push_back(n); sort(a.begin(), a.end());
    m++; init(m);
    for(int i=0; i<m; i++) {
        int u = a[i];
        C[i][i] = max( A[u][0], A[u][1] );
    }
    for(int k=1; k<m;k++)
        for(int i=0; i<m && i+k<m; i++) {
            int j = i+k;
            int u = a[i], v = a[j];
            C[i][j] = max( max( C[i+1][j], C[i][j-1] ), C[i+1][j-1] + mod(u-v) + A[u][0] + A[v][0] );
        }
    A[n][1] = C[0][m-1];
}

void solve()
{
    dfs(1);
    printf("%d", A[1][0]);
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

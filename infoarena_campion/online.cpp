#include<stdio.h>
#include<string.h>
#include<list>
#include<algorithm>
#include<bitset>
#include<vector>
#define inf "online.in"
#define outf "online.out"
#define NMax 201
#define MMax 10001
#define lit list< pair<int,int> >::iterator
using namespace std;

const long long INF = 1LL<<26;

int N, M, K, cost;
int C[NMax][NMax], S[NMax];
bitset<NMax> viz;
list< pair<int,int> > APM[NMax];

void read()
{
    scanf("%d%d", &N, &M);

    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++) C[i][j] = INF;

    int a, b, c;
    for(int i=1; i<=M; i++) {
        scanf("%d%d%d", &a, &b, &c);
        C[a][b] = C[b][a] = c;
    }
}

void solve()
{
    for(int i=2; i<=N; i++) S[i] = 1;
    for(int k=1; k<N; k++) {
        int m = INF, j;
        for(int i=1; i<=N; i++)
            if( S[i] && C[i][S[i]]<m ) m = C[i][S[i]], j = i;

        cost += C[j][S[j]];
        APM[j].push_back( make_pair(S[j], C[j][S[j]]) ); APM[S[j]].push_back( make_pair(j, C[j][S[j]]) );
        S[j] = 0;

        for(int i=1; i<=N; i++)
            if( S[i] && C[i][S[i]]>C[i][j] ) S[i] = j;
    }

    printf("%d\n", cost);

    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++) C[i][j] = 0;

    for(int i=1; i<=N; i++)
        for(lit it=APM[i].begin(); it!=APM[i].end(); ++it) C[i][it->first] = C[it->first][i] = it->second;

    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) printf("%d ", C[i][j]);
        printf("\n");
    }

    scanf("%d", &K);

    int a, b, c;
    for(int k=1; k<=K; k++) {
        scanf("%d%d%d", &a, &b, &c);
        if( C[a][b]>c ) cost += (C[a][b]-c), C[a][b] = C[b][a] = c;
        else if( C[a][b]!=0 && C[a][b]<=c ) cost = cost;
        else {
        }

        printf("%d\n", cost);
    }
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

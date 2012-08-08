#include<stdio.h>
#include<vector>
#define inf "amenzi.in"
#define outf "amenzi.out"
#define TMax 3501
#define NMax 151
using namespace std;

int N, M, K, P;
vector< pair<int,int> > G[NMax];
int A[TMax][NMax], B[TMax][NMax];

void read()
{
    scanf("%d%d%d%d", &N, &M, &K, &P);

    int a, b, c;
    for(int i=1; i<=M; i++) {
        scanf("%d%d%d", &a, &b, &c);
        G[a].push_back( make_pair(b,c) );
        G[b].push_back( make_pair(a,c) );
    }

    for(int i=1; i<=K; i++) {
        scanf("%d%d%d", &a, &b, &c);
        B[b][a] += c;
    }
}

void solve()
{
    for(int i=2; i<=N; i++) A[0][i] = -1;

    for(int t=1; t<TMax; t++) {
        for(int i=1; i<=N; i++) {
            A[t][i] = A[t-1][i];
            for(int j=0, l = G[i].size(); j<l; j++) {
                pair<int, int> a = G[i][j];
                if( t>=a.second && A[t][i] < A[t-a.second][a.first] ) A[t][i] = A[t-a.second][a.first];
            }
            if( A[t][i]!=-1 ) A[t][i] += B[t][i];
        }
    }

    int a, b;
    for(int i=1; i<=P; i++) {
        scanf("%d%d", &a, &b);
        printf("%d\n", A[b][a]);
    }
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

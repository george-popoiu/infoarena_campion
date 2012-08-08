#include<stdio.h>
#include<vector>
#define inf "secv5.in"
#define outf "secv5.out"
#define NMax 1050000
#define MOD 666013
using namespace std;

int N, L, U;
int A[NMax], no[NMax];
vector< pair<int,int> > H[MOD];

void read()
{
    scanf("%d%d%d", &N, &L, &U);
    for(int i=1; i<=N; i++) scanf("%d", &A[i]);
}

inline int h(int x) { return x%MOD; }

int find(int x) {
    int i = h(x);
    for(int j=0; j<H[i].size(); j++)
        if( H[i][j].first==x ) return H[i][j].second;
    return 0;
}

void add(int x, int v) {
    int i = h(x);
    H[i].push_back( make_pair(x,v) );
}

void solve()
{
    //normalizare
    int nr = 1, r;
    for(int i=1; i<=N; i++) {
        r = find(A[i]);
        if( !r ) {
            no[i] = nr;
            add( A[i], nr ); nr++;
        }
        else no[i] = r;
    }

    for(int i=1; i<=N; i++) printf("%d ", no[i]);
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

#include<stdio.h>
#include<algorithm>
#include<vector>
#define inf "heavymetal.in"
#define outf "heavymetal.out"
#define NMax 100001
#define MOD 666013
using namespace std;

int N, tmax;
int best[NMax], aux[2*NMax], m;
vector< pair<int,int> > H[MOD];

struct interval {
    int A, B;
} V[NMax];

void read()
{
    scanf("%d", &N);
    for(int i=1; i<=N; i++) {
        scanf("%d%d", &V[i].A, &V[i].B);
        aux[++m] = V[i].A; aux[++m] = V[i].B;
    }
}

inline int h(int x) { return x%MOD; }

void add(int x, int v) {
    int k = h(x);
    H[k].push_back( make_pair(x, v) );
}

int find(int x) {
    int k = h(x);
    for(int i=0; i<H[k].size(); ++i)
        if( H[k][i].first==x ) return H[k][i].second;
    return 0;
}

struct cmp {
    bool operator () (const interval &a, const interval &b) {
        return a.B<b.B;
    }
};

inline int max(int a, int b) { return a>b ? a : b; }

void solve()
{
    //normalizare
    sort( aux+1, aux+m+1 );
    int nr = 1; add(aux[1], 1);
    for(int i=2; i<=m; i++)
        if( aux[i]!=aux[i-1] ) add(aux[i], ++nr);
    //normalizare

    sort( V+1, V+N+1, cmp() ); int j = 1;
    for(int i=1; i<=nr; i++) {
        best[i] = best[i-1];
        while( find(V[j].B)==i ) {
            best[i] = max(best[i], V[j].B-V[j].A + best[find(V[j].A)]);
            j++;
        }
    }

    printf("%d", best[nr]);
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

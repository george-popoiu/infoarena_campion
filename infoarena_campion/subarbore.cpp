#include<stdio.h>
#include<algorithm>
#define inf "subarbore.in"
#define outf "subarbore.out"
#define NMax 41
#define MMax 421
using namespace std;

int N, M, cost;
int T[NMax], H[NMax];

struct muchie {
    int a, b, c;
} L[MMax];

void read()
{
    scanf("%d%d", &N, &M);
    for(int i=1; i<=M; i++) {
        scanf("%d%d%d", &L[i].a, &L[i].b, &L[i].c);
    }
}

struct cmp {
    bool operator () (const muchie &m1, const muchie &m2) {
        return m1.c<m2.c;
    }
};

int Root(int u) {
    while( T[u] ) u = T[u];
    return u;
}

void Unite(int u, int v) {
    if( H[u]==H[v] ) {
        T[v] = u;
        H[u]++; return;
    }
    if( H[v]<H[u] ) {
        T[v] = u;
        return;
    }
    T[u] = v;
}

void solve()
{
    sort( L+1, L+M+1, cmp() );

    int k = 0, i = 1, u, v;
    while( k<N-1 ) {
        while( ( u = Root(L[i].a) ) == ( v = Root(L[i].b) ) ) i++;
        cost += L[i].c;
        Unite(u, v);
        k++;
    }

    printf("%d", cost);
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

//O(N log^2 N )
#include<stdio.h>
#define inf "sir.in"
#define outf "sir.out"
#define NMax 100001
#define DMax 300000
#define INF 0x3f3f3f3f
using namespace std;

int N, X, Y, Z;
int V[NMax];
int start, end, rm, rM;

struct elem {
    int m, M;
} A[DMax];

void read()
{
    scanf("%d%d%d%d", &N, &X, &Y, &Z);
    for(int i=1; i<=N; i++) scanf("%d", &V[i]);
}

inline int min(int a, int b) { return a<b ? a : b; }

inline int max(int a, int b) { return a>b ? a : b; }

void build(int n, int left, int right) {
    if( left==right ) {
        A[n].m = A[n].M = V[left];
        return;
    }

    int m = (left+right)>>1;
    build(n<<1, left, m);
    build(n<<1 | 1, m+1, right);

    A[n].m = min( A[n<<1].m, A[n<<1 | 1].m );
    A[n].M = max( A[n<<1].M, A[n<<1 | 1].M );
}

void query(int n, int left, int right) { //start, end => rm, rM
    if( left>=start && right<=end ) {
        rm = min(rm, A[n].m);
        rM = max(rM, A[n].M);
        return;
    }

    int m = (left+right)>>1;
    if( m>=start ) query(n<<1, left, m);
    if( m<end ) query(n<<1 | 1, m+1, right);
}

void solve()
{
    build(1, 1, N);

    int m, l = X, r = Y, sol = -1, st, g;
    while( l<=r ) {
        m = (l+r)>>1;
        g = 0;
        for(int i=1; i+m-1<=N; i++) {
            rm = INF; rM = -INF;
            start = i; end = i+m-1;
            query(1, 1, N);
            if( rM-rm<=Z && m>=sol ) {
                sol = m, st = i;
                g = 1;
            }
        }
        if(g) l=m+1;
        else r = m-1;
    }

    sol == -1 ? printf("-1") : printf("%d %d %d", sol, st, st+sol-1);
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

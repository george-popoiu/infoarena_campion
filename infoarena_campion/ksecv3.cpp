#include<stdio.h>
#include<algorithm>
#define inf "ksecv.in"
#define outf "ksecv.out"
#define NMax 100001
using namespace std;

struct elem {
    int val, ind;
} A[NMax];

int N, K, AIB[NMax], aux[NMax];
int sol, start, end, v;

void read()
{
    scanf("%d%d", &N, &K);
    for(int i=1; i<=N; i++) {
        scanf("%d", &A[i].val);
        A[i].ind = i;
        aux[i] = A[i].val;
    }
}

struct cmp {
    bool operator () (const elem &a, const elem &b) {
        if( a.val<b.val ) return true;
        if( a.val==b.val ) return a.ind>b.ind;
        return false;
    }
};

inline int bit(int x) { return x & -x; }

void update(int x) {
    for(int i=x; i<=N; i+=bit(i)) AIB[i]++;
}

int query(int l, int r) {
    int rez = 0;
    while( l<=r ) {
        if( r-bit(r)+1>=r ) rez += AIB[r], r-=bit(r);
        else {
            if( aux[r]>=v ) rez++;
            r--;
        }
    }
    return rez;
}

void solve()
{
    sort( A+1, A+N+1, cmp() );
    for(int i=N; i>=1; i--) {
        int st = A[i].ind+1, sf = N, m, q;
        while( st<=sf ) {
            m = (st+sf)>>1;
            v = A[i].val; q = query( A[i].ind+1, m );

            //printf("i=%d c=%d m=%d q=%d\n", i, A[i].ind+1, m, q);

            if( q<=K ) {
                st = m+1;
                if( m-A[i].ind+1>sol ) {
                    sol = m-A[i].ind+1;
                    start = A[i].ind;
                    end = m;
                }
                else if( m-A[i].ind+1==sol && A[i].ind<start ) {
                    start = A[i].ind;
                    end = m;
                }
            }
            else sf = m-1;
        }
        update( A[i].ind );
    }

    printf("%d %d", start, end);
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

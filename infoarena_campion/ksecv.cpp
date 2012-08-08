#include<stdio.h>
#include<algorithm>
#include<string.h>
#define inf "ksecv.in"
#define outf "ksecv.out"
#define NMax 100010
using namespace std;

struct elem {
    int value, ind;
} V[NMax];

int N, K, A[NMax], m[NMax];
int AIB[NMax];

void read()
{
    scanf("%d%d", &N, &K);
    for(int i=1; i<=N; i++) {
        scanf("%d", &V[i].value);
        A[i] = V[i].value;
        V[i].ind = i;
    }
}

struct cmp {
    bool operator () (const elem &a, const elem &b) {
        if( a.value < b.value ) return true;
        if( a.value==b.value ) {
            if( a.ind > b.ind ) return true;
            return false;
        }
        return false;
    }
};

inline int lsb(int x) { return ( x & -x ); }

int query2(int l, int r) {
    int rez = 0;
    while( l<=r ) {
        if( r-lsb(r)+1>=l ) {
            rez += AIB[r];
            r -= lsb(r);
        }
        else {
            if( r >= l ) rez++;
            r--;
        }
    }
    return rez;
}

int query(int x) {
    int rez = 0;
    for(int i=x; i>=1; i-=lsb(i)) rez += AIB[i];
    return rez;
}

void update(int x, int val) {
    for(int i=x; i<=N; i+=lsb(i)) AIB[i] += val;
}

void solve()
{
    sort( V+1, V+N+1, cmp() );
    for(int i=N; i>=1; i--) {
        m[ V[i].ind ] = query(N) - query( V[i].ind-1 );
        update( V[i].ind, 1 );
    }


    int st = 1, dr = N, mij, r = 0, rs, rd, gasit;
    /*while( st<=dr ) {
        mij = (st+dr)>>1;
    }*/

    printf("%d %d", rs, rd);
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

#include<stdio.h>
#include<algorithm>
#include<stack>
#define inf "scmax.in"
#define outf "scmax.out"
#define NMax 100001
using namespace std;

int N, A[NMax], u[NMax], n[NMax];
int AIB[NMax], b[NMax], best[NMax];

void read()
{
    scanf("%d", &N);
    for(int i=1; i<=N; ++i) {
        scanf("%d", &A[i]);
        n[i] = u[i] = A[i];
    }
}

inline int lsb(int x) { return ( x & -x ); }

int query(int x) {
    int rez = 0;
    for(int i=x; i>=1; i-=lsb(x))
        if( best[ AIB[i] ] > best[rez] ) rez = AIB[i];
    return rez;
}

void update(int x, int ind) {
    for(int i=x; i<=N; i+=lsb(i))
        if( best[AIB[i]] < best[ind] ) AIB[i] = ind;
}

void solve()
{
    sort(u+1, u+N+1);

    int h = 1;
    for(int i=2; i<=N; ++i)
        if( u[i]!=u[h] ) u[++h] = u[i];

    for(int i=1; i<=N; i++) n[i] = lower_bound( u+1, u+h+1, n[i] ) - u;

    for(int i=1; i<=N; ++i) {
        b[i] = query( n[i]-1 );
        best[i] = best[b[i]] + 1;
        update(n[i], i);
    }

    int rez = 1;
    for(int i=2; i<=N; ++i)
        if( best[i]>best[rez] ) rez = i;

    printf("%d\n", best[rez]);

    h = 0;
    while( rez ) {
        u[++h] = A[rez];
        rez = b[rez];
    }

    for(int i=h; i>=1; i--) printf("%d ", u[i]);
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

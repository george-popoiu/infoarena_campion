#include<stdio.h>
#include<algorithm>
#define inf "euro2.in"
#define outf "euro2.out"
#define NMax 10001
using namespace std;

int N, c[NMax], d[NMax];
float A[NMax], a[NMax];
int n[NMax], AIBC[NMax], AIBD[NMax];

void read()
{
    scanf("%d", &N);
    for(int i=1; i<=N; i++) {
        scanf("%f", &A[i]);
        a[i] = A[i];
    }
}

inline int lsb(int x) { return (x & -x); }

int queryC(int x) {
    int rez = 0;
    for(int i=x; i>=1; i-=lsb(i))
        if( c[ AIBC[i] ] > c[rez] ) rez = AIBC[i];
    return rez;
}

void updateC(int x, int ind) {
    for(int i=x; i<=N; i+=lsb(i))
        if( c[AIBC[i]]<c[ind] ) AIBC[i] = ind;
}

int queryD(int x) {
    int rez = 0;
    for(int i=x; i>=1; i-=lsb(i))
        if( d[ AIBD[i] ] > d[rez] ) rez = AIBD[i];
    return rez;
}

void updateD(int x, int ind) {
    for(int i=x; i<=N; i+=lsb(i))
        if( d[ AIBD[i] ] < d[ind] ) AIBD[i] = ind;
}

void solve()
{
    sort(a+1, a+N+1);
    for(int i=1; i<=N; i++) n[i] = lower_bound( a+1, a+N+1, A[i] ) - a;

    for(int i=1; i<=N; i++) {
        c[i] = 1;
        int q = queryC(n[i]-1);
        if( c[i]<c[q]+1 ) c[i] = c[q]+1;
        updateC( n[i], i );
    }
    for(int i=N; i>=1; i--) {
        d[i] = 1;
        int q = queryD(n[i]-1);
        if( d[i] < d[q]+1 ) d[i] = d[q] + 1;
        updateD( n[i], i );
    }

    int sol = 0;
    for(int i=1; i<=N; i++)
        if( c[i]>1 && d[i]>1 && c[i]+d[i]-1>sol ) sol = c[i]+d[i]-1;

    printf("%d", sol);
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

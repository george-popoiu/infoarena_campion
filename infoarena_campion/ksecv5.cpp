#include<stdio.h>
#include<algorithm>
#define inf "ksecv.in"
#define outf "ksecv.out"
#define NMax 100001
using namespace std;

int N, K;
int AIB[NMax], A[NMax], un[NMax], aux[NMax];

void read()
{
    scanf("%d%d", &N, &K);
    for(int i=1; i<=N; i++) {
        scanf("%d", &A[i]);
        aux[i] = A[i];
    }
}

inline int bit(int x) { return x & -x; }

void update(int x) {
    for(int i=x; i<=N; i+=bit(i)) AIB[i]++;
}

int que(int x) {
    int rez = 0;
    for(int i=x; i>=1; i-=bit(i)) rez += AIB[i];
    return rez;
}

void solve()
{
    sort( aux+1, aux+N+1 );

    un[1] = aux[1]; int nr = 1;
    for(int i=2; i<=N; i++)
        if( aux[i]!=aux[i-1] ) un[++nr] = aux[i];

    for(int i=1; i<=N; i++) A[i] = lower_bound(un+1, un+nr+1, A[i]) - un;

    int k = 0, j = 0;
    for(int i=1; i<=N; i++) {
        if( A[i]>A[1] ) {
            k++;
            if(k==K+1) break;
            update(A[i]);
        }
        j = i;
    }

    int sol = j, st = 1, dr = j, x = A[1];
    for(int i=2; i<=N && j<N; i++) {
        if( A[i]<=x ) continue;
        x = A[i];
        k = que(N)-que(x);
        //printf("%d %d\n", x, k);
        while( k<=K && j<N ) {
            j++;
            if( A[j]>A[i] ) {
                if( k==K ) {j--; break;}
                update(A[j]); k++;
            }
            if( j-i+1>sol ) sol = j-i+1, st = i;
            else if( j-i+1==sol && i<st ) st = i;
        }
    }

    printf("%d %d", st, st+sol-1);
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

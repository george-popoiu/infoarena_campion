#include<stdio.h>
#include<vector>
#define inf "sume2.in"
#define outf "sume2.out"
#define NMax 50010
#define Dim 1050000
#define ll long long
#define MOD 666013
using namespace std;

ll K;
int N, A[NMax], cnt[Dim], Max;
vector<int> H[MOD];

inline int hash(int x) { return x%MOD; }

void add(int x) {
    int k = hash(x);
    H[k].push_back(x);
}

int is_in(int x) {
    int k = hash(x);
    for(int i=0; i<H[k].size(); i++)
        if( H[k][i]==x ) return 1;
    return 0;
}

int get(int x) {
    int k = hash(x), rez = 0;
    for(int i=0; i<H[k].size(); i++)
        if( H[k][i]==x ) rez++;
    return rez;
}

void read()
{
    scanf("%d %lld", &N, &K);
    for(int i=1; i<=N; i++) {
        scanf("%d", &A[i]);
        add(A[i]);
        if( A[i]>Max ) Max = A[i];
    }
}

int bs(int st, int dr) {
    int m; ll lower, upper;
    while( st<=dr ) {
        m = (st+dr)>>1;
        lower = upper = 0LL;
        for(int i=1; i<=N; i++) {
            if( A[i]>m ) continue;
            if( m-A[i]>Max ) {
                upper += (1LL * cnt[Max]);
                if(Max-1) lower += (1LL * cnt[Max]);
            }
            else {
                upper += (1LL * cnt[m-A[i]]);
                if(m-A[i]-1) lower += (1LL * cnt[m-A[i]-1]);
            }
        }
        //printf("%d - %d - %d => %lld\n", st, m, dr, rez);
        if( lower<K && K<=upper ) return m;
        else if( lower>=K || (upper>K && lower==K) ) dr = m-1;
        else if( upper<K ) st = m+1;
    }
    return 0;
}

void solve()
{
    if( is_in(0) ) cnt[0]++;
    for(int i=1; i<=Max; i++) {
        if( is_in(i) ) cnt[i] = get(i) + cnt[i-1];
        else cnt[i] = cnt[i-1];
    }

    /*for(int i=0; i<=Max; i++) printf("%d ", cnt[i]);
    printf("\n");*/

    /*int rez = bs(0, 2*Max);
    while( !rez ) { K++; rez = bs(0, 2*Max); }*/

    printf("%d", bs(0, 2*Max));
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

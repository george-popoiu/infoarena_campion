#include<stdio.h>
#include<set>
#include<algorithm>
#define inf "planificare.in"
#define outf "planificare.out"
#define NMax 100001
#define tit multiset<int>::iterator
using namespace std;

struct program {
    int start, stop;
} A[NMax];

int N, K;
multiset<int> T;
tit it;

void read()
{
    scanf("%d%d", &N, &K);
    for(int i=1; i<=N; i++) scanf("%d%d", &A[i].start, &A[i].stop);
}

struct cmp {
    bool operator () (const program &a, const program &b) {
        return a.stop<b.stop;
    }
};

void solve()
{
    sort( A+1, A+N+1, cmp() );

    int rez = 0;
    for(int i=1; i<=N; i++) {
        if( !T.size() ) {
            rez++; T.insert( A[i].stop );
            continue;
        }

        it = T.lower_bound( A[i].start+1 );

        if( it!=T.begin() ) {
            it--; rez++;
            T.erase(it); T.insert( A[i].stop );
        }
        else if( T.size()<K ) {
            T.insert( A[i].stop );
            rez++;
        }
    }

    printf("%d", rez);
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

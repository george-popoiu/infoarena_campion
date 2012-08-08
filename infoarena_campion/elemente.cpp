#include<stdio.h>
#include<algorithm>
#include<deque>
#define inf "elemente.in"
#define outf "elemente.out"
#define NMax 100010
#define MOD 1000003
using namespace std;

int N, K;
int A[NMax], best[NMax];
deque<int> q;

void read()
{
    scanf("%d%d", &N, &K);
    for(int i=1; i<=N; i++) scanf("%d", &A[i]);
}

int putlog(int e) {
    if( e==0 ) return 1;
    if( e%2 ) return (2* putlog(e-1) )%MOD;
    else {
        int p = putlog(e/2);
        return (1LL*p*p)%MOD;
    }
}

void solve()
{
    sort(A+1, A+N+1);

    best[1] = 1; q.push_back(1);
    for(int i=2; i<=N; i++) {
        while( !q.empty() && A[i]-A[q.front()]>K ) q.pop_front();
        q.push_back(i);
        best[i] = ( best[i-1] + putlog(i-q.front()) )%MOD;
    }

    printf("%d", best[N]);
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

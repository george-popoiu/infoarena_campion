#include<stdio.h>
#include<deque>
#define inf "sum2.in"
#define outf "sum2.out"
#define NMax 100002
#define INF 0x3f3f3f3f
using namespace std;

int N, U, L, A[NMax], s[NMax];
deque<int> q;

void read()
{
    scanf("%d%d%d", &N, &L, &U);
    for(int i=1; i<=N; i++) {
        scanf("%d", &A[i]);
        s[i] = A[i]+s[i-1];
    }
}

void solve()
{
    int sol = -INF;
    for(int i=L; i<=N; i++) {
        while( !q.empty() && s[q.back()]>s[i-L-1] ) q.pop_back();
        q.push_back( i-L==0 ? 0 : i-L-1 );

        if( s[i]-s[q.front()]>sol ) {
            sol = s[i]-s[q.front()];
        }

        while( !q.empty() && i-q.front()==U ) q.pop_front();
    }

    printf("%d", sol);
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

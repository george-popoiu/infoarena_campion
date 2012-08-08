//O(N logN )
#include<stdio.h>
#include<deque>
#define inf "sir.in"
#define outf "sir.out"
#define NMax 100001
using namespace std;

int N, X, Y, Z;
int A[NMax];
deque<int> q, q2;

void read()
{
    scanf("%d%d%d%d", &N, &X, &Y, &Z);
    for(int i=1; i<=N; i++) scanf("%d", &A[i]);
}

void solve()
{
    int sol = -1, st;
    int m, l = X, r = Y, g;
    while( l<=r ) {
        m = (l+r)>>1; g = 0;
        q.clear(); q2.clear();
        for(int i=1; i<=N; i++) {
            while( !q.empty() && A[i]<A[q.back()] ) q.pop_back(); //min
            q.push_back(i);
            while( !q2.empty() && A[i]>A[q2.back()] ) q2.pop_back(); //max
            q2.push_back(i);
            if( i<m ) continue;
            if( A[q2.front()]-A[q.front()]<=Z && m>=sol ) {
                sol = m; st = i-m+1;
                g = 1;
            }
            while( i-q.front()+1==m ) q.pop_front();
            while( i-q2.front()+1==m ) q2.pop_front();
        }
        if(g) l = m+1;
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

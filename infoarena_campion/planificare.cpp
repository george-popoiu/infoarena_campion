#include<stdio.h>
#include<algorithm>
#include<deque>
#define inf "planificare.in"
#define outf "planificare.out"
#define NMax 100010
#define KMax 100010
using namespace std;

struct part {
    int start, stop;
} A[NMax];

int N, K;
deque<int> q;

void read()
{
    scanf("%d%d", &N, &K);
    for(int i=1; i<=N; i++) scanf("%d%d", &A[i].start, &A[i].stop);
}

struct cmp {
    bool operator () (const part &a, const part &b) {
        return a.stop<b.stop;
    }
};

void solve()
{
    sort( A+1, A+N+1, cmp() );
    if( K==1 ) {
        int rez = 1, j = 1;
        for(int i=2; i<=N; i++)
            if( A[i].start >= A[j].stop ) {
                rez++;
                j = i;
            }
        printf("%d", rez);
        return;
    }

    q.push_back(1); int rez = 1;
    for(int i=2; i<=N; i++) {
        while( !q.empty() && A[i].start>=A[q.front()].stop ) q.pop_front();
        if( q.size()==K ) continue;
        q.push_back(i); rez++;
    }

    printf("%d", rez);
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

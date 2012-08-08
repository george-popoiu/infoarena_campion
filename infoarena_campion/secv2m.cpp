#include<stdio.h>
#include<deque>
#define inf "secv2m.in"
#define outf "secv2m.out"
#define DMax 2001
using namespace std;

const long long INF  = 1LL << 26;

int N, M, L;
int A[DMax], B[DMax];
int sol = INF, stA, stB;

deque<int> q;

void read()
{
    scanf("%d%d%d", &N, &M, &L);
    for(int i=1; i<=N; i++) scanf("%d", &A[i]);
    for(int i=1; i<=M; i++) scanf("%d", &B[i]);
}

inline int min(int a, int b) { return ( a<b ? a : b ); }

void solve()
{
    int stop = 1;
    for(int i=N-L+1; i>=1; i--) {
        if( i==1 ) stop = M-L+1;
        for(int j=1; j<=stop; j++) {
            //printf("%d %d\n", i, j);
            q.clear();
            for(int k=i; k<=min(N,i+M-j); k++) {
                //printf("%d ", A[k]+B[j+k-i]);
                while( !q.empty() && A[k]+B[j+k-i] > A[q.back()]+B[j+q.back()-i] ) q.pop_back();
                q.push_back(k);
                if(k-i+1>=L) {
                    if( A[q.front()]+B[j+q.front()-i]<sol ) {
                        sol = A[q.front()]+B[j+q.front()-i];
                        stA = k-L+1; stB = j+k-i-L+1;
                    }
                    else if( A[q.front()]+B[j+q.front()-i]==sol ) {
                        if( k-L+1<stA ) {
                            stA = k-L+1;
                            stB = j+k-i-L+1;
                        }
                        else if( k-L+1==stA && j+k-i-L+1<stB ) stB = j+k-i-L+1;
                    }
                    while( k-q.front()+1==L ) q.pop_front();
                }
            }
            //printf("\n");
        }
    }
    printf("%d\n%d %d", sol, stA, stB);
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

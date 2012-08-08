#include<stdio.h>
#include<deque>
#include<math.h>
#define inf "secv4.in"
#define outf "secv4.out"
#define NMax 100001
#define INF 0x3f3f3f3f
using namespace std;

int N, X, Y, semn[NMax];
double A[NMax], S[NMax];
deque<int> q, q2;

inline double mod(double x) { return x<0 ? -x : x ; }

void read()
{
    scanf("%d%d%d", &N, &X, &Y); semn[0] = 1;
    for(int i=1; i<=N; i++) {
        scanf("%lf", &A[i]);
        S[i] = log10( mod(A[i]) ) + S[i-1];
        if( A[i]<0 ) semn[i] = (-1)*semn[i-1];
        else semn[i] = semn[i-1];
    }

}

void solve()
{
    int len = 0, st = 0;
    double sol = -INF;

    /*for(int i=1; i<=N; i++) printf("%lf ", S[i]);
    printf("\n");

    for(int i=1; i<=N; i++) printf("%d ", semn[i]);
    printf("\n");*/

    for(int i=X; i<=N; i++) {
        if( semn[i-X]==1 ) {
            while( !q.empty() && S[q.back()]>S[i-X] ) q.pop_back();
            q.push_back(i-X);
        }
        else {
            while( !q2.empty() && S[q2.back()]>S[i-X] ) q2.pop_back();
            q2.push_back(i-X);
        }

        if( semn[i]==1 ) {
            if( q.empty() ) continue;
            if( S[i]-S[q.front()]>sol ) sol = S[i]-S[q.front()], len = i-q.front(), st = q.front()+1;
            else if( S[i]-S[q.front()]==sol ) {
                if( q.front()+len < st+len-1 ) len = i-q.front(), st = q.front()+1;
                else if( q.front()+len == st+len-1 && q.front()+1<st ) st = q.front()+1;
            }
        }
        else {
            if( q2.empty() ) continue;
            if( S[i]-S[q2.front()]>sol ) sol = S[i]-S[q2.front()], len = i-q2.front(), st = q2.front()+1;
            else if( S[i]-S[q2.front()]==sol ) {
                if( q2.front()+len < st+len-1 ) len = i-q2.front(), st = q2.front()+1;
                else if( q2.front()+len == st+len-1 && q2.front()+1<st ) st = q2.front()+1;
            }
        }
        while( !q.empty() && i-q.front()==Y ) q.pop_front();
        while( !q2.empty() && i-q2.front()==Y ) q2.pop_front();
    }


    printf("%d %d", len, st);
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

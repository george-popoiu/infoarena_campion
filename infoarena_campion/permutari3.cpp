#include<stdio.h>
#define inf "perm3.in"
#define outf "perm3.out"
#define Dim 1000
#define NMax 1010
using namespace std;

typedef int BIG[Dim];

BIG fact[NMax];

int N, M[NMax], P[NMax], uz[NMax];

void read()
{
    scanf("%d", &N);
    for(int i=1; i<=N; i++) scanf("%d", &M[i]);
    for(int i=1; i<=N; i++) scanf("%d", &P[i]);
}

void mul(BIG C, BIG A, int B) {
    int i, t = 0;
    for(i = 1; i<=A[0] || t; i++, t /= 10)
        C[i] = (t += (A[i] * B)) % 10;
    C[0] = i - 1;
}

void sum(BIG C, BIG A, BIG B) {
    int i, t = 0;
    for(i=1; i<=A[0] || i<=B[0] || t; i++, t/=10)
        C[i] = (t += (A[i]+B[i])) % 10;
    C[0] = i - 1;
}

void solve()
{
    fact[0][0] = 1; fact[0][1] = 0; fact[1][0] = 1; fact[1][1] = 1;
    for(int i=2; i<=NMax-10; i++) mul( fact[i], fact[i-1], i );

    BIG sol;
    for(int i=1; i<N; i++)
        for(int j=1; j<=N; j++) {
            if( P[i]>M[j] && !uz[j]) sum(sol, sol, fact[N-i]);
            else if( P[i]==M[j] ) uz[j] = 1;
        }

    BIG nr; nr[0] = 1; nr[1] = 1; sum( sol, sol, nr );
    for(int i = sol[0]; i>=1; i--) printf("%d", sol[i]);
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

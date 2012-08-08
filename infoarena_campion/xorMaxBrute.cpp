#include<stdio.h>
#define inf "xormax.in"
#define outf "xormax.out"
#define NMax 100010
using namespace std;

int N, A[NMax], S[NMax];

void read()
{
    scanf("%d", &N);
    for(int i=1; i<=N; i++) {
        scanf("%d", &A[i]);
        S[i] = (A[i]^S[i-1]);
    }
}

void solve()
{
    int sol = -1, start = 0, end = 0;
    for(int i=1; i<=N; i++)
        for(int j=0; j<i; j++)
            if( (S[j]^S[i])>=sol ) {
                sol = (S[j]^S[i]);
                start = j+1; end = i;
            }
    printf("%d %d %d", sol, start, end);
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

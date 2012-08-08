#include<stdio.h>
#include<vector>
#include<bitset>
#include<algorithm>
#define inf "economie.in"
#define outf "economie.out"
#define NMax 1001
#define VMax 50001
using namespace std;

int N, A[NMax];
bitset<VMax> s;
vector<int> sol;

void read()
{
    scanf("%d", &N);
    for(int i=1; i<=N; i++) scanf("%d", &A[i]);
}

void solve()
{
    sort( A+1, A+N+1 );

    s[0] = 1;
    for(int i=1; i<=N; i++) {
        if( !s[ A[i] ] ) sol.push_back( A[i] );
        for(int j=0; j<=A[N]-A[i]; j++)
            if( s[j] ) s[ j+A[i] ] = 1;
    }

    printf("%d\n", sol.size());
    for(int i=0; i<sol.size(); i++) printf("%d\n", sol[i]);
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

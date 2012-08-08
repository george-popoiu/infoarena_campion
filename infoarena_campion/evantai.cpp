#include<stdio.h>
#define inf "evantai.in"
#define outf "evantai.out"
#define NMax 710
#define MOD 30103
#define Max 2100
using namespace std;

int N, A[NMax];
int AIB[NMax][Max]; //query(j,val) - nr de val A[i]+A[k]<=val cu k = 1,..,j

void read()
{
    scanf("%d", &N);
    for(int i=1; i<=N; i++) scanf("%d", &A[i]);
}

inline int lsb(int x) { return ( x & -x ); }

void update(int k, int s, int val) {
    for(int i=k; i<=N; i += lsb(i))
        for(int j=s; j<=Max-100; j += lsb(j)) {
            AIB[i][j] += val;
            if( AIB[i][j]>=MOD ) AIB[i][j] -= MOD;
        }
}

int query(int k, int val) {
    int rez = 0;
    for(int i=k; i>=1; i -= lsb(i))
        for(int j=val; j>=1; j -= lsb(j)) {
            rez += AIB[i][j];
            if( rez>=MOD ) rez -= MOD;
        }
    return rez;
}

void solve()
{
    int sol = 0, rez;
    int B[NMax][NMax];

    for(int i=N-1; i>=1; i--) {
        for(int j=i+1; j<=N; j++) {
            B[i][j] = 1 + query(j-1, A[i]+A[j]-1);
            sol += B[i][j];
            if( sol>=MOD ) sol -= MOD;
        }
        for(int j=i+1; j<=N; j++) update(j, A[i]+A[j], B[i][j]);
    }

    printf("%d", sol);
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

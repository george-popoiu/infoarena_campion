#include<stdio.h>
#include<algorithm>
#include<vector>
#define inf "timbre.in"
#define outf "timbre.out"
#define MMax 10001
using namespace std;

int N, M, K;
int H[MMax], hdim;

struct interval {
    int m, c;
} I[MMax];

struct cmp {
    bool operator () (const interval &a, const interval &b) {
        return a.m > b.m;
    }
};

void read()
{
    scanf("%d%d%d", &N, &M, &K);
    for(int i=1; i<=M; i++) scanf("%d%d", &I[i].m, &I[i].c);
}

void downheap(int n) {
    int s;
    while( n<hdim ) {
        s = (n<<1);
        if( s<=hdim ) {
            if( s+1<=hdim && I[ H[s+1] ].c < I[ H[s] ].c ) s++;
            if( I[ H[n] ].c > I[ H[s] ].c ) {
                swap( H[n], H[s] );
                n = s;
            }
            else return;
        }
        else return;
    }
}

void upheap(int n) {
    int f;
    while( n>1 ) {
        f = (n>>1);
        if( I[ H[n] ].c < I[ H[f] ].c ) {
            swap( H[n], H[f] );
            n = f;
        }
        else return;
    }
}

void solve()
{
    sort( I+1, I+M+1, cmp() );

    int sol = 0, i = 1;
    for(int j = N; j>0; j-=K) {
        for(; I[i].m>=j && i<=M; i++) {
            hdim++; H[hdim] = i;
            upheap(hdim);
        }
        sol += I[ H[1] ].c;
        H[1] = H[hdim--]; downheap(1);
    }

    printf("%d", sol);
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

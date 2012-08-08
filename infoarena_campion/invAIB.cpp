#include<stdio.h>
#include<algorithm>
#define inf "inv.in"
#define outf "inv.out"
#define NMax 100010
#define MOD 9917
using namespace std;

struct elem {
    int value;
    int ind; //indicele in sirul initial
} A[NMax];

int N;

void read()
{
    scanf("%d", &N);
    for(int i=1; i<=N; i++) {
        scanf("%d", &A[i].value);
        A[i].ind = i;
    }
}

struct cmp { //sortez in functie de valoare, si in caz de egalitate in functie de indicele din sirul initial
    bool operator () (const elem &a, const elem &b) {
        if( a.value<b.value ) return true;
        else if( a.value==b.value ) {
            if( a.ind < b.ind ) return true;
            return false;
        }
        return false;
    }
};

int C[NMax];

inline int lsb(int x) { return ( x & -x ); }

int query(int x) {
    int rez = 0;
    for(int i=x; i>=1; i-=lsb(i)) {
        rez += C[i];
        rez %= MOD;
    }
    return rez;
}

void update(int x, int val) {
    for(int i=x; i<=N; i+=lsb(i)) C[i] += val;
}

void solve()
{
    sort(A+1, A+N+1, cmp());

    int rez = 0;
    for(int i=1; i<=N; i++) {
        rez += (query( N ) - query( A[i].ind ));
        update(A[i].ind, 1);
        if( rez>=MOD ) rez -= MOD;
        if( rez<0 ) rez += MOD;
    }

    printf("%d", rez);
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

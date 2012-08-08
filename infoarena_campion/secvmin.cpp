#include<stdio.h>
#define inf "secvmin.in"
#define outf "secvmin.out"
#define DMax 1000001
#define NMax 100001
#define INF 0x3f3f3f3f
using namespace std;

int N, M;
int A[NMax], B[NMax], V[NMax], f[DMax];

//la pasul i : V[x] = j <=> cea mai din dreapta pozitie a lui B[1] din A este j a.i in (j...i) sa avem elementele de indici (1...x) din B

void read()
{
    scanf("%d%d", &N, &M);
    for(int i=1; i<=N; i++) scanf("%d", &A[i]);
    for(int i=1; i<=M; i++) {
        scanf("%d", &B[i]);
        f[ B[i] ] = i;
    }
}

inline int min(int a, int b) { return a>b ? a : b; }

void solve()
{
    int sol = -1;
    for(int i=1; i<=N; i++) {
        if( !f[ A[i] ] ) continue;
        int poz = f[ A[i] ];
        if( poz==1 ) V[poz] = i;
        else V[poz] = V[poz-1];
        if( poz==M && i>=M ) {
            //printf("%d %d %d\n", i, V[M], i-V[M]+1);
            sol = min( sol, i-V[M]+1 );
        }
    }

    printf("%d", sol );
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<algorithm>
#define inf "toys.in"
#define outf "toys.out"
#define NMax 2000001
using namespace std;

int N, M, L;
int S, X, Y, Z, V;
int T[NMax];

void read()
{
    scanf("%d%d%d", &N, &L, &M);
    scanf("%d%d%d%d%d", &S, &X, &Y, &Z, &V);
}

int part(int st, int dr) {
    int i = st-1, j = dr+1, p = T[st + rand()%(dr-st+1)];
    while(1) {
        do { i++; } while( T[i]<p );
        do { j--; } while( T[j]>p );
        if( i<j ) swap(T[i], T[j]);
        return j;
    }
}

void qs(int st, int dr, int k) {
    if( st==dr ) return;

    int q = part(st, dr);
    int t = q-st+1;
    if( t>=k ) qs(st, q, k);
    else qs(q+1, dr, k-t);
}

void solve()
{
    int d = S, t = 1;
    for(int i=1; i<=N; i++) {
        if( t ) T[i] = 2*L-d;
        else T[i] = d;
        t = (Z*d + V*i) % 2;
        d = (X*d + Y*i) % (L-1) + 1;
    }

    for(int i=1; i<=N; i++) printf("%d ", T[i]);
    printf("\n");

    srand( time(NULL) );
    qs(1, N, (M-1)%N + 1);
    //nth_element( T+1, T + (M-1)%N + 1, T+N+1 );
    printf("%d\n", T[(M-1)%N + 1]);
    printf("%d\n", T[(M-1)%N + 1] + L + ( (M-1)%N == 0 ? (M-1)/N : (M-1)/N - 1)*2*L);

    for(int i=1; i<M; i++) {
        printf("T[%d] ", i%N==0 ? N : i%N);
        if( i>N ) printf("+ %dL ", i%N==0 ? 2*(i/N)-1 : 2*i/N);
        if( i%N==0 ) printf("\n");
    }
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

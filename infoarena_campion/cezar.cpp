#include<stdio.h>
#define inf "cezar.in"
#define outf "cezar.out"
#define NMax 10001
using namespace std;

struct nod {
    short info;
    nod *next;
} *A[NMax];

short N, d[NMax], H[NMax], K, hdim;

inline void add(short a, short b) {
    nod *p = new nod;
    p->info = b; p->next = A[a];
    A[a] = p;
}

void rem(short a, short b) {
    if( A[a]->info == b ) {
        nod *c = A[a];
        A[a] = A[a]->next;
        delete c;
        return;
    }

    nod *c = A[a];
    while( c->next->info != b ) c = c->next;
    nod *r = c->next;
    c->next = r->next;
    delete r;
}

void read()
{
    scanf("%hd%hd", &N, &K);

    short a, b;
    for(short i=1; i<=N; i++) {
        scanf("%hd%hd", &a, &b);
        add(a, b); add(b, a);
    }
}

void upheap(short u) {
    short f;
    while( u>1 ) {
        f = u>>1;
        if( d[ H[f] ] > d[ H[u] ] ) {
            short aux = H[f]; H[f] = H[u]; H[u] = aux;
            u = f;
        }
        else return;
    }
}

void downheap(short u) {
    short s;
    while( u<=hdim ) {
        s = u<<1;
        if( s>hdim ) return;
        if( s+1<=hdim && d[ H[s] ] > d[ H[s+1] ] ) s++;
        if( d[ H[u] ] > d[ H[s] ] ) {
            short aux = H[u]; H[u] = H[s]; H[s] = aux;
            u = s;
        }
        else return;
    }
}

inline void hAdd(short u) {
    H[++hdim] = u;
    upheap(hdim);
}

inline short hExtractMin() {
    short u = H[1];
    H[1] = H[hdim]; hdim--;
    downheap(1);
    return u;
}

void solve()
{
    for(short i=1; i<=N; i++) {
        d[i] = 1;
        if( !A[i]->next ) hAdd(i);
    }

    short rez = 0;

    for(short i=1; i<N-K; i++) {
        short u = hExtractMin();

        short v = A[u]->info;
        //printf("%d += %d\n", v, u);

        d[v] += d[u]; d[u] = 0;

        /*for(int j=1; j<=N; j++) printf("%d ", d[j]);
        printf("\n");*/

        rem(u, v); rem(v, u);
        if( !A[v]->next ) hAdd(v);
    }

    for(short i=1; i<=N; i++) rez += d[i];
    printf("%hd", rez);
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

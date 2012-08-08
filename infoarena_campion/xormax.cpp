#include<stdio.h>
#define inf "xormax.in"
#define outf "xormax.out"
#define NMax 100010
#define INF 0x3f3f3f3f
using namespace std;

int N, A[NMax], S[NMax];
const int bits = 22;

void read()
{
    scanf("%d", &N);
    for(int i=1; i<=N; i++) scanf("%d", &A[i]);
}

struct Trie {
    int ind;
    Trie *st, *dr;

    Trie() {
        ind = 0;
        st = dr = 0;
    }
};

Trie *T = new Trie();

void insert(Trie *nod, int x, int ind) {
    for(int i=bits; i>=0; i--) {
        int bit = (x & (1<<i));
        if( bit ) {
            if( nod->st==0 ) nod->st = new Trie();
            nod = nod->st;
        }
        else {
            if( nod->dr==0 ) nod->dr = new Trie();
            nod = nod->dr;
        }
    }
    nod->ind = ind;
}

int que(Trie *nod, int x) {
    for(int i=bits; i>=0; i--) {
        int bit = (x & (1<<i));
        if( bit ) {
            if( nod->dr!=0 ) nod = nod->dr;
            else nod = nod->st;
        }
        else {
            if( nod->st!=0 ) nod = nod->st;
            else nod = nod->dr;
        }
    }
    return nod->ind;
}

void solve()
{
    for(int i=1; i<=N; i++) S[i] = (A[i]^S[i-1]);

    insert(T, 0, 0);

    int sol = -1, start = 0, stop = 0;
    for(int i=1; i<=N; i++) {
        int p = que(T, S[i]);

        if( sol < (S[p]^S[i]) ) { sol = (S[p]^S[i]); start = p+1; stop = i; }

        insert(T, S[i], i);
    }

    printf("%d %d %d\n", sol, start, stop);
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

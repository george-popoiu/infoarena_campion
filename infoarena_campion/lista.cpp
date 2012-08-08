#include<stdio.h>
#define inf "lista.in"
#define outf "lista.out"
#define NMax 100001
using namespace std;

int N, g[NMax], v[NMax];
int H[NMax], hdim; //min-Heap

void read()
{
    scanf("%d", &N);

    int a;
    for(int i=1; i<N; i++) {
        scanf("%d", &v[i]);
        g[ v[i] ]++;
    }
}

inline void swap(int &a, int &b) { int aux = a; a = b; b = aux; }

void upheap(int n) {
    int f;
    while( n>1 ) {
        f = (n>>1);
        if( H[n]<H[f] ) {
            swap( H[n], H[f] );
            n = f;
        }
        else return;
    }
}

void downheap(int n) {
    int s;
    while( n<hdim ) {
        s = (n<<1);
        if( s<=hdim ) {
            if( s+1<=hdim && H[s+1]<H[s] ) s++;
            if( H[n]>H[s] ) {
                swap( H[n], H[s] );
                n = s;
            }
            else return;
        }
        else return;
    }
}

void solve()
{
    for(int i=1; i<=N; i++)
        if( !g[i] ) {
            hdim++; H[hdim] = i;
            upheap(hdim);
        }

    for(int i=1; i<N; i++) {
        int u = H[1];
        H[1] = H[hdim]; hdim--;
        downheap(1);

        printf("%d %d\n", u, v[i]);
        g[ v[i] ]--;

        if( !g[ v[i] ] ) {
            hdim++; H[hdim] = v[i];
            upheap(hdim);
        }
    }
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

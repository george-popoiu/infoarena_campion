#include<stdio.h>
#define inf "ksecv.in"
#define outf "ksecv.out"
#define NMax 200001
#define KMax 200001
using namespace std;

int N, K, A[NMax];
int H[KMax], hdim;

void read()
{
    scanf("%d%d", &N, &K);
    for(int i=1; i<=N; i++) scanf("%d", &A[i]);
}

void upheap(int n) {
    int f;
    while( n>1 ) {
        f = n>>1;
        if( H[f]>H[n] ) {
            int aux = H[f]; H[f] = H[n]; H[n] = aux;
            n = f;
        }
        else return;
    }
}

void add(int val) {
    H[++hdim] = val;
    upheap(hdim);
}

void downheap(int n) {
    int s;
    while( n<hdim ) {
        s = n<<1;
        if( s+1<=hdim && H[s+1]<H[s] ) s++;
        if( H[n]>H[s] ) {
            int aux = H[n]; H[n] = H[s]; H[s] = aux;
            n = s;
        }
        else return;
    }
}

void extractMin() {
    H[1] = H[hdim--];
    downheap(1);
}

void solve()
{
    int k = 0, j = 1;
    for(int i=2; i<=N; i++) {
        j = i;
        if( A[i]>A[1] ) {
            if(hdim==K) break;
            add(A[i]);
        }
    }

    int x = A[1], sol = j, st = 1;
    for(int i=2; i<=N && j<N; i++) {
        if( A[i]<=x ) continue;

        x = A[i];
        while( hdim && H[1]<=x ) extractMin();

        for(; j<=N; j++ ) {
            if( A[j]>x ) {
                if(hdim==K) { break; }
                add(A[j]);
            }
            if( sol<j-i+1 ) sol = j-i+1, st = i;
        }

        /*while(1) {
            j++;
            if( A[j]>x ) {
                if(hdim==K) { j--; break; }
                add(A[j]);
            }
            if( sol<j-i+1 ) sol = j-i+1, st = i;
            if(j==N) break;
        }*/
    }

    printf("%d %d", st, st+sol-1);
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

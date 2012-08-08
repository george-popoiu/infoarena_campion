#include<stdio.h>
#include<vector>
#define inf "piloti.in"
#define outf "piloti.out"
#define NMax 10001
using namespace std;

int N, H[NMax], hdim;

void upheap(int n) {
    int f;
    while( n>1 ) {
        f = n>>1;
        if( H[n]>H[f] ) {
            swap(H[n], H[f]);
            n = f;
        }
        else return;
    }
}

void downheap(int n) {
    int s;
    while( n<hdim ) {
        s = n<<1;
        if( s<=hdim ) {
            if( s+1<=hdim && H[s+1]>H[s] ) s++;
            if( H[s]>H[n] ) {
                swap(H[s], H[n]);
                n = s;
            }
            else return;
        }
        else return;
    }
}

void solve()
{
    scanf("%d", &N);

    int c, a, rez = 0;
    for(int i=N; i>=1; i--) {
        scanf("%d%d", &c, &a);
        rez += c;
        H[++hdim] = c-a; upheap(hdim);
        if(i%2==0) {
            rez -= H[1];
            H[1] = H[hdim]; hdim--;
            downheap(1);
        }
    }

    printf("%d", rez);
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	solve();
	return 0;
}

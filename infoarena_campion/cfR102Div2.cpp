#include<stdio.h>
#include<cstdlib>
#define inf "test.in"
#define outf "test.out"
using namespace std;

int r1, r2, c1, c2, d1, d2;
int n = 9, m = 4; //combinari de n luate cate m;
int c[5], p[5], uz[5], e, a, b, cc, d;

void read()
{
    scanf("%d%d%d%d%d%d", &r1, &r2, &c1, &c2, &d1, &d2);
}

void afis() {
    for(int i=1; i<5; i++) printf("%d ", c[i]);
    printf("\n");
}

void gen_perm(int k) {
    if( k-1==m ) {
        if( c[p[1]]+c[p[2]]==r1 && c[p[3]]+c[p[4]]==r2 && c[p[1]]+c[p[3]]==c1 && c[p[2]]+c[p[4]]==c2
            && c[p[1]]+c[p[4]]==d1 && c[p[2]]+c[p[3]]==d2 ) {
                printf("%d %d\n%d %d", c[p[1]], c[p[2]], c[p[3]], c[p[4]]);
                exit(0);
            }
    }
    for(int i=1; i<=4; i++)
        if( !uz[i] ) {
            p[k] = i;
            uz[i] = 1;
            gen_perm(k+1);
            uz[i] = 0;
        }
}

void comb(int k) {
    if( k-1==m ) {
        gen_perm(1);
    }
    else
        for(int i=c[k-1]+1; i<=n-m+k; i++) {
            c[k] = i;
            comb(k+1);
        }
}

void solve()
{
    comb(1);
    printf("-1");
}

int main()
{
	//freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

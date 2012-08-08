#include<stdio.h>
#include<string.h>
#define inf "billboards.in"
#define outf "billboards.out"
#define DMax 1001
using namespace std;

int T, W, H;
char *s;
char *c[DMax]; int nrc;

int good(int dim) {
    int w = 0, h = 0;
    int o[DMax+1];

    for(int i=1; i<=nrc; i++) {
        if( strlen(c[i])*dim > W ) return 0;
        o[i] = -1;
    }

    int l = 1;
    for(int i=1; i<=nrc; i++) {
        if( o[l]==-1 ) {
            o[l] = strlen(c[i])*dim;
        }
        else if( o[l]!=-1 ) {
            if( o[l]+dim+strlen(c[i])*dim <= W ) o[l] += dim+strlen(c[i])*dim;
            else {
                l++;
                o[l] = strlen(c[i])*dim;
            }
        }
    }

    if( l*dim>H ) return 0;
    return 1;
}

void solve()
{
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        s = new char[DMax+10];
        scanf("%d %d ", &W, &H);
        gets(s);

        char *p = strtok(s, " "); int i=0;
        while( p!=NULL ) {
            c[++i] = p;
            p = strtok(NULL, " ");
        }
        nrc = i;

        int st = 1, dr = DMax-1, m, rez = 0;
        while( st<=dr ) {
            m = (st+dr)>>1;
            if( good(m) ) {
                rez = m;
                st = m+1;
            }
            else dr = m-1;
        }

        printf("Case #%d: %d\n", t, rez);

        delete s;
    }
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	solve();
	return 0;
}

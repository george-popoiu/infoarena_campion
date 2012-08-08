#include<stdio.h>
#include<algorithm>
#define inf "palmieri.in"
#define outf "palmieri.out"
#define NMax 250001
using namespace std;

int N, A;

struct punct {
    int x, y;
} V[NMax];

void read()
{
    scanf("%d%d", &N, &A);
    for(int i=1; i<=N; i++) scanf("%d%d", &V[i].x, &V[i].y);
}

struct cmp {
    bool operator () (const punct &a, const punct &b) {
        if( a.x<b.x ) return true;
        if( a.x==b.x ) return a.y<b.y;
        return false;
    }
};

inline int min(int a, int b) { return a<b ? a : b; }

inline int max(int a, int b) { return a>b ? a : b; }

inline int mod(int a) { return a<0 ? -a : a; }

void solve()
{
    sort( V+1, V+N+1, cmp() );

    int nrd = 1, maxy = 0, miny = 0;
    punct lp, fp;

    fp = V[1];
    maxy = miny = V[1].y;

    for(int i=2; i<=N; i++) {
        if( mod( mod(V[i].x) - mod(fp.x) ) * ( max(maxy, V[i].y) - min(miny, V[i].y) ) <= A ) {
            maxy = max(maxy, V[i].y);
            miny = min(miny, V[i].y);
        }
        else {
            nrd++;
            fp = V[i];
            maxy = miny = fp.y;
        }
    }

    printf("%d", nrd);
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

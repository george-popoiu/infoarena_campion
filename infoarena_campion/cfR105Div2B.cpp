#include<stdio.h>
//#define inf "test.in"
//#define outf "test.out"
using namespace std;

int vp, vd, t, f, c;
int bij, pp, pd, tp;

int main()
{
	//freopen(inf,"r",stdin); freopen(outf,"w",stdout);

	scanf("%d%d%d%d%d", &vp, &vd, &t, &f, &c);

	for( pp = 0, tp = 0; pp<c; pp += vp, tp++ ) {
	    if( tp<=t ) continue;
	    pd += vd;
	    if( pd>=pp ) {
	        ++bij;
	        pp += ((pd/vd) + f)*vp;
	        tp += ((pd/vd) + f);
	        pd = 0;
	    }
	}

	printf("%d", bij);

	return 0;
}

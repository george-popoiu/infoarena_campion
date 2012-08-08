#include<stdio.h>
#include<math.h>
#define inf "sdmin.in"
#define outf "sdmin.out"
#define NMax 501
#define eps 1e-4
#define eps2 1e-10
#define INF 0x3f3f3f3f
#define norm 100000
using namespace std;

int N;
double Y, xm = INF, xM = -INF;
double rez = INF, X;

struct seg {
    double x1, x2, y;
} v[NMax];

inline double min(double a, double b) { return a<b ? a : b; }

inline double max(double a, double b) { return a>b ? a : b; }

void read()
{
    scanf("%d", &N);
    scanf("%lf", &Y);

    for(int i=1; i<=N; i++) {
        scanf("%lf%lf%lf", &v[i].x1, &v[i].x2, &v[i].y);
        xm = min( xm, v[i].x1 );
        xM = max( xM, v[i].x2 );
    }
}

double dist(double x, int i) {
    double x1 = v[i].x1, x2 = v[i].x2, y = v[i].y;
    if( x>=x1 && x<=x2 ) return fabs(Y-y);
    if( x<x1 ) return sqrt( (x-x1)*(x-x1) + (Y-y)*(Y-y) );
    return sqrt( (x-x2)*(x-x2) + (Y-y)*(Y-y) );
}

void solve()
{
    double d;
    for(double x=xm; x<=xM; x+=eps) {
        d = 0;
        for(int i=1; i<=N; i++) d += dist(x, i);
        if( rez-d>eps2 ) { rez = d; X = x; }
    }

    printf("%.6lf %.6lf", rez, X);
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

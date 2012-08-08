#include<fstream>
#include<math.h>
#include<iomanip>
#define inf "cercuri.in"
#define outf "cercuri.out"
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int T;

inline bool eq(double a, double b)
{
    int x = a*1000, y = b*1000;
    return x==y;
}

void solve(double x0, double y0, double r0, double x1, double y1, double r1)
{
    if( r0==r1 && x0==x1 && y0==y1 ) { g<<"-1\n"; return; } //cercuri identice => oo intersectii

    double dx = x1-x0, dy = y1 - y0;
    double d = sqrt( dx*dx + dy*dy  );

    if( d > r0+r1 || d < fabs(r0-r1) ) { g<<"-2\n"; return; } //0 intersectii

    if( eq(d,r0+r1) || eq( d,fabs(r0-r1) ) ) { g<<"-3\n"; return; } //1 intersectie

    double a = ( (r0*r0) - (r1*r1) + (d*d) ) / (d*2); //distanta dintre P0 si P2

    //coordonatele punctului P2
    double x2 = x0 + ( dx*a/d );
    double y2 = y0 + ( dy*a/d );

    //distanta de la punctele de intersectie la P2
    double h = sqrt( (r0*r0) - (a*a) );

    double x3, y3, _x3, _y3; //coordonatele punctelor de intersectie P3 si _P3
    x3 = x2 + h*( dy/d ); y3 = y2 - h*( dx/d );
    _x3 = x2 - h*( dy/d ); _y3 = y2 + h*( dy/d );
    double _dx = x3-_x3, _dy = y3-_y3;
    double dist = sqrt( (_dx*_dx) + (_dy*_dy) ); // distanta dintre punctele de intersectie
    g<< fixed << setprecision(3) << dist <<"\n";
}

int main()
{
    double x0, y0, r0, x1, y1, r1;
    f>>T;
    for( int i=1; i<=T; i++ )
    {
        f>>x0>>y0>>r0>>x1>>y1>>r1;
        solve(x0,y0,r0,x1,y1,r1);
    }
	f.close(); g.close();
	return 0;
}

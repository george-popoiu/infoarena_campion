#include<fstream>
#include<iostream>
#define inf "apartine.in"
#define outf ""
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

struct punct { float x,y; };
punct P,P1,P2,P3;

void read()
{
    float x,y;
    f>>x>>y; P.x = x; P.y = y;
    f>>x>>y; P1.x = x; P1.y = y;
    f>>x>>y; P2.x = x; P2.y = y;
    f>>x>>y; P3.x = x; P3.y = y;
}

float verifica(punct P, punct P1, punct P2)
{
    return ( (P1.x-P.x)*(P2.y-P.y) - (P2.x-P.x)*(P1.y-P.y) ) ;
}

inline int max( float a, float b ) { return ( a>b ? a : b ); }
inline int min( float a, float b ) { return ( a<b ? a : b ); }

bool apartine(punct P, punct P1, punct P2)
{
    if( verifica(P,P1,P2) ) return false;
    if( P1.x == P2.x )
    {
        if( P.y >= min(P1.y, P2.y) && P.y <= max(P1.y, P2.y) ) return true;
        return false;
    }
    if( P.x >= min(P1.x, P2.x) && P.x <= max(P1.x, P2.x) ) return true;
    return false;
}

float ceas_trig(punct P, punct P1, punct P2) // P,P1,P2; <0 => stanga; >0 => dreapta; =0 => P-P1-P2
{
    return ( (P2.x-P.x)*(P1.y-P.y) - (P1.x-P.x)*(P2.y-P.y) );
}

bool respingere_rapida(punct P1, punct P2, punct P3, punct P4)
{
    int x1, y1, x2, y2, x3, y3, x4, y4;
    x1 = min(P1.x, P2.x); y1 = min(P1.y, P2.y);
    x2 = max(P1.x, P2.x); y2 = max(P1.y, P2.y);
    x3 = min(P3.x, P4.x); y3 = min(P3.y, P4.y);
    x4 = max(P3.x, P4.x); y4 = max(P3.y, P4.y);
    return ( x2>=x3 && x4>=x1 && y2>=y3 && y4>=y1 ) ;
}

bool intersectie(punct P1, punct P2, punct P3, punct P4)
{
    if( !respingere_rapida(P1,P2,P3,P4) ) return false;
    if( ceas_trig(P1,P2,P3) * ceas_trig(P1,P2,P4) > 0 ) return false;
    if( ceas_trig(P3,P4,P1) * ceas_trig(P3,P4,P2) > 0 ) return false;
    return true;
}

void solve()
{
    if( intersectie(P,P1,P2,P3) ) cout<<"Da";
}

int main()
{
	read(); solve();
	f.close(); g.close();
	return 0;
}

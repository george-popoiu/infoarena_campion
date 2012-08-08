#include<fstream>
#define inf "reuniune.in"
#define outf "reuniune.out"
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

struct punct { long long x,y; };
struct dreptunghi { punct SS,DJ; };
dreptunghi a,b,c;

inline void read()
{
    long long x0,y0,x1,y1;
    f>>x0>>y0>>x1>>y1;
    a.SS.x = x0; a.SS.y = y1; a.DJ.x=x1; a.DJ.y=y0;
    f>>x0>>y0>>x1>>y1;
    b.SS.x = x0; b.SS.y = y1; b.DJ.x=x1; b.DJ.y=y0;
    f>>x0>>y0>>x1>>y1;
    c.SS.x = x0; c.SS.y = y1; c.DJ.x=x1; c.DJ.y=y0;
}

inline long long max(long long a, long long b) { return ( a>b ? a : b ); }
inline long long min(long long a, long long b) { return ( a<b ? a : b ); }

inline bool NotIntersect(dreptunghi a, dreptunghi b) { return ( a.DJ.y>b.SS.y || a.SS.y<b.DJ.y || a.DJ.x<b.SS.x || a.SS.x>b.DJ.x ); }

inline punct StangaSus(dreptunghi a, dreptunghi b)
{
    punct p;
    p.x = max(a.SS.x,b.SS.x); p.y = min(a.SS.y,b.SS.y);
    return p;
}

inline punct DreaptaJos(dreptunghi a, dreptunghi b)
{
    punct p;
    p.x = min(a.DJ.x,b.DJ.x); p.y = max(a.DJ.y,b.DJ.y);
    return p;
}

inline long long Arie(punct p1, punct p2) { return ( (p1.y-p2.y)*(p2.x-p1.x) ); }
inline long long Perim(punct p1, punct p2) { return ( 2*(p1.y-p2.y+p2.x-p1.x) ); }

inline void solve()
{
    long long per=Perim(a.SS,a.DJ)+Perim(b.SS,b.DJ)+Perim(c.SS,c.DJ), ar=Arie(a.SS,a.DJ)+Arie(b.SS,b.DJ)+Arie(c.SS,c.DJ);
    if( !NotIntersect(a,b) )
    {
        dreptunghi r; r.SS = StangaSus(a,b); r.DJ = DreaptaJos(a,b);
        per -= Perim(r.SS,r.DJ);
        ar -= Arie(r.SS,r.DJ);
        if( !NotIntersect(r,c) )
        {
            dreptunghi p; p.SS = StangaSus(r,c); p.DJ = DreaptaJos(r,c);
            per += Perim(p.SS,p.DJ);
            ar += Arie(p.SS,p.DJ);
        }
    }
    if( !NotIntersect(a,c) )
    {
        dreptunghi r; r.SS = StangaSus(a,c); r.DJ = DreaptaJos(a,c);
        per -= Perim(r.SS,r.DJ);
        ar -= Arie(r.SS,r.DJ);
    }
    if( !NotIntersect(b,c) )
    {
        dreptunghi r; r.SS = StangaSus(b,c); r.DJ = DreaptaJos(b,c);
        per -= Perim(r.SS,r.DJ);
        ar -= Arie(r.SS,r.DJ);
    }
    g<< ar <<" "<< per;
}

int main()
{
	read(); solve();
	f.close(); g.close();
	return 0;
}

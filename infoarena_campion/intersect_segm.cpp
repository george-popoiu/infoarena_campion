#include<fstream>
#include<vector>
#define inf "intersect_segm.in"
#define outf "intersect_segm.out"
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

struct punct
{
    float x,y;
    punct(){}
    punct(float _x,float _y) { x=_x; y=_y; }
};

struct segment
{
    punct P1,P2;
    segment(){}
    segment(punct _P1, punct _P2) { P1 = _P1; P2 = _P2; }
};

int n;
vector<punct> P;
vector<segment> S;

void read()
{
    float x,y;
    f>>n;
    for(int i=1; i<=n; i++)
    {
        f>>x>>y;
        P.push_back( *( new punct(x,y) ) );
    }
    for(int i=0; i<P.size()-1; i++) S.push_back( *( new segment(P[i],P[i+1]) ) );
}

inline float max(float a,float b) { return ( a>b ? a : b ); }

inline float min(float a,float b) { return ( a<b ? a : b ); }

bool intersect(segment S1, segment S2)
{
    //test rapid
    float x1,y1,x2,y2,_x1,_y1,_x2,_y2;
    x1 = min( S1.P1.x, S1.P2.x ); y1 = min( S1.P1.y, S1.P2.y );
    x2 = max( S1.P1.x, S1.P2.x ); y2 = max( S1.P1.y, S1.P2.y );

    _x1 = min( S2.P1.x, S1.P2.x ); _y1 = min( S2.P1.y, S2.P2.y );
    _x2 = max( S2.P1.x, S2.P2.x ); _y2 = max( S2.P1.y, S2.P2.y );
}

void solve()
{
}

int main()
{
	read(); solve();
	f.close(); g.close();
	return 0;
}

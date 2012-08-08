#include<fstream>
#include<vector>
#define inf "intersect_polig_convex.in"
#define outf "intersect_polig_convex.out"
#define Max 100
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

struct punct { double x,y; };

int N, M;
punct P[Max], Q[Max];
vector<punct> use;

void read()
{
    f>>N; double x,y;
    for(int i=1; i<=N; i++)
    {
        f>>x>>y;
        P[i].x = x; P[i].y = y;
    }
    f>>M;
    for(int i=1; i<=M; i++)
    {
        f>>x>>y;
        Q[i].x = x; Q[i].y = y;
    }
    P[0] = P[N]; P[N+1] = P[1];
    Q[0] = Q[M]; Q[M+1] = Q[1];
}

inline double min(double a, double b) { return ( a<b ? a : b ); }

inline double max(double a, double b) { return ( a>b ? a : b ); }

inline double ceas_trig(punct P1, punct P2, punct P3) //P1P3 X P1P2
{
    return ( ((P2.x-P1.x)*(P3.y-P1.y)) - ((P3.x-P1.x)*(P2.y-P1.y)) );
}

bool intersects(punct P1, punct P2, punct P3, punct P4)
{
    double x1, x2, x3, x4, y1, y2, y3, y4;
    x1 = min(P1.x,P2.x); y1 = min(P1.y,P2.y);
    x2 = max(P1.x,P2.x); y2 = max(P1.y,P2.y);
    x3 = min(P3.x,P4.x); y3 = min(P3.y,P4.y);
    x4 = max(P3.x,P4.x); y4 = max(P3.y,P4.y);
    if( !( x2>=x3 && x4>=x1 && y2>=y3 && y4>=y1 ) ) return false;
    if( ceas_trig(P1,P2,P3) * ceas_trig(P1,P2,P4) > 0 ) return false;
    if( ceas_trig(P3,P4,P1) * ceas_trig(P3,P4,P2) > 0 ) return false;
    return true;
}

bool inside(punct p, punct Q[], int dim)
{
    int intersectii = 0;
    for(int i=1; i<=dim; i++)
    {
        if( (p.y > Q[i].y && p.y < Q[i+1].y) || (p.y > Q[i+1].y && p.y < Q[i].y) )
        {
            double t = (p.y-Q[i+1].y)/(Q[i].y-Q[i+1].y);
            double cx = t*Q[i].x + (1-t)*Q[i+1].x;
            if( cx==p.x ) return false;
            if( p.x < cx ) intersectii++;
        }
        if( (p.x==Q[i].x && p.y==Q[i].y) || (p.x==Q[i+1].x && p.y==Q[i+1].y) ) return false;
        if( p.y==Q[i].y )
        {
            if( Q[i+1].y==Q[i].y && ( (p.x>=Q[i].x && p.x<=Q[i+1].x)  || (p.x>=Q[i+1].x && p.x<=Q[i].x) ) ) return false;
            if( p.x < Q[i].x )
            {
                if( Q[i-1].y < p.y ) intersectii++;
                if( Q[i+1].y < p.y ) intersectii++;
            }
        }
    }
    return ( (intersectii%2) == 1 );
}

inline bool egal(punct a, punct b)
{
    return ( (a.x==b.x) && (a.y==b.y) );
}

void solve()
{
    for(int i=1; i<=N; i++)
        for(int j=1; j<=M; j++)
            if( intersects(P[i],P[i+1],Q[j],Q[j+1]) )
            {
                double a1 = P[i].y - P[i+1].y, b1 = P[i+1].x - P[i].x, c1 = (P[i].x*P[i+1].y) - (P[i+1].x*P[i].y);
                double a2 = Q[j].y - Q[j+1].y, b2 = Q[j+1].x - Q[j].x, c2 = (Q[j].x*Q[j+1].y) - (Q[j+1].x*Q[j].y);
                punct p;
                if( b1*a2 != b2*a1 )
                {
                    if( a1 )
                    {
                        p.y = ( (c2*a1) - (c1*a2) ) / ( (b1*a2) - (b2*a1) );
                        p.x = (-c1 - (p.y*b1)) / a1;
                    }
                    else
                    {
                        p.y = (-c1) / b1;
                        p.x = ( (-b2)*p.y - c2 ) / a2;
                    }
                }
                else
                {
                    if( egal(P[i],Q[j]) || egal(P[i],Q[j+1]) ) p = P[i];
                    else p = P[i+1];
                }
                use.push_back(p);
            }
    for(int i=1; i<=N; i++)
        if( inside(P[i], Q, M) ) use.push_back(P[i]);
    for(int i=1; i<=M; i++)
        if( inside(Q[i], P, N) ) use.push_back(Q[i]);
    if( use.size()<3 ) { g<<"-1"; return; }
    for(int i=0; i<use.size(); i++) g<< use[i].x<<" "<<use[i].y<<"\n";
}

int main()
{
	read(); solve();
	f.close(); g.close();
	return 0;
}

#include<fstream>
#include<vector>
#include<algorithm>
#include<iomanip>
#define inf "arie.in"
#define outf "arie.out"
#define Max 30
#define INF 0x3f3f3f3f
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

struct punct { double x,y; };
punct P[Max], Q[Max], O;
int N,M;
vector<punct> points, final;

void read()
{
    f>>N; double x,y;
    for(int i=1; i<=N; i++)
    {
        f>>x>>y;
        P[i].x = x; P[i].y = y;
    }
    P[0] = P[N]; P[N+1] = P[1]; P[N+2] = P[2];
    f>>M;
    for(int i=1; i<=M; i++)
    {
        f>>x>>y;
        Q[i].x = x; Q[i].y = y;
    }
    Q[0] = Q[M]; Q[M+1] = Q[1]; Q[M+2] = Q[2];
}

inline double min(double a,double b) { return ( a<b ? a : b ); }
inline double max(double a,double b) { return ( a>b ? a : b ); }

inline double ceas_trig(punct P1, punct P2, punct P3) { return ( ((P2.x-P1.x)*(P3.y-P1.y)) - ((P3.x-P1.x)*(P2.y-P1.y)) ); }

inline bool intersects(punct P1, punct P2, punct P3, punct P4)
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

inline bool egal(punct P1, punct P2) { return ( (P1.x==P2.x) && (P1.y==P2.y) ); }

inline int semn(double a)
{
    if( !a ) return 0;
    if( a<0 ) return -1;
    return 1;
}

bool inside(punct M, punct P[], int dim)
{
    int count = 0;
    for(int i=1; i<=dim; i++)
    {
        if( ( M.y>P[i].y && M.y<P[i+1].y ) || ( M.y>P[i+1].y && M.y<P[i].y ) )
        {
            double t = (M.y-P[i+1].y) / (P[i].y-P[i+1].y);
            double cx = (t*P[i].x) + ( (1-t)*P[i+1].x );
            if( cx==M.x ) return false;
            if( M.x<cx ) count++;
        }
        if( P[i].y==M.y && P[i+1].y==M.y && P[i].x<=M.x && P[i+1].x>=M.x ) return false; //pe latura, P[i] stanga
        if( M.y==P[i].y && M.x<=P[i].x )
        {
            if( P[i+1].y==M.y ) {
                if( P[i+1].x<=M.x && M.x>=P[i].x ) return false; } //pe latura, P[i] dreapta
            else {
                if( P[i+1].y<M.y ) count++; }
            if( P[i-1].y<M.y ) count++;
        }
    }
    return (count%2 == 1);
    /*int sgn = semn( ceas_trig(P[1],P[2],M) );
    if( !sgn ) return false;
    for(int i=2; i<=dim; i++)
        if( semn( ceas_trig(P[i],P[i+1],M) ) != sgn ) return false;
    return true;*/
}

struct cmp
{
    bool operator () (const punct &P1, const punct &P2) { return ( ceas_trig(O,P1,P2)>0 ); }
};

void solve()
{
    for(int i=1; i<=N; i++)
        for(int j=1; j<=M; j++)
            if( intersects(P[i], P[i+1], Q[j], Q[j+1]) )
            {
                double a1 = P[i].y - P[i+1].y, b1 = P[i+1].x - P[i].x, c1 = (P[i].x*P[i+1].y) - (P[i+1].x*P[i].y);
                double a2 = Q[j].y - Q[j+1].y, b2 = Q[j+1].x - Q[j].x, c2 = (Q[j].x*Q[j+1].y) - (Q[j+1].x*Q[j].y);
                punct p;
                if( b1*a2==b2*a1 )
                {
                    if( egal(P[i],Q[j]) || egal(P[i],Q[j+1]) ) p = P[i];
                    else p = P[i+1];
                }
                else
                {
                    if( a1 )
                    {
                        p.y = ( (c2*a1) - (c1*a2) ) / ( (b1*a2) - (b2*a1) );
                        p.x = ( (-1)*(b1*p.y) - c1 ) / a1;
                    }
                    else
                    {
                        p.y = ( (-1)*c1) / b1;
                        p.x = ( (-1)*(b2*p.y) - c2 ) / a2;
                    }
                }
                points.push_back(p);
            }
    for(int i=1; i<=N; i++)
        if( inside(P[i], Q, M) ) points.push_back(P[i]);
    for(int i=1; i<=M; i++)
        if( inside(Q[i], P, N) ) points.push_back(Q[i]);
    if( !points.size() ) { g<<"0.000"; return; }

    //for(int i=0; i<points.size(); i++) g<<points[i].x<<" "<<points[i].y<<"\n";

    int minX = INF, minY = INF, poz;
    for(int i=0; i<points.size(); i++) {
        if( points[i].x<minX ) minX = points[i].x, minY = points[i].y, poz = i;
        else if( points[i].x==minX && points[i].y<minY ) minY = points[i].y, poz = i; }

    swap( points[0], points[poz] ); O = points[0];
    sort( points.begin()+1, points.end(), cmp() );

    final.push_back(points[0]);
    for(int i=1; i<points.size(); i++)
        if( !egal( points[i], final[ final.size()-1 ] ) ) final.push_back(points[i]);
    if( final.size()<3 ) { g<<"0.000"; return; }

    //for(int i=0; i<final.size(); i++) g<<final[i].x<<" "<<final[i].y<<"\n";

    punct S[Max]; int vf=0;
    S[++vf] = final[0];
    for(int i=1; i<final.size(); i++)
    {
        while( vf>=2 && ( ceas_trig(S[vf-1],S[vf],final[i])<0 ) ) vf--;
        S[++vf] = final[i];
    }
    if( vf<3 ) { g<<"0.000"; return; }

    double area = 0; S[0] = S[vf]; S[vf+1] = S[1];
    //for(int i=1; i<=vf; i++) g<<S[i].x<<" "<<S[i].y<<"\n";
    for(int i=1; i<=vf; i++)
    {
        //g<< ( (S[i+1].x-S[i].x)*(S[i+1].x+S[i].x) ) / 2 <<"\n";
        area += ( (S[i+1].x-S[i].x)*(S[i+1].y+S[i].y) ) / 2;
    }
    g<< fixed << setprecision(3) << ( area < 0 ? -area : area );
}

int main()
{
	read(); solve();
	f.close(); g.close();
	return 0;
}

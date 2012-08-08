#include<fstream>
using namespace std;

fstream f,g;

struct punct { double x,y; };
punct P1, P2, P3, P4;

void read()
{
	f.open("intersect.in", ios::in);
	f>> P1.x >> P1.y >> P2.x >> P2.y >> P3.x >> P3.y >> P4.x >> P4.y;
	f.close();	
}

inline double min(double a,double b) { return ( a<b ? a : b ); }

inline double max(double a,double b) { return ( a>b ? a : b ); }

double ceas_trig(punct P1, punct P2, punct P3)
{
	return ( ((P2.x-P1.x)*(P3.y-P1.y)) - ((P3.x-P1.x)*(P2.y-P1.y)) );
}

bool intersect(punct P1, punct P2, punct P3, punct P4)
{
	int x1, x2, x3, x4, y1, y2, y3, y4;
	x1 = min(P1.x,P2.x); y1 = min(P1.y,P2.y);
	x2 = max(P1.x,P2.x); y2 = max(P1.y,P2.y);
	x3 = min(P3.x,P4.x); y3 = min(P3.y, P4.y);
	x4 = max(P3.x,P4.x); y4 = max(P3.y, P4.y);
	if( !(x2>=x3 && x4>=x1 && y2>=y3 && y4>=y1) ) return false;
	if( ceas_trig(P1,P2,P3) * ceas_trig(P1,P2,P4) > 0 ) return false;
	if( ceas_trig(P3,P4,P1) * ceas_trig(P3,P4,P2) > 0 ) return false;
	return true;
}

void solve()
{
	g.open("intersect.out", ios::out);
	if( intersect(P1,P2,P3,P4) ) g<<"Se intersecteaza\n";
	else { g<<"Nu se intersecteaza"; return; }
	double a1 = P1.y-P2.y, b1 = P2.x-P1.x, c1 = (P1.x*P2.y) - (P2.x*P1.y);
	double a2 = P3.y-P4.y, b2 = P4.x-P3.x, c2 = (P3.x*P4.y) - (P4.x*P3.y);
	//g<< a1<<" "<<b1<<" "<<c1<<"\n";
	//g<< a2<<" "<<b2<<" "<<c2<<"\n";
	double x,y;
	y = ((c2*a1) - (c1*a2)) / ((a2*b1) - (a1*b2)); //g<<y;
	if( !a1 && !b2 ) x = (-c2) / a2;
	else if( !a1 && b2 ) x = (-c2 - (y*b2)) / a2;
	else if( a1 && !b1 ) x = (-c1) / a1; 
	else if( a1 && b1 ) x = (-c1 - (y*b1)) / a1;
	g<<x<<" "<<y;
	g.close();
}

int main()
{
	read(); solve();
	return 0;
}


#include<fstream>
#include<math.h>
#include<algorithm>
#include<iomanip>
#define inf "cmap.in"
#define outf "cmap.out"
#define NMax 101000
#define INF 0x3f3f3f3f
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

struct punct { int x,y; };

punct P[NMax];
int N;

void read()
{
    punct p; int x,y;
    f>>N;
    for(int i=1; i<=N; i++)
    {
        f>>x>>y; p.x=x; p.y=y;
        P[i] = p;
    }
}

double min(double a, double b) { return ( a<b ? a : b ); }

double dist(punct a, punct b)
{
    return sqrt( pow( (double)(a.x-b.x), 2.0 ) + pow( (double)(a.y-b.y), 2.0 ) );
}

double dei(int st, int dr)
{
    if( dr-st <= 2 )
    {
        if( st+1 == dr ) return dist(P[st], P[dr]);
        if( dr == st+2 )
        {
            double mini = dist(P[st], P[st+1]);
            double d2 = dist(P[dr], P[st+1]);
            double d3 = dist(P[st], P[dr]);
            if( mini>d2 ) mini = d2;
            if( mini>d3 ) mini = d3;
            return mini;
        }
    }
    else
    {
        int m, ls, ld, i, j;
        double d1, d;
        m = (st+dr)/2;
        d = dei(st, m); d1 = dei(m+1, dr);
        if( d>d1 ) d=d1;

        for(i=m; i>=st; i--)
            if( P[m].x-P[i].x > d ) break;
        ls = i+1;

        for(i=m+1; i<=dr; i++)
            if( P[i].x-P[m+1].x > d ) break;
        ld = i-1;

        for(i=ls; i<=m; i++)
            for(j=m+1; j<=ld; j++)
                if( dist(P[i], P[j]) < d ) d = dist(P[i], P[j]);
        return d;
    }
}

struct cmp { bool operator () (const punct &a, const punct &b) { return (a.x<b.x); } };

void solve()
{
    sort( P+1, P+N+1, cmp() );
    g<< fixed << setprecision(6) << dei(1,N);
}

int main()
{
	read(); solve();
	f.close(); g.close();
	return 0;
}

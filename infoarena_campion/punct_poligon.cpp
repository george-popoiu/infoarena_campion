#include<fstream>
#define inf "punct_poligon.in"
#define outf "punct_poligon.out"
#define NMax 100
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

struct punct { double x,y; };
punct P[NMax], M;
int N, intersectii;

void read()
{
    f>>N; double x,y;
    for(int i=1; i<=N; i++)
    {
        f>>x>>y;
        P[i].x = x; P[i].y = y;
    }
    P[N+1] = P[1]; P[0] = P[N];
    f>> M.x >> M.y;
}

// "trag" o "raza la dreapta" din y
// daca raza intersecteaza frontiera poligonului de un numar impar de ori e in interiorul lui
// altfel e in afara
void solve()
{
    for(int i=1; i<=N; i++)
    {
        if( ( M.y>P[i].y && M.y<P[i+1].y ) || ( M.y>P[i+1].y && M.y<P[i].y ) )
        {
            double t = (M.y-P[i+1].y)/(P[i].y-P[i+1].y) ;
            double cx = t*P[i].x + (1-t)*P[i+1].x ;
            if( cx==M.x ) { g<<"pe frontiera"; return; }
            else if( M.x<cx ) { intersectii++; }
        }
        //daca e varf
        if( ( M.x==P[i].x && M.y==P[i].y ) || ( M.x==P[i+1].x && M.y==P[i+1].y ) ) { g<<"pe frontiera"; return; }
        if( P[i].y==M.y )
        {
            if( P[i+1].y==P[i].y && ( ( M.x>=P[i].x && M.x<=P[i+1].x ) || ( M.x>=P[i+1].x && M.x<=P[i].x ) ) ) { g<<"pe frontiera"; return; }
            //"mut dreapta" foarte putin in jos
            if( M.x<P[i].x )
            {
                if( P[i+1].y<M.y ) { intersectii++;  }
                if( P[i-1].y<M.y ) { intersectii++; }
            }
        }
    }
    if( intersectii%2 ) g<<"inauntru";
    else g<<"afara";
}

int main()
{
	read(); solve();
	f.close(); g.close();
	return 0;
}

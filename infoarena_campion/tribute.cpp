#include<fstream>
#include<algorithm>
#define inf "tribute.in"
#define outf "tribute.out"
#define NMax 50100
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int N, DX, DY;
int X[NMax], Y[NMax];

void read()
{
    f>>N>>DX>>DY;
    for(int i=1; i<=N; i++) f>>X[i]>>Y[i];
}

void solve()
{
    sort( X+1, X+N+1 ); sort( Y+1, Y+N+1 );
    int li = 1, ls = N, d = 0;
    while( li<=ls )
    {
        int addx = X[ls] - X[li] - DX;
        if( addx>0 ) d += addx;
        int addy = Y[ls] - Y[li] - DY;
        if( addy>0 ) d += addy;
        li++; ls--;
    }
    g<< d;
}

int main()
{
	read(); solve();
	f.close(); g.close();
	return 0;
}

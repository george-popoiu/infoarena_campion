#include<fstream>
#include<vector>
#include<string.h>
#include<queue>
#define inf "croco.in"
#define outf "croco.out"
#define NMax 150
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

struct flux { int val,D; }

const int S = 1;
int N, M, D;
int C[NMax][NMax], F[NMax][NMax], viz[NMax], T[NMax];

inline int min(int a,int b) { return ( a<b ? a : b ); }

void read()
{
}

int flux()
{
}

void solve()
{
    int fmin = INF;
    for(int i=1; i<=N; i++)

}

int main()
{
	read(); solve();
	f.close(); g.close();
	return 0;
}

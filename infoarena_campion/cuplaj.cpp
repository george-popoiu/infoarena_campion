#include<fstream>
#include<string.h>
#include<vector>
#include<bitset>
#define inf "cuplaj.in"
#define outf "cuplaj.out"
#define NMax 10100
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int N, M, E, sol;
int L[NMax], R[NMax];
bitset<NMax> viz;
vector<int> LA[NMax];

void read()
{
	f>>N>>M>>E; int a,b;
	for(int i=1; i<=E; i++)
	{
		f>>a>>b;
		LA[a].push_back(b);
	}
}

bool cupleaza(int u)
{
	if( viz[u] ) return false;
	viz[u] = 1;
	for(int i=0; i<LA[u].size(); i++)
	{
		int v = LA[u][i];
		if( !R[v] || cupleaza(R[v]) )
		{
			L[u] = v; R[v] = u;
			return true;
		}
	}
	return false;
}

void solve()
{
	bool ok = true;
	while( ok )
	{
		ok = false; viz.reset();
		for(int i=1; i<=N; i++)
			if( !L[i] && cupleaza(i) ) sol++, ok = true;
	}

	for(int i=1; i<=N; i++)
        if( (!L[i] && cupleaza(i)) || ( L[i] && R[L[i]] && cupleaza(R[L[i]]) ) ) { g<<"NU"; return; }

	g<<"DA\n";
	for(int i=1; i<=N; i++)
		if( L[i] ) g<< i <<" "<< L[i] <<"\n";
}

int main()
{
	read(); solve();
	f.close(); g.close();
	return 0;
}


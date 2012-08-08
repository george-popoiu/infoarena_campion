#include<fstream>
#define inf "ghiozdan.in"
#define outf "ghiozdan.out"
#define NMax 20001
#define GMax 75001
#define WMax 201
#define INF 0x3f3f3f3f
using namespace std;

fstream f(inf,ios::in), g(outf, ios::out);

int best[GMax]; //best[i] = nr minim de obiecte cu care se poate obtine greutatea i
int v[WMax]; //v[i] = j daca exista j obiecte cu greutatea i
int N, G;

void read()
{
    f>>N>>G;
    int x;
    for(int i=1; i<=N; i++) f>>x, v[x]++;
}

void solve()
{
    for(int i=1; i<=G; i++) best[i] = INF;
    best[0] = 1;

    int wmax = -INF;
    for(int i=1; i<WMax; i++)
        if( v[i] && i>wmax ) wmax = i;

    for(int i=1; i<=wmax; i++)
    {
        if( !v[i] ) continue;
            for(int j=G; j>=0; j--)
                if( best[j]!=INF && j+i<=G && best[j]+1 < best[j+i] ) best[j+i] = best[j] + 1;
    }
    for(int i = G; i>=0; i--)
        if( best[i]!=INF )
        {
            g<< i <<" "<< best[i]-1 <<"\n";
            break;
        }
}

int main()
{
	read(); solve();
	f.close(); g.close();
	return 0;
}

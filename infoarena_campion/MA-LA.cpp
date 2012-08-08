#include<fstream>
#include<vector>
#define inf "MA-LA.in"
#define outf "MA-LA.out"
#define NMax 100
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int N;
int MA[NMax][NMax];
vector< vector<int> > LA;

void read()
{
    f>>N;
    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++) f>> MA[i][j];
}

void solve()
{
    for(int i=1; i<=N; i++)
    {
        vector<int> list;
        for(int j=1; j<=N; j++)
            if( MA[i][j] ) list.push_back(j);
        LA.push_back(list);
    }

    for(int i=0; i<N; i++)
    {
        g<<"Lista de adiacenta a lui "<<i+1<<" : ";
        if( !LA[i].size() ) { g<<"empty\n"; continue; }
        for(int j=0; j<LA[i].size(); j++) g<< LA[i][j] <<" ";
        g<<"\n";
    }
}

int main()
{
    read(); solve();
    f.close(); g.close();
    return 0;
}

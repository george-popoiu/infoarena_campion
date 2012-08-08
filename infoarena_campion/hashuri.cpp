#include<fstream>
#include<vector>
#define inf "hashuri.in"
#define outf "hashuri.out"
#define MOD 666013
#define vit vector<int>::iterator
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int N;
vector<int> H[MOD];

inline int h(int x) { return x%MOD; }

vit find(int x)
{
int t = h(x);
vit it;
for( it = H[t].begin(); it!=H[t].end(); ++it )
    if( *it == x ) return it;
return it;
}

inline void insert(int x)
{
int t=h(x);
if( find(x) == H[t].end() ) H[t].push_back(x);
}

inline void del(int x)
{
int t=h(x);
vit it = find(x);
if( it != H[t].end() ) H[t].erase(it);
}

void solve()
{
int op,x;
f>>N;
for(int i=1; i<=N; i++)
    {
    f>>op>>x;
    switch( op )
        {
        case 1 : insert(x); break;
        case 2 : del(x); break;
        case 3 :
            int t = h(x);
            vit it = find(x);
            if( it!= H[t].end() ) g<<"1\n";
            else g<<"0\n";
            break;
        }
    }
}

int main()
{
solve();
f.close(); g.close();
return 0;
}

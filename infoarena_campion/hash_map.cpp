#include<fstream>
#include<map>
#define inf "hashuri.in"
#define outf "hashuri.out"
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int N,NR;
map< int, int > M;

void solve()
{
int op,x;
f>>N;
for(int i=1; i<=N; i++)
    {
    f>>op>>x;
    switch( op )
        {
        case 1 :
                if( M.find(x) == M.end() ) M[x] = ++NR;
                break;
        case 2 : M.erase(x); break;
        case 3 : g<< ( M.find(x)!=M.end() ) <<"\n" ;
        }
    }
}

int main()
{
solve();
f.close(); g.close();
return 0;
}

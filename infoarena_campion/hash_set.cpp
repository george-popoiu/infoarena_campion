#include<fstream>
#include<hash_set.h>
#define inf "hashuri.in"
#define outf "hashuri.out"
using namespace std;
using namespace __gnu_cxx;

fstream f(inf,ios::in),g(outf,ios::out);

int N;
hash_set< int, hash<int> > H;

void solve()
{
int op,x;
for( f>>N; N; --N )
    {
    f>>op>>x;
    switch( op )
        {
        case 1 : H.insert(x); break;
        case 2 : H.erase(x); break;
        case 3 : g<< ( H.find(x)!=H.end() ) <<"\n";
        }
    }
}

int main()
{
solve();
f.close(); g.close();
return 0;
}

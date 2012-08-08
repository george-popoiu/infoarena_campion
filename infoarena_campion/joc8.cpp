#include<fstream>
#include<deque>
#define inf "joc8.in"
#define outf "joc8.out"
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int x,y;
deque<int> q;

void read()
{
int a;
f>>x>>y;
while( !f.eof() )
    {
    f>>a;
    q.push_back(a);
    }
q.pop_back();
}

void solve()
{
int m;
while( x<=y )
    {
    m=(x+y)>>1;
    if( q.front()==1 ) { g<<m; return; }
    q.pop_front();
    if( q.front()==1) { y=m-1; q.pop_front(); }
    else { x=m+1; q.pop_front(); }
    }
g<<"0";
}

int main()
{
read();
solve();
f.close();
g.close();
return 0;
}

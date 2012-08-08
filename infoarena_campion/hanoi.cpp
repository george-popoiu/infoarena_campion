#include<fstream>
#define inf "hanoi.in"
#define outf "hanoi.out"
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int n,m;
int s,nr;

void read(){ f>>n>>m; }

void hanoi(int x,int i,int j)
{
if( x>1 )
    {
    hanoi( x-1, i, s-i-j );
    nr++;
    hanoi( x-1, s-i-j, j );
    }
else nr++;
}

void solve()
{
s = ( m *(m+1) ) / 2;
hanoi(n,1,m);
g<< nr;
}

int main()
{
read(); solve();
f.close(); g.close();
return 0;
}

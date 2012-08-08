#include<fstream>
#define inf "partitii2.in"
#define outf "partitii2.out"
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int n,nc;
int p[100];

void read()
{
f>>n;
}

void print()
{
for(int i=1; i<=nc; i++)
    {
    g<<"{ ";
    for(int j=1; j<=n; j++)
        if( p[j]==i ) g<<j<<" ";
    g<<"} ";
    }
g<<"\n";
}

void back(int k)
{
if( k-1 == n ) print();
else
    {
    for(int j=1; j<=nc; j++)
        {
        p[k]=j;
        back(k+1);
        }
    nc++;
    p[k]=nc;
    back(k+1);
    nc--;
    }
}

void solve()
{
back(1);
}

int main()
{
read();
solve();
f.close();
g.close();
return 0;
}

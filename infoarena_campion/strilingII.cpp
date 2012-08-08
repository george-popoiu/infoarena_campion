#include<fstream>
#define inf "strilingII.in"
#define outf "strilingII.out"
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int n,k;
int *s[100];

void read()
{
f>>n>>k;
}

int bell(int n)
{
int a=0;
if( !n ) return 1;
for(int i=1; i<=n; i++) a += s[n][i];
return a;
}

void solve()
{
for(int i=1; i<=n; i++)
    {
    s[i] = new int[i+1];
    s[i][1]=s[i][i]=1;

    for(int j=2; j<i; j++ ) s[i][j] = s[i-1][j-1] + s[i-1][j]*j ;

    delete s[i-1];
    }
g<<s[n][k]<<"\n";
g<<bell(n);
}

int main()
{
read();
solve();
f.close();
g.close();
return 0;
}

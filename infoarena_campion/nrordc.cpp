#include<fstream>
#define inf "nrordc.in"
#define outf "nrordc.out"
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int n,m;
int c[10];

int comb(int n,int m)
{
if( m==0 || n==m ) return 1;
return comb(n-1,m) + comb(n-1,m-1) ;
}

void read()
{
f>>n>>m;
for(int i=1; i<=m; i++) f>>c[i];
}

void solve()
{
int nr=0;
for(int i=1; i<=m; i++)
    for(int j=c[i-1]+1 ; j<c[i]; j++)
        nr += comb(n-j,m-i);
g<<nr;
}

int main()
{
read();
solve();
f.close();
g.close();
return 0;
}

#include<fstream>
#define inf "nrordc2.in"
#define outf "nrordc2.out"
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int n,m,nr_ord,nr;
int c[10];

int comb(int n,int m)
{
if( m==0 || n==m ) return 1;
return comb(n-1,m) + comb(n-1,m-1) ;
}

void read()
{
f>>n>>m>>nr_ord;
}

void solve()
{
for(int i=1; i<=m; i++)
    {
    int j=c[i-1]+1;
    while( nr+comb(n-j,m-i) <= nr_ord )
        {
        nr += comb(n-j,m-i);
        j++;
        }
    c[i]=j;
    g<<c[i]<<" ";
    }
}

int main()
{
read();
solve();
f.close();
g.close();
return 0;
}

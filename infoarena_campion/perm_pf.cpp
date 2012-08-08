#include<fstream>
#define inf "perm_pf.in"
#define outf "perm_pf.out"
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int n;
int st[100],uz[100];

void read()
{
f>>n;
}

void print()
{
for(int i=1; i<=n; i++) g<<st[i]<<" ";
g<<"\n";
}

void back(int k)
{
if( k-1==n ) print();
else
    for(int i=1; i<=n; i++)
        if( !uz[i] && i!=k )
            {
            st[k]=i; uz[i]=1;
            back(k+1);
            uz[i]=0;
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

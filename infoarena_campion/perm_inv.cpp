#include<fstream>
#define inf "perm_inv.in"
#define outf "perm_inv.out"
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int n,x,y;
int st[100],uz[100];

void read()
{
f>>n;
f>>y>>x;
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
        if( ( i==y && uz[x] && !uz[i] ) || ( i!=y && !uz[i] ) )
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

#include<fstream>
#define inf "surj.in"
#define outf "surj.out"
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int n,m;
int im[100];
int st[100];

void read()
{
f>>n>>m;
}

void print()
{
for(int i=1; i<=m; i++)
    if( !im[i] ) return;
for(int i=1; i<=n; i++) g<<st[i]<<" ";
g<<"\n";
}

void back(int k)
{
if( k-1==n ) print();
else
    for(int i=1; i<=m; i++)
        {
        im[i]++;
        st[k]=i;
        back(k+1);
        im[i]--;
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

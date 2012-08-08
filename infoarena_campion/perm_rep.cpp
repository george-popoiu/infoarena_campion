#include<fstream>
#define inf "perm_rep.in"
#define outf "perm_rep.out"
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int n,p;
int st[100];
int m[100],uz[100];

void read()
{
f>>n;
for(int i=1; i<=n; i++) f>>m[i], p+=m[i] ;
}

void print()
{
for(int i=1; i<=p; i++) g<<st[i]<<" ";
g<<"\n";
}

void back(int k)
{
if( k-1==p ) print();
else
    for(int i=1; i<=n; i++)
        if( uz[i]<m[i] )
            {
            uz[i]++; st[k]=i;
            back(k+1);
            uz[i]--;
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

#include<fstream>
#define inf "nr_part.in"
#define outf "nr_part.out"
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int n;
int val;
int st[100];

void read()
{
f>>n;
}

void print(int k)
{
for(int i=1; i<=k; i++) g<<st[i]<<" ";
g<<"\n";
}

void back(int k)
{
if( val==n ) print(k-1);
else
    for(int i=st[k-1]; val+i<=n; i++)
        {
        val+=i;
        st[k]=i;
        back(k+1);
        val-=i;
        }
}

void solve()
{
st[0]=1;
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

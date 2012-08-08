#include<fstream>
#include<vector>
#define inf "combinari1.in"
#define outf "combinari1.out"
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int n,k;
vector< int > c[100];// vector de vector<int>

void read()
{
f>>n>>k;
}

void solve()
{
for(int i=1; i<=n; i++)
    {
    c[i].assign( i+1, 0 ); //aloc la c[i] un vector de i+1 elemente ce contin valoarea 0
    c[i][0]=c[i][i]=1;
    for(int j=1; j<i; j++) c[i][j]=c[i-1][j]+c[i-1][j-1];
    }
g<<c[n][k];
}

int main()
{
read();
solve();
f.close();
g.close();
return 0;
}

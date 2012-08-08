#include<fstream>
#include<vector>
#define inf "combinari2.in"
#define outf "combinari2.out"
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

//2 linii

vector<int> *c[100];
int n,k;

void read()
{
f>>n>>k;
}

void solve()
{
for(int i=1; i<=n; i++)
    {
    c[i]=new vector<int>(i+1);
    (*c[i]).at(0) = (*c[i]).at(i) = 1;
    for(int j=1; j<i; j++) (*c[i]).at(j) = (*c[i-1]).at(j) + (*c[i-1]).at(j-1) ;
    delete c[i-1];
    }
g<< (*c[n]).at(k);
}

int main()
{
read();
solve();
f.close();
g.close();
return 0;
}

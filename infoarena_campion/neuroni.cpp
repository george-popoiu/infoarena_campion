#include<fstream>
#include<vector>
#define inf "neuroni.in"
#define outf "neuroni.out"
#define nmax 101
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int n,m;
vector<int> *a[nmax];

void read(){ f>>n>>m; }

void solve()
{
int l=1,c=0;
for(int i=1;i<n;i++)
    {
    if(i%2==0)a[i]=new vector<int>(i,0);
    else a[i]=new vector<int>(i,1);
    }
a[n]=new vector<int>(n,0);
for(int i=1;i<=m;i++)
    {
    l=1; c=0;
    while(l<n)
        {
        if( a[l]->at(c) == 1 ) { a[l]->at(c) = 0; l++; c++; }
        else { a[l]->at(c)=1; l++; }
        if(l==n)a[l]->at(c)++;
        }
    }
for(vector<int>::iterator it=a[n]->begin(); it!=a[n]->end(); it++)g<<(*it)<<" ";
}

int main()
{
read();
solve();
f.close();
g.close();
return 0;
}

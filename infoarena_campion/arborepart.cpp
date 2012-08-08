#include<fstream>
#include<list>
#define inf "arborepart.in"
#define outf "arborepart.out"
#define NMax 100
#define liter list<int>::iterator
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

list<int> la[NMax],ap[NMax];//list. de ad. a grafului (la) si cea a arborelui partial (ap)
int viz[NMax];
int n,m;

void read()
{
int x,y;
f>>n>>m;
for(int i=1;i<=m;i++)
    {
    f>>x>>y;
    la[x].push_back(y);
    la[y].push_back(x);
    }
}

void df(int s)
{
viz[s]=1;
for( liter it=la[s].begin(); it!=la[s].end() ; it++ )
    {
    if( !viz[(*it)] )
        {
        ap[s].push_back( (*it) );
        df( (*it) );
        }
    }
}

void print()
{
for(int i=1;i<=n;i++)
    {
    g<<i<<": ";
    for( liter it=ap[i].begin(); it!=ap[i].end(); it++ ) g<<(*it)<<" ";
    g<<"\n";
    }
}

int main()
{
read();
df(1);
print();
f.close();
g.close();
return 0;
}

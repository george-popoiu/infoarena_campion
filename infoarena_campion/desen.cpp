#include<fstream>
#include<algorithm>
#include<math.h>
#include<vector>
#define inf "desen.in"
#define outf "desen.out"
#define NMax 1100
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int N;
int k;
vector< pair<int,int> > v;
int T[NMax],H[NMax];

struct muchie
{
int a;
int b;
double c;
};

muchie m[2*NMax];

inline int p2(int x) { return x*x; }

int Root(int nod)
{
while( T[nod] ) nod=T[nod];
return nod;
}

inline void Reuneste(int v1,int v2)
{
if( H[v1]==H[v2] ) { T[v2]=v1; H[v1]++; return; }
if( H[v1]<H[v2] ) { T[v1]=v2; return; }
T[v2]=v1;
}

struct cmp
{
bool operator() (const muchie &x, const muchie &y)
    {
    if( x.c<y.c ) return true;
    return false;
    }
};

void init(int n)
{
for(int i=1; i<=n; i++) T[i]=H[i]=0;
}

double kruskal(int n,muchie m[],int k)
{
//if( n==1 ) return 0;
double result=0;
muchie apm[2*NMax];
int t=1;
int nrm=0;
int v1,v2;
sort(m+1,m+1+k, cmp() );
init(n);
while( nrm<n-1 )
    {
    while( ( v1 = Root(m[t].a) ) == ( v2 = Root(m[t].b) ) ) t++;
    result += m[t].c;
    nrm++;
    apm[nrm]=m[t];
    Reuneste( v1, v2 );
    t++;
    }
for(int i=1; i<n; i++) m[i]=apm[i];
return result;
}

void solve()
{
int x,y;
f>>N;
g.precision(6);
for(int i=1; i<=N; i++)
    {
    f>>x>>y;
    for(int j=0; j<v.size(); j++)
        ++k,
        m[k].a = i ,
        m[k].b = j+1 ,
        m[k].c = sqrt( p2(x-v[j].first) + p2(y-v[j].second) );
    v.push_back( make_pair(x,y) );
    g<< fixed << kruskal(i,m,k)<<"\n";
    k=i-1;
    }
}

int main()
{
solve();
f.close(); g.close();
return 0;
}

#include<fstream>
#define inf "cifru2.in"
#define outf "cifru2.out"
#define NMax 100100
#define INF 0x3f3f3f3f
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int n,m;
int si[NMax],sf[NMax];
int ui[NMax],uf[NMax];
int d;

void read()
{
f>>n>>m;
for(int i=1; i<=n; i++) f>>si[i];
for(int i=1; i<=n; i++) f>>sf[i];
}

void prefix(int a[],int urm[],int dim)
{
int k=0;
urm[1]=0;
for(int i=2; i<=dim; i++)
    {
    while( k>0 && a[k+1]!=a[i] ) k=urm[k];
    if( a[k+1]==a[i] ) k++;
    urm[i]=k;
    }
}

void solve()
{
prefix(si,ui,n);
prefix(sf,uf,n);
/*for(int i=1; i<=n; i++) g<< uf[i]<<" ";
g<<"\n"<<n<<"\n";
for(int i=1; i<=n; i++) g<< sf[i]<<" ";*/
}

int main()
{
read(); solve();
f.close(); g.close();
return 0;
}

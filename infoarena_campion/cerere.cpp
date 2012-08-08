#include<fstream>
#define inf "cerere.in"
#define outf "cerere.out"
#define NMax 100010
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int n;
int radacina;
int str[NMax],nr[NMax];
int gi[NMax];
int st[NMax];

struct nod
{
int info;
nod *next;
};

nod *la[NMax];

void add(int a,int b)
{
nod *p=new nod;
p->info = b;
p->next = la[a] ;
la[a] = p ;
}

void read()
{
int a,b;
f>>n;
for(int i=1; i<=n; i++) f>>str[i];
for(int i=1; i<n; i++) f>>a>>b , add(a,b), gi[b]++ ;
for(int i=1; i<=n; i++)
    if( !gi[i] ) { radacina=i ; return; }
}

void DFS(int nd,int k)
{
if( !str[nd] ) st[k]=0 , nr[nd]=st[k];
else st[k] = 1+st[k-str[nd]] , nr[nd]=st[k];
nod *p = la[nd];
while( p )
    {
    DFS( p->info, k+1 );
    p = p->next;
    }
}

void solve()
{
DFS(radacina,1);
for(int i=1; i<=n; i++) g<<nr[i]<<" ";
}

int main()
{
read();
solve();
f.close();
g.close();
return 0;
}

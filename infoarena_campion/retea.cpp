#include<stdio.h>
#include<algorithm>
#include<bitset>
#define inf "retea.in"
#define outf "retea.out"
#define MMax 20100
#define NMax 1100
#define KMax 50100
using namespace std;

int N,M,K;
int T[NMax],H[NMax];
int cost_apm,result;
bitset<KMax> s;

struct muchie{ int a,b,c; };

muchie m[MMax],apm[NMax];

void read()
{
scanf("%d%d%d",&N,&M,&K);
int x,y,z;
for(int i=1; i<=M; i++)
    {
    scanf("%d%d%d",&x,&y,&z);
    m[i].a = x; m[i].b = y; m[i].c = z;
    }
}

int Root(int nod)
{
int R=nod;
while( T[R] ) R=T[R];
//compresia drumurilor
/*int aux;
while( T[nod] )
    {
    aux = T[nod];
    T[nod] = R;
    nod = aux;
    }*/
return R;
}

void Reuneste(int v1,int v2)
{
if( H[v1]==H[v2] ) { T[v2]=v1; H[v1]++; return; }
if( H[v2]<H[v1] ) { T[v2]=v1; return; }
T[v1]=v2;
}

/*struct cmp
{
bool operator() (const muchie &x,const muchie &y)
    {
    if( x.c<y.c ) return true;
    return false;
    }
};*/

bool rule(muchie x,muchie y)
{
if( x.c<y.c ) return true;
return false;
}

void solve()
{
//kruskal
sort( m+1, m+M+1, rule );
int k=1,nrm=0,v1,v2;
while( nrm<N-1 )
    {
    while( ( v1=Root(m[k].a) ) == ( v2=Root(m[k].b) ) ) k++;
    nrm++;
    apm[nrm].a = m[k].a; apm[nrm].b = m[k].b; apm[nrm].c = m[k].c ;
    cost_apm += apm[nrm].c;
    Reuneste( v1,v2 );
    k++;
    }
//rucsac
s[0]=1;
for(int i=1; i<N; i++)
    {
    for(int j=K; j>=0; j--)
        if( s[j] && j+apm[i].c<=K ) s[ j+apm[i].c ] = 1;
    }
for(int i=0; i<=K; i++)
    if( s[i] ) result++;
printf("%d %d", cost_apm, result );
}

int main()
{
freopen(inf,"r",stdin);
freopen(outf,"w",stdout);
read(); solve();
return 0;
}

// APM - Kruskal - O( MlogM + MlogN )
#include<stdio.h>
#include<algorithm>
#define inf "urgenta.in"
#define outf "urgenta.out"
#define NMax 300
#define MMax 33000
using namespace std;

int N,M,K;
int T[NMax],H[NMax];
int total_cost,apm_cost,result;
int m_select[MMax];

struct muchie { int a,b,c; };

muchie m[MMax],apm[NMax];

void read()
{
scanf("%d%d%d",&N,&M,&K);
int x,y,z;
for(int i=1; i<=M; i++)
    {
    scanf("%d%d%d",&x,&y,&z);
    m[i].a = x; m[i].b = y; m[i].c = z;
    total_cost += z;
    }
}

int Root(int nod)
{
while( T[nod] ) nod = T[nod];
return nod;
}

void Reuneste(int v1,int v2)
{
if( H[v1]==H[v2] ) { T[v2]=v1; H[v1]++; return; }
if( H[v2]<H[v1] ) { T[v2]=v1; return; }
T[v1]=v2;
}

struct cmp
{
bool operator() (const muchie &x,const muchie &y)
    {
    if( x.c<y.c ) return true;
    return false;
    }
};

void solve()
{
sort( m+1, m+M+1, cmp() );
int nrm=0,k=1,v1,v2;
while( nrm<N-1 )
    {
    while( ( v1=Root(m[k].a) ) == ( v2=Root(m[k].b) ) ) k++;
    m_select[k]=1;
    nrm++;
    apm[nrm].a = m[k].a ; apm[nrm].b = m[k].b; apm[nrm].c = m[k].c;
    apm_cost += apm[nrm].c;
    Reuneste( v1,v2 );
    k++;
    }
result = total_cost - apm_cost ;
sort( apm+1, apm+1+N-1, cmp() );
for(int i=N-1; i>=N-K+1; i--) result += apm[i].c ;
printf("%d\n",result );
printf("%d\n",M-N+K);
for(int i=1; i<=M; i++)
    if( !m_select[i] ) printf("%d %d\n",m[i].a,m[i].b);
for(int i=N-1; i>=N-K+1; i--) printf("%d %d\n", apm[i].a, apm[i].b );
}

int main()
{
freopen(inf,"r",stdin);
freopen(outf,"w",stdout);
read(); solve();
return 0;
}

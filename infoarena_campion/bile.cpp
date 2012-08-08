#include<fstream>
#include<vector>
#define inf "buline.in"
#define outf "buline.out"
#define NMax 1000100
#define INF 100000000000000000LL
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int N;
long long v[NMax];
long long s[NMax];
vector< long long > T(NMax,-INF);
int ind[NMax];

void read()
{
long long a,b;
f>>N;
for(int i=1; i<=N; i++)
    {
    f>>a>>b;
    if( !b ) v[i]=-a;
    else v[i]=a;
    s[i] = s[i-1] + v[i];
    if( T[i-1]<s[i] ) T[i]=s[i], ind[i]=i;
    else T[i]=T[i-1], ind[i]=ind[i-1];
    }
}

void solve()
{
int p,l;
int pi,li;
long long smax=-INF;
//smax clasic
long long sum=-INF;
for(int i=1; i<=N; i++)
    {
    if( sum+v[i]<v[i] )
        {
        sum = v[i];
        pi = i;
        li = 1;
        }
    else sum += v[i] , li++;
    if( sum>smax ) smax=sum, l=li, p=pi;
    else if( sum==smax )
        {
        if( pi<p ) p=pi, l=li;
        else if( pi==p && li<l ) l=li;
        }
    }
//circular
for(int i=1; i<=N; i++)
    if( smax < s[N]-s[i-1] + T[i-1] ) { smax = s[N]-s[i-1] + T[i-1] ; p = i ; l= N-i+1+ind[i-1] ; }
g<< smax <<" "<< p <<" "<< l ;
}

int main()
{
read(); solve();
f.close(); g.close();
return 0;
}

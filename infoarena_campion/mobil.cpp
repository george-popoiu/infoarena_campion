#include<stdio.h>
#define inf "mobil.in"
#define outf "mobil.out"
#define INF 100000000000000000LL
#define MMax 100010
using namespace std;

int M;
long long a[40];
long long s[MMax]; // s[i]=costul minim pentru a obtine suma i

void read()
{
scanf("%d",&M);
for(int i=0; i<=30; i++) scanf("%lld",&a[i]);
}

void solve()
{
long long min=INF;
s[0]=1;
for(int i=0; i<=M; i++)
    for(int j=0; j<=30; j++)
        if( s[i] )
            {
            if( i+a[j]<M  )
                {
                if( !s[ i+a[j] ] ) s[ i+a[j] ] = s[i]+(1<<j);
                else if( s[i]+(1<<j) < s[ i+a[j] ] ) s[ i+a[j] ] = s[i]+(1<<j);
                }
            else if( s[i]+(1<<j) < min ) min=s[i]+(1<<j);
            }
printf("%lld",min-1);
}

int main()
{
freopen(inf,"r",stdin);
freopen(outf,"w",stdout);
read();
solve();
return 0;
}

#include<fstream>
#include<algorithm>
#include<string.h>
#define inf "expozitie.in"
#define outf "expozitie.out"
#define NMax 501
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

typedef short big[NMax];
short n,d,k;
short t,s;
big c[2][2*NMax];
short nou=1,old;

void read(){ f>>n>>d>>k; }

void suma(big a,big b,big c)
{
short i;
short t=0;
for( i=1; i<=a[0] || i<=b[0] || t ; i++, t/=10 )
    t += (a[i]+b[i]) ,
    c[i] = t%10 ;
c[0] = i-1;
}

void solve()
{
s = n-d*k;
if( s<0 ) { g<<"0"; return; }
if( s==0 ) { g<<"1"; return; }
short m = s+d-1;
for(short i=1; i<=m; i++)
    {
    c[nou][0][0] = c[nou][i][0] = 1;
    c[nou][0][1] = c[nou][i][1] = 1;
    for(short j=1; j<i && j<=s; j++ ) suma( c[old][j], c[old][j-1], c[nou][j] );
    swap( nou, old );
    }
for( short i=c[old][s][0]; i>=1; i-- ) g<< c[old][s][i];
}

int main()
{
read(); solve();
f.close(); g.close();
return 0;
}

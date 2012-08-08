#include<fstream>
#define inf "culmi.in"
#define outf "culmi.out"
#define Max 110
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

typedef int BIG[Max];
int n,k;
int nou,old;
BIG c[2][Max],p,r;

void read(){ f>>n>>k; }

void sum(BIG a,BIG b,BIG c)
{
int i,t=0;
for( i=1; i<=a[0] || i<=b[0] || t; i++, t/=10 )
    t += (a[i]+b[i]) ,
    c[i] = t%10 ;
c[0] = i-1;
}

void comb(int m,int t)
{
old=0; nou=1;
for(int i=1; i<=m; i++)
    {
    c[nou][0][0] = c[nou][i][0] = 1;
    c[nou][0][1] = c[nou][i][1] = 1;
    for(int j=1; j<i && j<=t; j++) sum(  c[old][j], c[old][j-1], c[nou][j] );
    swap(nou,old);
    }
}

void produs(BIG a,BIG b,BIG c)
{
int i,j,t=0;
for( i=1; i<=a[0] ; i++ )
    {
    for( t=0,j=1; j<=b[0] || t; j++, t/=10 )
        t += ( c[i+j-1]+a[i]*b[j] ) ,
        c[i+j-1] = t%10;
    if( i+j-2>c[0] ) c[0] = i+j-2;
    }
}

void div(BIG a,int nr,BIG c)
{
c[0] = a[0];
int i,t=0;
for( i=a[0]; i>=1; i--, t %= nr )
    t = t*10 + a[i] ,
    c[i] = t/nr ;
for( ; c[0]>=1 && !c[ c[0] ] ; c[0]-- ) ;
}

void solve()
{
comb(n,k);
produs( c[old][k], c[old][k-1], p );
div( p, n, r );
for(int i=r[0]; i>=1; i--) g<<r[i];
}

int main()
{
read(); solve();
f.close(); g.close();
return 0;
}

#include<fstream>
#include<bitset>
#define inf "prim.in"
#define outf "prim.out"
#define Max 1500000
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int k;
int nrp,nr;
bitset<Max> prim;

void read() { f>>k; }

void solve()
{
nrp=1;
for(int i=3; i<=Max; i+=2)
    if( !prim[i] )
        {
        nrp++;
        if( nrp==k+1 ) { nr=i; break; }
        for(int j=i+i+i; j<=Max; j+= (i<<1) ) prim[j]=1;
        }
g<<  (long long) ( (long long)(nr) * (long long)(nr) ) ;
}

int main()
{
read(); solve();
f.close(); g.close();
return 0;
}

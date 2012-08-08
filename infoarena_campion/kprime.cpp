#include<fstream>
#include<bitset>
#define inf "kprime.in"
#define outf "kprime.out"
#define NMax 100100
#define VMax 1001
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int n,k;
int result;
int v[NMax];
int nrp[NMax]; // nrp[i] = numarul numerelor prime din secventa 1,2,...,i
bitset<VMax> prim; // prim[i]=0 <=> i este prim

void read()
{
f>>n>>k;
for(int i=1; i<=n; i++) f>>v[i];
}

void ciur()
{
prim[1] = 1;
for( int i=2; i<=VMax; i++)
    if( !prim[i] )
        for( int j = i+i; j<=VMax; j += i ) prim[j]=1 ;
}

int cauta(int st,int dr)
{
int m,poz,c;
bool gasit=false;
c = dr;
while( st<=dr )
    {
    m = (st+dr)/2;
    if( nrp[c]-nrp[m-1]>k ) st=m+1;
    else if( nrp[c]-nrp[m-1]<k ) dr=m-1;
    else if( nrp[c]-nrp[m-1]==k )
        {
        poz = m;
        gasit = true;
        dr=m-1;
        }
    }
if( gasit ) return poz;
return -1;
}

int cauta2(int st,int dr)
{
int m,poz,c;
bool gasit=false;
c = dr;
while( st<=dr )
    {
    m = (st+dr)>>1;
    if( nrp[c]-nrp[m-1]>k ) st=m+1;
    if( nrp[c]-nrp[m-1]<k ) dr=m-1;
    else if( nrp[c]-nrp[m-1]==k )
        {
        poz=m;
        gasit = true;
        st=m+1;
        }
    }
if( gasit ) return poz;
return -1;
}

void solve()
{
ciur();
for(int i=1; i<=n; i++)
    {
    nrp[i] = nrp[i-1];
    if( !prim[ v[i] ] ) nrp[i]++;
    }
int p,p2;
for(int i=1; i<=n; i++)
    {
    p = cauta(1,i);
    if( p!=-1 )
        {
        p2 = cauta2(1,i);
        result += (p2-p+1);
        }
    }
g<< result;
}

int main()
{
read(); solve();
f.close(); g.close();
return 0;
}

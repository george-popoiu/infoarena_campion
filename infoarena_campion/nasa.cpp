#include<stdio.h>
//#include<fstream>
#include<bitset>
#include<math.h>
#define inf "nasa.in"
#define outf "nasa.out"
#define Max 100000010
#define NMax 47000
using namespace std;

//fstream f(inf,ios::in),g(outf,ios::out);

bitset<Max> bit;
bitset<NMax> prim;
int A,B;
int n;

inline void read() { //f>>A>>B; }
scanf("%d%d",&A,&B);
}

void solve()
{
int cnt=B-A+1;
//ciur
for(int i=3; i<=n; i+=2)
    if(!prim[i])
        for(int j=i+i+i; j<=n; j+= i<<1 ) prim[j]=1;

//ciur


int z,x,t;

n = (int)sqrt(B);

//rezolvare
for(int i=2; i<=n; i++)
    if(!prim[i])
        {
        z=i*i;

        t = z * (A/z);
        if( t<A ) t+=z;

        while( t<=B && t>=A)
            {
            if( !bit[t-A+1] ) bit[t-A+1]=1, cnt--;
            t+=z;
            }
        }
printf("%d",cnt);
//g<<result;
}

int main()
{
freopen(inf,"r",stdin); freopen(outf,"w",stdout);
read(); solve();
//f.close(); g.close();
return 0;
}

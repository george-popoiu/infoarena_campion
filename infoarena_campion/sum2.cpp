#include<fstream>
#define inf "sum2.in"
#define outf "sum2.out"
#define NMax 100001
#define INF 0x3f3f3f3f
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int v[NMax],sum[NMax];
int N,L,U;
int q[NMax],front,back;

void Citire()
{
f>>N>>L>>U;
for(int i=1;i<=N;i++)
    {
    f>>v[i];
    sum[i]=sum[i-1]+v[i];
    }
}

void Rezolva()
{
int j,t;

for(int i=1;i<=N;i++)
    {
    j=i-L+1;
    if(j<0)j=1;
    t=j+U-1;
    while(
    }
g<<rez;
}

int main()
{
Citire();
Rezolva();
f.close();
g.close();
return 0;
}

#include<fstream>
#define inf "tren.in"
#define outf "tren.out"
#define K 3
#define MaxN 50001
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int v[MaxN];
int sum[MaxN];
int s[MaxN][K+1];
int N,M;

void Citire()
{
f>>N;
for(int i=1;i<=N;i++)
    {
    f>>v[i];
    sum[i]=v[i]+sum[i-1];
    }
f>>M;
}

int max(int a,int b)
{
if(a>b)return a;
return b;
}

void Rezolvare()
{
for(int i=1;i<=M;i++)
    for(int j=1;j<=K;j++)s[i][j]=sum[i];
for(int i=M+1;i<=N;i++)
    {
    for(int j=1;j<=K;j++)
        {
        s[i][j]=max(s[i-1][j],s[i-M][j-1]+sum[i]-sum[i-M]);
        }
    }
g<<s[N][K];
}

int main()
{
Citire();
Rezolvare();
f.close();
g.close();
return 0;
}

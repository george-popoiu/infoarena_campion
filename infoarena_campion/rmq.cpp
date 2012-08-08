#include<fstream>
#define inf "rmq.in"
#define outf "rmq.out"
#define MaxN 23000
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int N,M;
int v[MaxN];
int C[MaxN][MaxN];

int min(int a,int b)
{
if(a<b)return a;
return b;
}

void Citire()
{
f>>N;
f>>M;
for(int i=1;i<=N;i++)f>>v[i];
for(int i=1;i<=N;i++)C[i][i]=v[i];
for(int i=1;i<N;i++)
    {
    for(int j=i+1;j<=N;j++)
        {
        C[i][j]=min(C[i][j-1],v[j]);
        }
    }
int x,y;
for(int i=1;i<=M;i++)
    {
    f>>x>>y;
    g<<C[x][y]<<"\n";
    }
}

int main()
{
//Citire();
g<<"as";
f.close();
g.close();
return 0;
}

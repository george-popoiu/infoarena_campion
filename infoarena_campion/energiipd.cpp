#include<fstream>
#define inf "energii.in"
#define outf "energii.out"
#define GMax 2001
#define WMax 6001
#define INF 0x3f3f3f3f
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int G,W;
int sum[GMax];
int C[GMax],E[GMax];
int Cost[GMax][WMax];

void Citire()
{
f>>G;
f>>W;
for(int i=1;i<=G;i++)
    {
    f>>E[i]>>C[i];
    sum[i]=sum[i-1]+E[i];
    }
}

void Rezolva()
{
for(int j=1;j<=W;j++)Cost[0][j]=INF;
for(int i=1;i<=G;i++)
    {
    for(int j=1;j<=W;j++)
        {
        if( j-E[i]>=0 && sum[i-1]>=j-E[i] && Cost[i-1][j-E[i]]+C[i]<Cost[i-1][j] ) Cost[i][j]=Cost[i-1][j-E[i]]+C[i];
        else Cost[i][j]=Cost[i-1][j];
        }
    }
if(Cost[G][W]!=-1)g<<Cost[G][W];
else g<<"-1";
}

int main()
{
Citire();
Rezolva();
f.close();
g.close();
return 0;
}

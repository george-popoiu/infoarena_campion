#include<fstream>
#define inf "eval.in"
#define outf "eval.out"
#define MaxN 100
#define PINF 0x3f3f3f3f
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int N,P;
int op[MaxN][MaxN],c[MaxN][MaxN],cmin[MaxN][MaxN],rez[MaxN][MaxN],v[MaxN];

void Citire()
{
f>>N>>P;
for(int i=1;i<=P;i++)f>>v[i];
for(int i=1;i<=N;i++)
    for(int j=1;j<=N;j++)f>>op[i][j];
for(int i=1;i<=N;i++)
    for(int j=1;j<=N;j++)f>>c[i][j];
}

void Rezolvare()
{
for(int i=1;i<=P;i++){rez[i][i]=v[i];}
for(int t=1;t<=P-1;t++)
    {
    for(int i=1;i<=P-t;i++)
        {
        int j=i+t;
        cmin[i][j]=PINF;
        for(int k=i;k<j;k++)
            {
            if(cmin[i][j]>cmin[i][k]+cmin[k+1][j]+c[rez[i][k]][rez[k+1][j]])
                {
                cmin[i][j]=cmin[i][k]+cmin[k+1][j]+c[rez[i][k]][rez[k+1][j]];
                cmin[j][i]=k;
                rez[i][j]=op[rez[i][k]][rez[k+1][j]];
                }
            }
        }
    }
g<<cmin[1][P];
}

void Afisare(int i,int j)
{
if(i==cmin[j][i])g<<v[i];
else
    {
    g<<"(";
    Afisare(i,cmin[j][i]);
    g<<")";
    }
g<<"o";
if(j==cmin[j][i]+1)g<<v[j];
else
    {
    g<<"(";
    Afisare(cmin[j][i]+1,j);
    g<<")";
    }
}

int main()
{
Citire();
Rezolvare();
g<<endl;
Afisare(1,P);
f.close();
g.close();
return 0;
}

#include<fstream>
#define MaxN 102
#define Infinit 40000
#define inf "taxa2.in"
#define outf "taxa2.out"
using namespace std;

int Taxa[MaxN][MaxN],TaxaMin[MaxN][MaxN],N,S;

void Citire()
{
fstream f(inf,ios::in);
f>>S>>N;
for(int i=1;i<=N;i++)
    for(int j=1;j<=N;j++)f>>Taxa[i][j];
f.close();
}

int Min(int a,int b)
{
if(a<b)return a;
return b;
}

int MinVecini(int lin,int col)
{
int min1,min2,min;
if(TaxaMin[lin][col-1]<TaxaMin[lin][col+1])min1=TaxaMin[lin][col-1];
else min1=TaxaMin[lin][col+1];
if(TaxaMin[lin-1][col]<TaxaMin[lin+1][col])min2=TaxaMin[lin-1][col];
else min2=TaxaMin[lin+1][col];
min=Min(min1,min2);
return min;
}

void Rezolvare()
{
int AmOptimizare=1,min;
for(int i=0;i<=N+1;i++)
    for(int j=0;j<=N+1;j++)TaxaMin[i][j]=Infinit;
TaxaMin[1][1]=Taxa[1][1];
while(AmOptimizare)
    {
    AmOptimizare=0;
    for(int i=1;i<=N;i++)
        {
        for(int j=1;j<=N;j++)
            {
            min=MinVecini(i,j);
            if(min+Taxa[i][j]<TaxaMin[i][j])
                {
                TaxaMin[i][j]=min+Taxa[i][j];
                AmOptimizare=1;
                }
            }
        }
    }
}

void Afisare()
{
fstream g(outf,ios::out);
if(TaxaMin[N][N]<=S)g<<S-TaxaMin[N][N];
else g<<-1;
g.close();
}

int main()
{
Citire();
Rezolvare();
Afisare();
return 0;
}

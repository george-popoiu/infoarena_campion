// folosesc matrici, nu vectori
// folosesc o metoda 'roteste()'
#include<fstream>
using namespace std;

fstream f("cartela.in",ios::in),g("cartela.out",ios::out);

int n,cartele,sablon[51][51],c[51][51];

void citire()
{
for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){f>>c[i][j];}
}

void roteste()
{
int i,j,aux[51][51];
for(i=1;i<=n;i++)
    {
    for(j=1;j<=n;j++)aux[i][j]=c[j][n-i+1];
    }
for(i=1;i<=n;i++)for(j=1;j<=n;j++)c[i][j]=aux[i][j];
}

int main()
{
int i,j,k,gasit,sol;
f>>n>>cartele;
for(i=1;i<=n;i++)for(j=1;j<=n;j++)f>>sablon[i][j];
for(k=1;k<=cartele;k++)
    {
    citire();
    sol=0;
    for(int t=1;t<=4;t++)
        {
        gasit=0;
        //test
        for(i=1;i<=n;i++)
            {
            for(j=1;j<=n;j++)
                {
                if(c[i][j]!=sablon[i][j]){gasit=1;break;}
                }
            if(gasit==1)break;
            }
        if(gasit==0){g<<"1"<<endl;sol=1;break;}
        else roteste();
        }
    if(sol==0)g<<"0"<<endl;
    }
f.close();
g.close();
return 0;
}

#include<fstream>
#define inf "rucsac.in"
#define outf "rucsac.out"
#define MaxN 101
#define MaxG 301
using namespace std;

fstream f(inf,ios::in),fout(outf,ios::out);

int c[MaxN],g[MaxN];
int cmax[MaxG],uz[MaxG][MaxN];
int nro[MaxG];
int N,G;

void Citire()
{
f>>N>>G;
for(int i=1;i<=N;i++)f>>g[i];
for(int i=1;i<=N;i++)f>>c[i];
for(int i=1;i<=G;i++)cmax[i]=-1;
}

void Rezolva()
{
for(int i=1;i<=G;i++)
    {
    for(int j=1;j<=N;j++)
        {
        if(g[j]<=i && cmax[i-g[j]]!=-1 && !uz[i-g[j]][j])
            {
            if(cmax[i]<cmax[i-g[j]]+c[j])
                {
                cmax[i]=cmax[i-g[j]]+c[j];
                for(int k=1;k<=N;k++)uz[i][k]=uz[i-g[j]][k];
                uz[i][j]=1;
                nro[i]=1+nro[i-g[j]];
                }
            else if(cmax[i]==cmax[i-g[j]]+c[j])
                {
                if(nro[i]<nro[i-g[j]]+1)
                    {
                    nro[i]=nro[i-g[j]]+1;
                    for(int k=1;k<=N;k++)uz[i][k]=uz[i-g[j]][k];
                    }
                }
            }
        }
    }
}

void Afisare()
{
if(cmax[G]!=-1)
    {
    fout<<cmax[G]<<"\n";
    for(int i=1;i<=N;i++)
        if(uz[G][i])fout<<i<<" ";
    }
}

int main()
{
Citire();
Rezolva();
Afisare();
f.close();
fout.close();
return 0;
}

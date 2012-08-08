#include<fstream>
#define inf "raft.in"
#define outf "raft.out"
#define MaxS 100
#define MaxN 100
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int sume[MaxS];
int alege[MaxS];
int v[MaxN];
int s,n;

void Citire()
{
f>>s>>n;
for(int i=1;i<=n;i++)f>>v[i];
}

void Rezolvare()
{
int sume1[MaxS]={};
for(int i=1;i<=n;i++)
    {
    sume1[v[i]]=1;
    for(int j=1;j<=s;j++)
        {
        if(sume[j]==1)
            {
            sume1[j+v[i]]=1;
            }
        }
    for(int j=1;j<=s;j++)
        {
        if(sume[j]==0 && sume1[j]==1)
            {
            sume[j]=1;
            alege[j]=v[i];
            sume1[j]=0;
            }
        }
    }
}

void Afisare()
{
if(sume[s])
    {
    while(s>0)
        {
        g<<alege[s]<<" ";
        s-=alege[s];
        }
    }
else g<<"Suma nu poate fi alcatuita";
}

int main()
{
Citire();
Rezolvare();
Afisare();
f.close();
g.close();
return 0;
}

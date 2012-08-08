#include<fstream>
using namespace std;

fstream f("grafbipartit.in",ios::in),g("grafbipartit.out",ios::out);

int MA[50][50],s[50],marc[50],n,bipartit=1;

void Citire()
{
f>>n;
int i,j;
while(f>>i>>j)
    {
    MA[i][j]=MA[j][i]=1;
    }
}

void DF_Bipartit(int nod,int val)
{
s[nod]=1;marc[nod]=val;val*=-1;
int k;
for(int k=1;k<=n;k++)
    {
    if(MA[nod][k]==1)
        {
        if(s[k]==0)DF_Bipartit(k,val);
        else
            {
            if(marc[k]!=val)bipartit=0;
            }
        }
    }
}

int main()
{
Citire();
DF_Bipartit(1,1);
int i;
if(bipartit)
    {
    g<<"Multimea A:"<<endl;
    for(i=1;i<=n;i++)
        {
        if(marc[i]==1)g<<i<<" ";
        }
    g<<endl<<"Multimea B:"<<endl;
    for(i=1;i<=n;i++)
        {
        if(marc[i]==-1)g<<i<<" ";
        }
    }
f.close();
g.close();
return 0;
}

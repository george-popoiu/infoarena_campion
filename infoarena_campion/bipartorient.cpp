#include<fstream>
#include<iostream>
#define inf "bipartorient.in"
#define outf "bipartorient.out"
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int ma[50][50],n,marc[50],s[50],bipartit=1;

void citire()
{
f>>n;
int i,j;
while(f>>i>>j)
    {
    ma[i][j]=1;
    }
}

void df(int nod,int v)
{
int k;
for(k=1;k<=n;k++)
    {
    if(ma[nod][k]==1)
        {
        if(s[k]==0)
            {
            marc[nod]=v;
            s[nod]=1;
            s[k]=1;
            marc[k]=v*(-1);
            df(k,v*(-1));
            }
        else
            {
            if( marc[k]!=(v*(-1)) ) bipartit=0;
            else {marc[nod]=v;s[nod]=1;}
            }
        }
    }
}

int main()
{
citire();
int gasit=0;
do
    {
    gasit=0;
    for(int i=1;i<=n;i++)
        {
        if(marc[i]==0 && s[i]==0)
            {
            gasit=1;
            df(i,1);
            }
        }
    }
while(gasit);
if(bipartit==1)
    {
    g<<"DA"<<endl;
    for(int i=1;i<=n;i++)
        if(marc[i]==1)g<<i<<" ";
    g<<endl;
    for(int i=1;i<=n;i++)
        if(marc[i]==-1)g<<i<<" ";
    }
else g<<"NU";
f.close();
g.close();
return 0;
}

#include<fstream>
using namespace std;

fstream f("grafeulerian.in",ios::in),g("grafeulerian.out",ios::out);

int MA[50][50],eul[100],n,sf,ind;

void Citire()
{
f>>n;
int i,j;
while(f>>i>>j)
    {
    MA[i][j]=MA[j][i]=1;
    }
}

void unCiclu(int ind)
{
int k;
for(k=1;k<=n;k++)
    {
    if(MA[eul[ind]][k]==1)
        {
        MA[eul[ind]][k]=MA[k][eul[ind]]=0;
        sf++;
        for(int i=sf;i>ind;i--)eul[i]=eul[i-1];
        eul[++ind]=k;
        unCiclu(ind);
        }
    }
}

int main()
{
Citire();
eul[1]=1;
sf=1;
for(int i=1;eul[i];i++)
    {
    unCiclu(i);
    }
for(int i=1;i<=sf;i++)g<<eul[i]<<" ";
f.close();
g.close();
return 0;
}

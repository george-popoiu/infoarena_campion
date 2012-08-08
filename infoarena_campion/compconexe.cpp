#include<fstream>
using namespace std;

fstream f("compconexe.in",ios::in),g("compconexe.out",ios::out);

int MA[50][50],s[50],N;

void Citire()
{
int i,j;
f>>N;
while(f>>i>>j)
    {
    MA[i][j]=MA[j][j]=1;
    }
}

void DF(int nod)
{
int k;
s[nod]=1;
g<<nod<<" ";
for(k=1;k<=N;k++)
    {
    if(MA[nod][k]==1 && s[k]==0)DF(k);
    }
}

int main()
{
Citire();
for(int i=1;i<=N;i++)
    {
    if(s[i]==0)
        {
        g<<"Componenta conexa"<<endl;
        DF(i);
        g<<endl;
        }
    }
f.close();
g.close();
return 0;
}

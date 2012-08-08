#include<fstream>
#define HMax 30003
#define CMax 10002

using namespace std;

fstream f("chick.in",ios::in),g("chick.out",ios::out);

int CIMin[HMax][CMax],H,C,Cost[HMax][CMax],V[CMax];

void Citire()
{
int i;
f>>C;
for(i=1;i<=C;i++)f>>V[i];
}

void Rezolvare()
{
int i,j;
//Initializare
for(i=1;i<=V[1];i++)
    for(j=1;j<=C;j++)
        {
        if(i<=V[j])CIMin[i][j]=-1;
        }
}

void Afisare(){}

int main()
{
Citire();
Rezolvare();
for(int i=1;i<=V[1];i++)
    {
    for(int j=1;j<=C;j++)g<<CIMin[i][j]<<" ";
    g<<endl;
    }
f.close();
g.close();
return 0;
}

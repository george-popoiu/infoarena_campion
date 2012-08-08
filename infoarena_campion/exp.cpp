#include<fstream>
#define MaxN 80001
#define MaxNumber 30001
#define inf "exp.in"
#define outf "exp.out"
using namespace std;

int V[MaxN],putere[MaxNumber],M,N;

void Descompune(int nr)
{
int i=2;
do
    {
    while(nr%i==0)
        {
        putere[i]++;
        nr/=i;
        }
    i++;
    }
while(nr!=1);
}

void Citire()
{
fstream f(inf,ios::in);
f>>M>>N;
for(int i=1;i<=N;i++)f>>V[i];
f.close();
}

int main()
{
int notnat=0;
Citire();
for(int i=1;i<=N;i++)Descompune(V[i]);
fstream g(outf,ios::out);
for(int i=2;i<MaxNumber;i++)
    {
    if(putere[i])
        {
        if(putere[i]%M==0)putere[i]/=M;
        else {notnat=1;break;}
        }
    }
if(notnat)g<<"0";
else
    {
    g<<"1\n";
    for(int i=2;i<MaxNumber;i++)
        {
        if(putere[i])g<<i<<" "<<putere[i]<<"\n";
        }
    }
g.close();
return 0;
}

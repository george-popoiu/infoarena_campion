#include<fstream>
#define inf "subsiruri.in"
#define outf "subsiruri.out"
#define NMax 1001
#define MODULO 9901
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int N;
int v[NMax],martor[NMax];
int best[NMax];

void Citire()
{
f>>N;
for(int i=1;i<=N;i++)f>>v[i];
}

void Rezolva()
{
int max=1,poz;
int sum=0;
for(int i=1;i<=N;i++)
    {
    best[i]=1;
    martor[i]=1;
    for(int j=1;j<i;j++)
        {
        if(v[j]<v[i] && best[i]<best[j]+1)
            {
            best[i]=best[j]+1;
            martor[i]=martor[j]%MODULO;
            martor[i]%=MODULO;
            if(max<best[i]){max=best[i];poz=i;}
            }
        else if(v[j]<v[i] && best[i]==best[j]+1)
            {
            martor[i]+=(martor[j]%MODULO);martor[i]%=MODULO;
            if(max<best[i]){max=best[i];poz=i;}
            }
        }
    }
g<<max<<"\n";
for(int i=1;i<=N;i++)
    {
    if(best[i]==max)
        {
        sum+=(martor[i]%MODULO);
        sum%=MODULO;
        }
    }
g<<sum;
}

int main()
{
Citire();
Rezolva();
f.close();
g.close();
return 0;
}

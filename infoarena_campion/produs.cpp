#include<fstream>
#define inf "produs.in"
#define outf "produs.out"
#define NMax 501
#define KMax 201
#define MINF -0x3f3f3f3f
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int pmax[NMax][KMax];
int op[NMax][KMax];//op[i][j]=t <=> pt a obtine produsul max din i cifre cu j semne de * ultimul * l-am pus dupa elementul al t-lea
int v[NMax];
int N,K,C;

void Citire();
int putere(int,int);
int CreeazaNr(int,int);
void Rezolvare();
void Afisare(int,int);

int main()
{
Citire();
Rezolvare();
Afisare(N,K);
f.close();
g.close();
return 0;
}

void Citire()
{
f>>N>>K>>C;
for(int i=1;i<=N;i++)f>>v[i];
}

int putere(int baza,int exp)
{
if(exp==0)return 1;
else if(exp==1)return baza;
else
    {
    if(exp%2==0)
        {
        int x=putere(baza,exp/2);
        return x*x;
        }
    else
        {
        return baza*putere(baza,exp-1);
        }
    }
}

int CreeazaNr(int i,int j)
{
int nr=0;
for(int t=i;t<=j;t++)
    {
    nr+=(v[t]*putere(10,j-t));
    }
return nr;
}

void Rezolvare()
{
for(int i=1;i<=C;i++)pmax[i][0]=CreeazaNr(1,i);
for(int i=2;i<=N;i++)
    {
    for(int j=1;j<i && j<=K;j++)
        {
        pmax[i][j]=MINF;
        int t=i-C;
        if(t<1)t=1;
        for(;t<i;t++)
            {
            if(pmax[i][j]<pmax[t][j-1]*CreeazaNr(t+1,i))
                {
                pmax[i][j]=pmax[t][j-1]*CreeazaNr(t+1,i);
                op[i][j]=t;
                }
            }
        }
    }
//g<<pmax[N][K]<<"\n";
}

void Afisare(int i,int j)
{
if(j>=0)
    {
    Afisare(op[i][j],j-1);
    if(j>0)g<<"*";
    for(int k=op[i][j]+1;k<=i;k++)g<<v[k];
    }
}

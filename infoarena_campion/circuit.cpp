#include<fstream>
#include<iostream>
#include<stdlib.h>
#define inf "circuit.in"
#define outf "circuit.out"
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int MA[50][50];
int N,K;
int T[50];
int s[50];
int aux;

void Citire()
{
f>>N>>K;
int i,j;
while(f>>i>>j)
    {
    MA[i][j]=1;
    }
}

void Drum(int nod)
{
int a[50];
int ind=1;
aux=nod;
while(aux)
    {
    a[ind++]=aux;
    aux=T[aux];
    }
for(int i=ind-1;i>=1;i--)g<<a[i]<<" ";
//exit(EXIT_SUCCESS);
}

void DF(int nod)
{
int i;
if(nod==K && s[K]==1){aux=T[K];T[K]=0;;Drum(aux);g<<K<<endl;}
s[nod]=1;
for(i=1;i<=N;i++)
    {
    if(MA[nod][i]==1)
        {
        MA[nod][i]=0;
        T[i]=nod;
        DF(i);
        MA[nod][i]=1;
        //T[i]=0;
        }
    }


}

int main()
{
Citire();
DF(K);
f.close();
g.close();
return 0;
}

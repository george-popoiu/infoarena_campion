#include<fstream>
#include<iostream>
#define inf "pietre.in"
#define outf "pietre.out"
#define MaxN 1001
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int N;
int v[MaxN],l[MaxN];
int pred[MaxN];

void Citire()
{
f>>N;
for(int i=1;i<=N;i++)f>>v[i];
}

void Afisare(int poz)
{
if(poz!=0)Afisare(pred[poz]);
if(poz)g<<v[poz]<<" ";
}

void Rezolvare()
{
l[1]=1;
for(int i=2;i<=N;i++)
    {
    l[i]=1;
    for(int j=1;j<i;j++)
        {
        if(v[j]<=v[i] && l[i]<l[j]+1)
            {
            l[i]=l[j]+1;
            pred[i]=j;
            }
        }
    }
g<<l[N]<<"\n";
int max,poz;
max=l[1];
poz=1;
for(int i=2;i<=N;i++)
    {
    if(l[i]>max){max=l[i];poz=i;}
    }
Afisare(poz);
}

int main()
{
Citire();
Rezolvare();
f.close();
g.close();
return 0;
}

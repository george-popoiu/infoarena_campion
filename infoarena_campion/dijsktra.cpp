#include<fstream>
#include<iostream>
#define inf "dijkstra.in"
#define outf "dijkstra.out"
#define PINF 0x3f3f3f3f
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int MP[50][50];
int s[50];
int N,K,P;
int S[50],D[50],T[50];

void Citire()
{
int i,j,c;
f>>N>>K>>P;
for(i=1;i<=N;i++)
    {
    for(j=1;j<=N;j++)
        {
        if(i==j)MP[i][j]=0;
        else MP[i][j]=PINF;
        }
    }
while(f>>i>>j>>c)
    {
    MP[i][j]=c;
    }
}

void Drum(int a)
{
if(T[a])Drum(T[a]);
g<<a<<" ";
}

int main()
{
int min,poz;
Citire();
S[K]=1;
for(int i=1;i<=N;i++)
    {
    D[i]=MP[K][i];
    if(i!=K)
        if(MP[K][i]<PINF)T[i]=K;
    }
for(int i=1;i<=N-1;i++)
    {
    min=PINF;
    for(int j=1;j<=N;j++)
        {
        if(S[j]==0)
            {
            if(D[j]<min)
                {
                min=D[j];
                poz=j;
                }
            }
        }
    S[poz]=1;
    for(int j=1;j<=N;j++)
        {
        if(D[j]>D[poz]+MP[poz][j])
            {
            D[j]=D[poz]+MP[poz][j];
            T[j]=poz;
            }
        }
    }
if(T[P])
    {
    g<<D[P]<<endl;
    Drum(P);
    }
else g<<"NU SE POATE";
f.close();
g.close();
return 0;
}

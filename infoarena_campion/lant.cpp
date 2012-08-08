#include<fstream>
#include<string.h>
#define inf "lant.in"
#define outf "lant.out"
#define LMax 31
#define NrMax 151
#define PINF 0x3f3f3f3f
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int K,Nr;
int A[NrMax][NrMax]; // A[i][j]=1 daca dist lev dintre cuvantul i si j este <=k
char Cuv[NrMax][LMax];
int nr[NrMax];

void AdaugaCuvant(char *p)
{
for(int i=0;p[i];i++)Cuv[Nr][i]=p[i];
}

void Citire()
{
char sir[1000];
char *p;
f>>K;
f.get();
while(!f.eof())
    {
    *sir=NULL;
    f.get(sir,1000);
    f.get();
    p=strtok(sir," ,.:?;!-");
    while(p)
        {
        Nr++;
        AdaugaCuvant(p);
        p=strtok(NULL," ,.:?;!-");
        }
    }
}

int Levenstein(char *x,char *y)
{
int cost[LMax][LMax];
int N,M;
N=strlen(x+1);
M=strlen(y+1);
for(int i=N;i>=1;i--)cost[i][M+1]=N-i+1;
for(int i=M;i>=1;i--)cost[N+1][i]=M-i+1;
for(int i=N;i>=1;i--)
    {
    for(int j=M;j>=1;j--)
        {
        cost[i][j]=PINF;
        if(x[i]==y[j])cost[i][j]=cost[i+1][j+1];
        if(cost[i][j]>1+cost[i+1][j])cost[i][j]=1+cost[i+1][j];
        if(cost[i][j]>1+cost[i][j+1])cost[i][j]=1+cost[i][j+1];
        }
    }
return cost[1][1];
}

void ConstrA()
{
for(int i=1;i<Nr;i++)
    for(int j=i+1;j<=Nr;j++)
        if(Levenstein(Cuv[i],Cuv[j])<=K)
            {
            A[i][0]++;
            A[i][A[i][0]]=j;
            }
}

void Numara(int vf)
{
int i;
if(!A[vf][0]){nr[vf]=1;return;}
long int s=0;
for(i=1;i<=A[vf][0];i++)
    {
    if(nr[A[vf][i]]==0)Numara(A[vf][i]);
    s+=nr[A[vf][i]];
    }
nr[vf]=s;
}

int main()
{
Citire();
ConstrA();
Numara(1);
g<<nr[1];
//g<<Levenstein(Cuv[1],Cuv[2]);
//for(int i=1;i<=Nr;i++)g<<Cuv[i]<<"\n";
f.close();
g.close();
return 0;
}

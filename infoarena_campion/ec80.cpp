//descompunerea unui graf orientat fara circuite pe nivele
#include<fstream>
#include<stdlib.h>
#define inf "ec80.in"
#define outf "ec80.out"
#define NMax 101
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int gr[NMax];//gr[i]=gradul interior al nodului i;gr[i]=-1<=> a fost scos din graf
int nivel[NMax];//nivel[i]=nivelul pe care se afla nodul i
int *a[NMax];
int N,M;
int nr;//nivelul curent

void Citire()
{
int x,y;
f>>N>>M;
for(int i=1;i<=N;i++)a[i]=(int *)realloc(a[i],sizeof(int));
for(int i=1;i<=M;i++)
    {
    f>>x>>y;
    a[x][0]++;
    a[x]=(int *)realloc(a[x],(a[x][0]+1)*sizeof(int));
    a[x][a[x][0]]=y;
    gr[y]++;
    }
}

void Rezolvare()
{
int total=0;
while(total<N)
    {
    nr++;
    for(int i=1;i<=N;i++)
        if(!gr[i])
            {
            nivel[i]=nr;
            total++;
            }
    for(int i=1;i<=N;i++)
        if(nivel[i]==nr)
            {
            gr[i]=-1;
            for(int j=1;j<=a[i][0];j++)gr[a[i][j]]--;
            }
    }
for(int i=1;i<=N;i++)g<<nivel[i]<<" ";
}

int main()
{
Citire();
Rezolvare();
f.close();
g.close();
return 0;
}

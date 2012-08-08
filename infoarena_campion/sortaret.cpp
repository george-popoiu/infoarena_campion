#include<fstream>
#include<stdlib.h>
#define inf "sortaret.in"
#define outf "sortaret.out"
#define NMax 50010
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int postord[NMax];
int viz[NMax];
int *a[NMax];
int nr,N,M;

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
    }
}

void DFS(int s)
{
viz[s]=1;
for(int i=1;i<=a[s][0];i++)
    if(!viz[a[s][i]])DFS(a[s][i]);
postord[++nr]=s;
}

void Rezolvare()
{
for(int i=1;i<=N;i++)
    if(!viz[i])DFS(i);
for(int i=N;i>=1;i--)g<<postord[i]<<" ";
}

int main()
{
Citire();
Rezolvare();
f.close();
g.close();
return 0;
}

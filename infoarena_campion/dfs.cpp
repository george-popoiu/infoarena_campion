#include<fstream>
#define inf "dfs.in"
#define outf "dfs.out"
#define GradMax 50000001
# define MaxN 100001
using namespace std;

int LA[2][GradMax],s[MaxN],N,M,Nr,Start[MaxN];

void Citire()
{
fstream f(inf,ios::in);
f>>N>>M;
int i,j,k=0;
while(f>>i>>j)
    {
    k++;
    LA[1][k]=j;
    LA[0][k]=Start[i];
    Start[i]=k;
    k++;
    LA[1][k]=i;
    LA[0][k]=Start[j];
    Start[j]=k;
    }
f.close();
}

void DFS(int nod)
{
int k;
s[nod]=1;
k=Start[nod];
while(k)
    {
    if(s[LA[1][k]]==0)DFS(LA[1][k]);
    k=LA[0][k];
    }
}

int main()
{
Citire();
for(int i=1;i<=N;i++)
    {
    if(s[i]==0){Nr++;DFS(i);}
    }
fstream g(outf,ios::out);
g<<Nr;
g.close();
return 0;
}

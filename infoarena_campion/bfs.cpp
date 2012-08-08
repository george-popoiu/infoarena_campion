#include<fstream>
#include<iostream>
#define inf "bfs.in"
#define outf "bfs.out"
#define MaxNods 100001
#define ListLenght 2000001
using namespace std;

int N,M,S,LA[2][ListLenght],Start[MaxNods],s[MaxNods],Cost[MaxNods],Coada[MaxNods],i_c=1,s_c=1,used[MaxNods];

void Citire()
{
fstream f(inf,ios::in);
int i,j,k=0;
f>>N>>M>>S;
while(f>>i>>j)
    {
    if( (used[i]&&used[j]) && (i!=j)){}else{
    used[i]=1;used[j]=1;
    k++;
    LA[1][k]=j;
    LA[0][k]=Start[i];
    Start[i]=k;
    k++;
    LA[1][k]=i;
    LA[0][k]=Start[j];
    Start[j]=k;}
    }
f.close();
}

void BFS()
{
int aux;
while(i_c<=s_c)
    {
    aux=Start[Coada[i_c]];
    while(aux)
        {
        if(s[LA[1][aux]]==0)
            {
            s_c++;
            Coada[s_c]=LA[1][aux];
            s[LA[1][aux]]=1;
            Cost[LA[1][aux]]=1+Cost[Coada[i_c]];
            }
        aux=LA[0][aux];
        }
    i_c++;
    }
}

int main()
{
Citire();
s[S]=1;
Cost[S]=0;
Coada[i_c]=S;
BFS();
fstream g(outf,ios::out);
for(int i=1;i<=N;i++)
    {
    if(Cost[i]==0 && i!=S)Cost[i]=-1;
    }
for(int i=1;i<=N;i++)g<<Cost[i]<<" ";
g.close();
return 0;
}

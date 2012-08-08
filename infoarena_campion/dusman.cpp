#include<fstream>
#include<stdlib.h>
#define inf "dusman.in"
#define outf "dusman.out"
#define MaxN 1001
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int MA[MaxN][MaxN];
int st[MaxN],k;
int N,S,M,sol=0;

void Citire()
{
f>>N>>S>>M;
int i,j;
while(f>>i>>j)
    {
    MA[i][j]=1;
    MA[j][i]=1;
    }
}

void Tipar(){for(int i=1;i<=N;i++)g<<st[i]<<" ";}

void Init(){st[k]=0;}

int Succesor()
{
if(st[k]<N)
    {
    st[k]++;
    return 1;
    }
return 0;
}

int Valid()
{
if( k!=1 && MA[st[k-1]][st[k]] ==1 )return 0;
for(int i=1;i<k;i++)
    {
    if(st[i]==st[k])return 0;
    }
return 1;
}

int Solutie()
{
return (k==N);
}

void Back()
{
int AS;
k=1;
Init();
while(k>0)
    {
    do{} while ( (AS=Succesor()) && !Valid() );
    if(AS)
        {
        if(Solutie())
            {
            sol++;
            if(sol==S)
                {
                Tipar();
                exit(EXIT_SUCCESS);
                }
            }
        else {k++;Init();}
        }
    else k--;
    }
}

int main()
{
Citire();
Back();
f.close();
g.close();
return 0;
}

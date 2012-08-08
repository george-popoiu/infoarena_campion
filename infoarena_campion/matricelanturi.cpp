#include<fstream>
#define inf "matricelanturi.in"
#define outf "matricelanturi.out"
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int L[50][50];//Matrice lanturi
int LA[2][50]; // Lista de adiacenta
int Start[50];//Start[i]=indicele coloanei la care incepe lista nodurilor adiacente in matricea LA
int coada[50],i_c=1,s_c=1;
int N;//nr noduri
int s[50];

void Citire()
{
f>>N;
int i,j;
int k=0;
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
}

void InitS()
{
for(int i=1;i<50;i++)s[i]=0;
i_c=1;
s_c=1;
}

void BF(int nod)
{
InitS();
int p;
coada[i_c]=nod;
s[nod]=1;
while(i_c<=s_c)
    {
    p=Start[coada[i_c]];
    while(p)
        {
        if(s[LA[1][p]]==0)
            {
            s_c++;
            s[LA[1][p]]=1;
            coada[s_c]=LA[1][p];
            L[nod][LA[1][p]]=1;
            }
        p=LA[0][p];
        }
    i_c++;
    }
}

int main()
{
Citire();
for(int i=1;i<=N;i++)BF(i);
for(int i=1;i<=N;i++)
    {
    for(int j=1;j<=N;j++)g<<L[i][j]<<" ";
    g<<endl;
    }
f.close();
g.close();
return 0;
}

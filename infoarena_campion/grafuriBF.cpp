#include<fstream>
#define inf "grafuriBF.in"
#define outf "grafuriBF.out"
using namespace std;

int N,coada[50],s[50],LA[2][50],Start[50],i_c=1,s_c=1,p,MA[50][50];

void Citire()
{
fstream f(inf,ios::in);
f>>N;
int i,j,k=0;
while(f>>i>>j)
    {
    k++;
    LA[0][k]=j;
    LA[1][k]=Start[i];
    Start[i]=k;
    k++;
    LA[0][k]=i;
    LA[1][k]=Start[j];
    Start[j]=k;
    }
f.close();
}

void BFLA(int nod)
{
fstream g(outf,ios::out);
coada[i_c]=nod;
s[nod]=1;
while(i_c<=s_c)
    {
    p=Start[coada[i_c]];
    while(p)
        {
        if(s[LA[0][p]]==0)
            {
            s_c++;
            coada[s_c]=LA[0][p];
            s[LA[0][p]]=1;
            }
        p=LA[1][p];
        }
    g<<coada[i_c]<<" ";
    i_c++;
    }
g.close();
}

void CitireMA()
{
fstream f(inf,ios::in);
int i,j;
f>>N;
while(f>>i>>j)
    {
    MA[i][j]=MA[j][i]=1;
    }
f.close();
}

void BFMA(int nod)
{
fstream g(outf,ios::out);
int i;
s[nod]=1;
coada[i_c]=nod;
while(i_c<=s_c)
    {
    for(int i=1;i<=N;i++)
        {
        if(MA[coada[i_c]][i]==1 && s[i]==0)
            {
            s_c++;
            coada[s_c]=i;
            s[i]=1;
            }
        }
    g<<coada[i_c]<<" ";
    i_c++;
    }
g.close();
}


int main()
{
//Citire();
//BFLA(6);
CitireMA();
BFMA(6);
/*for(int i=1;i<=N;i++)
    {
    g<<"Lista nodurilor adiacente cu "<< i<<" :";
    p=Start[i];
    while(p)
        {
        g<<LA[0][p]<<" ";
        p=LA[1][p];
        }
    g<<endl;
    }*/
return 0;
}

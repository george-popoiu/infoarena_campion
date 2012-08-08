#include<fstream>
using namespace std;

void CitireMatAd(char * filename,int MatAd[50][50],int * N)
{
fstream f(filename,ios::in);
f>>*N;
int i,j;
while(f>>i>>j)
    {
    MatAd[i][j]=MatAd[j][i]=1;
    }
f.close();
}

void AfisareMatAd(char * filename,int MatAd[50][50],int N)
{
fstream g(filename,ios::out);
for(int i=1;i<=N;i++)
    {
    for(int j=1;j<=N;j++)g<<MatAd[i][j]<<" ";
    g<<endl;
    }
g.close();
}

void CitireLAStatic(char * filename,int LA[2][50],int Start[50],int * N)
{
fstream f(filename,ios::in);
int k=0,i,j;
f>>*N;
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

void AfisareLAStatic(char * filename,int LA[2][50],int Start[50],int N)
{
fstream g(filename,ios::out);
int aux;
for(int i=1;i<=N;i++)
    {
    g<<"Lista nodurilor adiacente cu "<<i<<":";
    aux=Start[i];
    while(aux)
        {
        g<<LA[0][aux]<<" ";
        aux=LA[1][aux];
        }
    g<<endl;
    }
g.close();
}

struct Nod
{
int nd;
Nod* adr_urm;
};

void CitireLADinamic(char * filename,Nod* LA[50],int * N)
{
fstream f(filename,ios::in);
int i,j;
Nod * p;
f>>*N;
while(f>>i>>j)
    {
    p=new Nod;
    p->adr_urm=LA[i];
    p->nd=j;
    LA[i]=p;
    p=new Nod;
    p->adr_urm=LA[j];
    p->nd=i;
    LA[j]=p;
    }
f.close();
}

void AfisareLADinamic(char * filename,Nod* LA[50],int N)
{
fstream g(filename,ios::out);
for(int i=1;i<=N;i++)
    {
    g<<"Noduri adiacente cu "<<i<<" : ";
    while(LA[i])
        {
        g<<LA[i]->nd<<" ";
        LA[i]=LA[i]->adr_urm;
        }
    g<<endl;
    }
g.close();
}

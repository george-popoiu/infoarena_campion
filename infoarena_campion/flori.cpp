#include<fstream>
#define fete 151
#define flori 101
using namespace std;

fstream f("flori.in",ios::in),g("flori.out",ios::out);

int n,k,a[fete][flori],uz[fete],gr[fete];

void citire();
int exista_sol();
int valabil(int dim,int loc);
void afis(int dim);
void rezolva();

int main()
{
citire();
rezolva();
g.close();
return 0;
}

void citire()
{
int i,j,aux;
f>>n>>k;
for(i=1;i<=n;i++)
    {
    for(j=1;j<=k;j++)
        {
        f>>aux;
        a[i][aux]=1;
        }
    }
f.close();
}

int exista_sol()
{
for(int i=1;i<=n;i++)if(uz[i]==0)return 1;
return 0;
}

int valabil(int dim,int loc)
{
int i,j;
for(i=1;i<=dim;i++)
    {
    for(j=1;j<=100;j++)
        {
        if(a[gr[i]][j]==1 && a[loc][j]==1)return 1;
        }
    }
return 0;
}

void afis(int dim)
{
for(int i=1;i<=dim;i++)g<<gr[i]<<" ";
g<<endl;
}

void rezolva()
{
int i,dim;
while(exista_sol())
    {
    dim=0;
    for(i=1;i<=n;i++)
        {
        if(uz[i]==0)
            {
            if(dim==0){dim=dim+1;gr[dim]=i;uz[i]=1;}
            else
                {
                if(valabil(dim,i))
                    {
                    dim=dim+1;
                    gr[dim]=i;
                    uz[i]=1;
                    }
                }
            }
        }
    afis(dim);
    for(i=1;i<fete;i++)gr[i]=0;
    }
}

#include<fstream>
#define inf "nrminp.in"
#define outf "nrminp.out"
#define Max 101
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int N,M;
int Nr[Max][Max];
/*
Nr[i][j]=nr minim de patrate in care poate fi taiat dreptunghiul de dim i x j
Nr[i][j]=1 <=> i==j
Nr[i][j]=i*j V i,j (initializare)
Nr[i][j]=min{
    min{Nr[i][k]+Nr[i][j-k]}//taiere verticala in pozitia k
    k=1,j-1
    min{Nr[k][j]+Nr[i-k][j]}//taiere orizontala in pozitia k
    k=1,i-1
    }
*/

void Citire()
{
f>>N>>M;
}

void Rezolva()
{
for(int i=1;i<=N;i++)
    for(int j=1;j<=M;j++)
        {
        if(i==j)Nr[i][j]=1;
        else
            {
            Nr[i][j]=i*j;
            //taiere verticala
            for(int k=1;k<j;k++)
                if(Nr[i][k]+Nr[i][j-k]<Nr[i][j])Nr[i][j]=Nr[i][k]+Nr[i][j-k];
            //taiere orizontala
            for(int k=1;k<i;k++)
                if(Nr[k][j]+Nr[i-k][j]<Nr[i][j])Nr[i][j]=Nr[k][j]+Nr[i-k][j];
            }
        }
g<<Nr[N][M];
}

int main()
{
Citire();
Rezolva();
f.close();
g.close();
return 0;
}

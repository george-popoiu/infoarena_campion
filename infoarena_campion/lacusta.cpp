#include<fstream>
#define M 100
using namespace std;

fstream f("lacusta.in",ios::in),g("lacusta.out",ios::out);

int A[M][M],B[M][M],n,m,min1,min2,jmin;

void Citire();
void Rezolvare();

int main()
{
Citire();
Rezolvare();
return 0;
}

void Citire()
{
f>>m>>n;
for(int i=0;i<m;i++)
    {
    for(int j=0;j<n;j++)f>>A[i][j];
    }
f.close();
}

void Rezolvare()
{
int i,j;
for(i=0;i<n;i++)B[0][i]=32000;
B[1][0]=32000;
for(i=1;i<n;i++)B[1][i]=A[0][0]+A[0][i]+A[1][i];
for(i=1;i<m-1;i++)
    {
    if(B[i][0]<B[i][1])
        {
        min1=B[i][0];
        min2=B[i][1];
        jmin=0;
        }
    else
        {
        min1=B[i][1];
        min2=B[i][0];
        jmin=1;
        }
    for(j=2;j<n;j++)
        {
        if(B[i][j]<min1)
            {
            min2=min1;
            min1=B[i][j];
            jmin=j;
            }
        else if(B[i][j]<min2)min2=B[i][j];
        }
    for(j=0;j<n;j++)
        {
        if(j!=jmin)B[i+1][j]=min1+A[i][j]+A[i+1][j];
        else B[i+1][j]=min2+A[i][j]+A[i+1][j];
        }
    }
min1=B[m-1][0];
for(i=0;i<n-1;i++)
    {
    if(B[m-1][i]<min1)min1=B[m-1][i];
    }
g<<min1+A[m-1][n-1];
g.close();
}

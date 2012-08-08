#include<fstream>
#define MaxN 101
#define MaxM 101
#define inf "lacusta2.in"
#define outf "lacusta2.out"
using namespace std;

int mat[MaxM][MaxN],suma[MaxM][MaxN],M,N;

void Citire()
{
fstream f;
f.open(inf,ios::in);
f>>M>>N;
for(int i=1;i<=M;i++)
    for(int j=1;j<=N;j++)f>>mat[i][j];
f.close();
}

void Init()
{
for(int j=1;j<=N;j++)suma[1][j]=-1;
suma[2][1]=-1;
for(int j=2;j<=N;j++)suma[2][j]=mat[2][j]+mat[1][j]+mat[1][1];
}

void Rezolvare()
{
int min;
for(int i=3;i<=M;i++)
    {
    for(int j=1;j<=N;j++)
        {
        min=900000;
        for(int k=1;k<=N;k++)
            {
            if(k!=j && suma[i-1][k]!=-1)
                {
                if(suma[i-1][k]+mat[i-1][j]+mat[i][j]<min)
                    {
                    suma[i][j]=suma[i-1][k]+mat[i-1][j]+mat[i][j];
                    min=suma[i][j];
                    }
                }
            }
        }
    }
min=900000;
for(int j=1;j<=N-1;j++)
    {
    if(suma[M][j]+mat[M][N]<min)
        {
        suma[M][N]=suma[M][j]+mat[M][N];
        min=suma[M][N];
        }
    }
fstream f(outf,ios::out);
f<<suma[M][N];
f.close();
}

int main()
{
Citire();
Init();
Rezolvare();
return 0;
}

#include<fstream>
#include<iostream>
#define inf "matrixm.in"
#define outf "matrixm.out"
#define PINF 0x3f3f3f3f
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int Cost[100][100],Dim[100];
int N;

void Citire()
{
f>>N;
for(int i=1;i<=N+1;i++)f>>Dim[i];
}

void Rezolvare()
{
int k,l,i,j,m;
for(l=1;l<=N-1;l++)
    {
    for(i=1;i<=N-l;i++)
        {
        j=i+l;
        Cost[i][j]=PINF;
        for(k=i;k<j;k++)
            {
            m=Cost[i][k]+Cost[k+1][j]+Dim[i]*Dim[k+1]*Dim[j+1];
            if(m<Cost[i][j])Cost[i][j]=m;
            }
        }
    }
g<<Cost[1][N];
}

int main()
{
Citire();
Rezolvare();
f.close();
g.close();
return 0;
}

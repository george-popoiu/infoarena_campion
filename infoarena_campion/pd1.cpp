#include<fstream>
#include<iostream>
#define inf "pd1.in"
#define outf "pd1.out"
#define MaxN 102
#define MINF -0x3f3f3f3f
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int N;
int mat[MaxN][MaxN];
int c[MaxN][MaxN];

void Citire()
{
f>>N;
for(int i=1;i<=N;i++)
    for(int j=1;j<=N;j++)f>>mat[i][j];
//Borderare
for(int i=0;i<=N+1;i++)
    {
    c[0][i]=MINF;c[N+1][i]=MINF;
    c[i][0]=MINF;c[i][N+1]=MINF;
    }
}

int max(int a,int b,int c)
{
int m=MINF;
if(m<a)m=a;
if(m<b)m=b;
if(m<c)m=c;
return m;
}

void Rezolvare()
{
for(int i=1;i<=N;i++)c[1][i]=mat[1][i];
for(int i=2;i<=N;i++)
    {
    for(int j=1;j<=N;j++)
        {
        c[i][j]=mat[i][j]+max(c[i-1][j],c[i-1][j-1],c[i-1][j+1]);
        }
    }
int m=MINF;
for(int i=1;i<=N;i++)
    {
    if(m<c[N][i])m=c[N][i];
    }
g<<m;
}

int main()
{
Citire();
Rezolvare();
f.close();
g.close();
return 0;
}

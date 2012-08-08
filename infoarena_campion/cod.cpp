#include<fstream>
#include<string.h>
#define MaxDim 201
#define inf "cod.in"
#define outf "cod.out"
using namespace std;

int lcs[MaxDim][MaxDim],N,M;
char Cuv1[MaxDim],Cuv2[MaxDim];

void Citire()
{
fstream f(inf,ios::in);
f.get(Cuv1,MaxDim);
f.get();
f.get(Cuv2,MaxDim);
N=strlen(Cuv1);
M=strlen(Cuv2);
f.close();
}

void Rezolvare()
{
for(int i=N-1;i>=0;i--)
    {
    for(int j=M-1;j>=0;j--)
        {
        if(Cuv1[i]==Cuv2[j])lcs[i][j]=1+lcs[i+1][j+1];
        else
            {
            if(lcs[i+1][j]>lcs[i][j+1])lcs[i][j]=lcs[i+1][j];
            else lcs[i][j]=lcs[i][j+1];
            }
        }
    }
}

void Afisare()
{
int d[MaxDim];
int h=0,p=0,poz=0,ii,jj,max,haux,paux;
for(int i=lcs[0][0];i>0;i--)
    {
    max=-1;
    for(ii=h;ii<N;ii++)
        {
        for(jj=p;jj<M;jj++)
            {
            if(lcs[ii][jj]==i && Cuv1[ii]==Cuv2[jj] && Cuv1[ii]-'0'>max)
                {
                max=Cuv1[ii]-'0';
                haux=ii+1;
                paux=jj+1;
                }
            }
        }
    h=haux;
    p=paux;
    d[poz++]=max;
    }
fstream g(outf,ios::out);
for(int i=0;i<poz;i++)g<<d[i];
g.close();
}

int main()
{
Citire();
Rezolvare();
Afisare();
return 0;
}

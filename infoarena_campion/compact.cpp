#include<fstream>
#include<iostream>
#include<string.h>
#define inf "compact.in"
#define outf "compact.out"
#define PINF 0x3f3f3f3f
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

//c[i][j]=costul minim necesar codificarii sirului intre caracterele i si j, inclusiv

int m,c[100][100];
char sir[100],s[100][100];

void citire()
{
f>>m;
f.get();
for(int i=1;i<=m;i++)
    {
    f.get(s[i],100);
    f.get();
    }
f.get(sir,100);
}

int exista(int i,int j)
{
if(i==j)return 1;
char sr[100]={};
int t=0;
for(int k=i-1;k<j;k++)
    {
    sr[t]=sir[k];
    t++;
    }
for(int k=1;k<=m;k++)
    {
    if(strcmp(sr,s[k])==0)return 1;
    }
return 0;
}

void rez()
{
int j,min;
for(int i=1;i<=strlen(sir);i++)c[i][i]=1;
for(int l=1;l<=strlen(sir)-1;l++)
    {
    for(int i=1;i<=strlen(sir)-l;i++)
        {
        j=i+l;
        c[i][j]=PINF;
        if(exista(i,j)){c[i][j]=1;}
        else
            {
            for(int k=i;k<j;k++)
                {
                if(c[i][j]>c[i][k]+c[k+1][j])c[i][j]=c[i][k]+c[k+1][j];
                }
            }
        }
    }
g<<c[1][strlen(sir)];
}

int main()
{
citire();
rez();//O(n^3)
/*if(exista(4,6))g<<"Bun";
else g<<"Nu e bun";*/
f.close();
g.close();
return 0;
}

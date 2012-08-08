#include<fstream>
#define inf "grafdrumAB.in"
#define outf "grafdrumAB.out"
using namespace std;

int MA[50][50],T[50],N,A,B,s[50],coada[50],i_c=1,s_c=1;

fstream g(outf,ios::out);

void Citire()
{
fstream f(inf,ios::in);
int i,j;
f>>N>>A>>B;
while(f>>i>>j)
    {
    MA[i][j]=MA[j][i]=1;
    }
f.close();
}

void DF(int nod)
{
int k;
s[nod]=1;
for(k=1;k<=N;k++)
    {
    if(MA[nod][k]==1 && s[k]==0)
        {
        T[k]=nod;
        DF(k);
        }
    }
}

void BF(int nod)
{
coada[i_c]=nod;
s[nod]=1;
while(i_c<=s_c)
    {
    for(int i=1;i<=N;i++)
        {
        if(MA[coada[i_c]][i]==1 && s[i]==0)
            {
            s_c++;
            coada[s_c]=i;
            s[i]=1;
            T[i]=coada[i_c];
            }
        }
    i_c++;
    }
}

void Refacere(int nod)
{
if(nod!=0)
    {
    Refacere(T[nod]);
    g<<nod<<" ";
    }
}

int main()
{
Citire();
BF(A);
if(T[B]!=0)Refacere(B);
g.close();
return 0;
}

#include<fstream>
#include<string.h>
#define inf "ec_po.in"
#define outf "ec_po.out"
#define MaxN 101
#define MaxM 50
#define p3(x) ((x)*(x)*(x))
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int cmin[MaxN];
int lg[MaxN],slg[MaxN];
int ultim[MaxN];
int N,M;
char cuv[MaxN][MaxM];

void Citire()
{
f>>N>>M;
f.get();
for(int i=1;i<=N;i++)
    {
    f.get(cuv[i],MaxM);
    lg[i]=strlen(cuv[i]);
    slg[i]=lg[i]+slg[i-1];
    f.get();
    }
}

void Rezolvare()
{
cmin[N]=0;
ultim[N]=N;
for(int i=N-1;i>0;i--)
    {
    //cuvintele i,....N incap pe ultima linie?
    if(slg[N]-slg[i-1]+N-i<=M)
        {
        cmin[i]=0;
        ultim[i]=N;
        }
    else
        {
        //plasam cuvantul i singur pe linie
        cmin[i]=p3(M-lg[i])+cmin[i+1];
        ultim[i]=i;
        //incercam sa plasam cuvintele i,...,j pe acceasi linie
        for(int j=i+1;j<N;j++)
            {
            if(slg[j]-slg[i-1]+j-i>M)break;
            if(cmin[i]>p3(M-(slg[j]-slg[i-1]+j-i))+cmin[j+1] ){cmin[i]=p3(M-(slg[j]-slg[i-1]+j-i))+cmin[j+1];ultim[i]=j;}
            }
        }
    }
g<<cmin[1]<<"\n";
}

void Afis()
{
int poz=0;
while(poz+1<=N)
    {
    for(int i=poz+1;i<=ultim[poz+1];i++)g<<cuv[i]<<" ";
    g<<"\n";
    poz=ultim[poz+1];
    }
}

int main()
{
Citire();
Rezolvare();
Afis();
f.close();
g.close();
return 0;
}

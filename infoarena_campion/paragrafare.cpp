#include<fstream>
#include<string.h>
#define NMax 101
#define MMax 51
#define p3(x) ( (x) * (x) * (x) )
using namespace std;

fstream f("paragrafare.in",ios::in),g("paragrafare.out",ios::out);

int Slg[NMax],Cost[NMax],Ultim[NMax],N,M;
char C[NMax][MMax];

void Citire()
{
f>>N>>M;
f.get();
for(int i=1;i<=N;i++)
    {
    f.getline(C[i],MMax);
    Slg[i]=Slg[i-1]+strlen(C[i]);
    }
f.close();
}

void Rezolvare()
{
int i,j;
Cost[N]=0;
Ultim[N]=N;
for(i=N-1;i>0;i--)
    {
    /* cuvintele i,i+1,...,N incap pe ultima linie? */
    if( (Slg[N]-Slg[i-1]+N-i) <= M )
        {
        Cost[i]=0;
        Ultim[i]=N;
        }
    else
        {
        /* Cuvantul incape singur pe o linie */
        Cost[i]=p3(M-(Slg[i]-Slg[i-1]))+Cost[i+1];
        Ultim[i]=i;
        for(j=i+1;j<N;j++)
            {
            if( Slg[j]-Slg[i-1]+j-i > M ) // Daca nu incap
                break;
            if( Cost[i] > p3(M-(Slg[j]-Slg[i-1]+j-i)) + Cost[j+1] )
                {
                Cost[i]=p3(M-(Slg[j]-Slg[i-1]+j-i)) + Cost[j+1];
                Ultim[i]=j;
                }
            }
        }
    }
}

void Afisare()
{
int poz=0;
g<<Cost[1]<<endl;
while(poz+1<=N)
    {
    for(int j=poz+1;j<Ultim[poz+1];j++)
        {
        g<<C[j]<<" ";
        }
    g<<C[Ultim[poz+1]]<<endl;
    poz=Ultim[poz+1];
    }
g.close();
}

int main()
{
Citire();
Rezolvare();
Afisare();
return 0;
}

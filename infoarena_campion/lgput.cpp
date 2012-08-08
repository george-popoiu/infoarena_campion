#include<fstream>
#define inf "lgput.in"
#define outf "lgput.out"
#define NR 1999999973
#define p2(x) ((x)*(x))
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

unsigned long long N,P;

void Citire()
{
f>>N>>P;
}

unsigned long long Putere(unsigned long long p)
{
if(p==2)return N*N;
else
    {
    if(p%2==0)
        {
        unsigned long long x=Putere(p/2)%NR;
        return ((x%NR)*(x%NR))%NR;
        }
    else return (N*Putere(p-1))%NR;
    }
}

int main()
{
Citire();
if(N==0)
    {
    g<<"0";
    return 0;
    }
if(N==1 || P==0)
    {
    g<<"1";
    return 0;
    }
if(N%NR==0)
    {
    g<<"0";
    return 0;
    }
N%=NR;
g<<Putere(P)%NR;
f.close();
g.close();
return 0;
}

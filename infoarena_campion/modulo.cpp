#include<fstream>
#define inf "modulo.in"
#define outf "modulo.out"
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

unsigned long long A,B,C;

void Citire()
{
f>>A>>B>>C;
}

unsigned long long Putere(unsigned long long p)
{
if(p==2)return A*A;
else
    {
    if(p%2==1)return (A*Putere(p-1))%C;
    else
        {
        unsigned long long x=Putere(p/2)%C;
        return ((x%C)*(x%C))%C;
        }
    }
}

int main()
{
Citire();
if(A==0)
    {
    g<<"0";
    return 0;
    }
if(A==1 || B==0)
    {
    g<<"1";
    return 0;
    }
if(A%C==0)
    {
    g<<"0";
    return 0;
    }
A%=C;
g<<Putere(B)%C;
f.close();
g.close();
return 0;
}

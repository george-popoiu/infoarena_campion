#include<fstream>
#define inf "fructe.in"
#define outf "fructe.out"
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int T,P,B;

void Citeste()
{
f>>T;
for(int i=1;i<=T;i++)
    {
    f>>P>>B;
    if(B%2==0)g<<"0\n";
    else g<<"1\n";
    }
}

int main()
{
Citeste();
f.close();
g.close();
return 0;
}

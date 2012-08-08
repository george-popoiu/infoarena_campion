#include "grafuri.cpp"
#define inf "grafuri731.in"
#define outf "grafuri731.out"
using namespace std;

Nod* LA[50];
int N;

int main()
{
CitireLADinamic(inf,LA,&N);
AfisareLADinamic(outf,LA,N);
return 0;
}

#include<fstream>
#define inf "avere.in"
#define outf "avere.out"
#define SMax 701
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int c[SMax][SMax];
int S;

void Rezolvare()
{
f>>S;
c[0][0]=1;
for(int v=1;v<=S;v++)
    for(int x=1;x<=(v*(v+1))/2;x++)c[v][x]=c[v-1][x]+c[v-1][x-v];
g<<c[S][S];
}

int main()
{
Rezolvare();
f.close();
g.close();
return 0;
}

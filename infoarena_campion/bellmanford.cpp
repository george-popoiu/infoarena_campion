#include<fstream>
#define inf "bellmanford.in"
#define outf "bellmanford.out"
#define INF 100000000000000000LL
#define NMax 50010
#define MMax 250010
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

struct muchie
{
int x,y,c;
};

int N,M;
int d[NMax];
muchie e[MMax];

void Citire()
{
f>>N>>M;
for(int i=1;i<=M;i++)f>>e[i].x>>e[i].y>>e[i].c;
}

void init()
{
d[1]=0;
for(int i=2;i<=N;i++)d[i]=INF;
}

void Rezolva()
{
for(int i=1;i<=N;i++)
    {
    for(int j=1;j<=M;j++)
        if(d[e[j].y]>d[e[j].x]+e[j].c)d[e[j].y]=d[e[j].x]+e[j].c;
    }
}

bool negativ()
{
for(int i=1;i<=M;i++)
    if(d[e[i].y]>d[e[i].x]+e[i].c)return true;
return false;
}

void Afisare(){for(int i=2;i<=N;i++)g<<d[i]<<" ";}

int main()
{
Citire();
init();
Rezolva();
if(negativ())g<<"Ciclu negativ!\n";
else Afisare();
f.close();
g.close();
return 0;
}

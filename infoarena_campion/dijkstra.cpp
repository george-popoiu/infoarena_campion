#include<fstream>
#define inf "dijkstra.in"
#define outf "dijkstra.out"
#define NMax 50010
#define INF 0x3f3f3f3f
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

struct graf
{
int nod,cost;
graf *next;
};

int N,M;
graf *a[NMax];
int d[NMax],s[NMax];

void add(int unde,int nd,int cst)
{
graf *c=new graf;
c->nod=nd;
c->cost=cst;
c->next=a[unde];
a[unde]=c;
}

void Citire()
{
int x,y,z;
f>>N>>M;
for(int i=1;i<=M;i++)
    {
    f>>x>>y>>z;
    add(x,y,z);
    }
for(int i=1;i<=N;i++)d[i]=INF;
}

void Dijkstra()
{
d[1]=0;
int min,pmin;
for(int i=1;i<=N;i++)
    {
    min=INF;
    for(int j=1;j<=N;j++)
        {
        if(d[j]<min && !s[j]){min=d[j];pmin=j;}
        }
    s[pmin]=1;
    graf *t=a[pmin];
    while(t)
        {
        if(d[t->nod]>d[pmin]+t->cost)d[t->nod]=d[pmin]+t->cost;
        t=t->next;
        }
    }
}

void Afisare()
{
for(int i=2;i<=N;i++)
    {
    if(d[i]==INF)g<<"0 ";
    else g<<d[i]<<" ";
    }
}

int main()
{
Citire();
Dijkstra();
Afisare();
f.close();
g.close();
return 0;
}

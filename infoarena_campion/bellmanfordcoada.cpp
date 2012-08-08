#include<fstream>
#include<queue>
#define inf "bellmanford.in"
#define outf "bellmanford.out"
#define NMax 50010
#define INF 0x3f3f3f3f
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

struct graf
{
int nod;
int cost;
graf *next;
};

int d[NMax],inqueue[NMax],cntin[NMax];
int N,M;
bool neg=false;
graf *a[NMax];
queue<int> q;

void add(int x,int y,int c)
{
graf *t=new graf;
t->nod=y;
t->cost=c;
t->next=a[x];
a[x]=t;
}

void Citire()
{
int x,y,c;
f>>N>>M;
for(int i=1;i<=M;i++)
    {
    f>>x>>y>>c;
    add(x,y,c);
    }
}

void init()
{
d[1]=0;
for(int i=2;i<=N;i++)d[i]=INF;
}

void Rezolva()
{
int x;
q.push(1);
inqueue[1]=1;
while( !q.empty() && !neg )
    {
    x=q.front();
    inqueue[x]=0;
    q.pop();
    graf *t=a[x];
    while(t)
        {
        if(d[t->nod]>d[x]+t->cost)
            {
            d[t->nod]=d[x]+t->cost;
            if(!inqueue[t->nod])
                {
                if(cntin[t->nod]>N)neg=true;
                else
                    {
                    q.push(t->nod);
                    inqueue[t->nod]=1;
                    cntin[t->nod]++;
                    }
                }
            }
        t=t->next;
        }
    }
}

int main()
{
Citire();
init();
Rezolva();
if(!neg)
    {
    for(int i=2;i<=N;i++)g<<d[i]<<" ";
    }
else g<<"Ciclu negativ!";
f.close();
g.close();
return 0;
}

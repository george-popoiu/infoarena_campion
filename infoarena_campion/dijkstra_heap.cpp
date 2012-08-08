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
graf *a[NMax];//lista de adiacenta
int d[NMax];
int heap[NMax];//heap[i]=j <=> eticheta nodului i din heap este nodul j din graf
int pos[NMax];//pos[i]=j <=> nodul i din graf este eticheta nodului j din heap
int dim;//numarul de noduri din heap la un moment dat

void add(int unde,int nd,int costarc)//adaug in lista de adiacenta a nodului unde, nodul nd
{
graf *c=new graf;
c->nod=nd;
c->cost=costarc;
c->next=a[unde];
a[unde]=c;
}

void Citire()//citesc datele
{
int x,y,z;
f>>N>>M;
for(int i=1;i<=M;i++)
    {
    f>>x>>y>>z;
    add(x,y,z);
    }
for(int i=1;i<=N;i++){d[i]=INF;pos[i]=-1;}//initializez vectorul d cu INF(0x3f3f3f3f)
}

int father(int nodh){return nodh/2;}//tatal nodului nodh din heap
int lson(int nodh){return 2*nodh;}//fiul stang al nodului nodh din heap
int rson(int nodh){return 2*nodh+1;}//fiul drept al nodului nodh din heap

void upheap(int nodh)//"ridic" nodul nodh in heap
{
int tata;
while(nodh>1)
    {
    tata=nodh>>1; //nodh/2
    if(d[heap[nodh]]<d[heap[tata]])
        {
        pos[heap[nodh]]=tata;
        pos[heap[tata]]=nodh;
        swap(heap[nodh],heap[tata]);
        nodh=tata;
        }
    else break;
    }
}

void downheap(int nodh)//"cern" nodul nodh in heap
{
int f;//fiu
while(nodh<=dim)
    {
    f=nodh;
    if( (nodh<<1)<=dim )
        {
        f=nodh<<1;//nodh*2
        if(f+1<=dim && d[heap[f+1]]<d[heap[f]])f++;
        }
    else return;
    if(d[heap[f]]<d[heap[nodh]])
        {
        pos[heap[nodh]]=f;
        pos[heap[f]]=nodh;

        swap(heap[nodh],heap[f]);

        nodh=f;
        }
    else return;
    }
}

void Dijkstra()
{
int min;
dim=1;
d[1]=0;
pos[1]=1;
heap[1]=1;
while(dim)
    {
    min=heap[1];
    swap(heap[1],heap[dim]);
    pos[heap[1]]=1;
    dim--;
    downheap(1);

    graf *t=a[min];
    while(t)
        {
        if(d[t->nod]>d[min]+t->cost)
            {
            d[t->nod]=d[min]+t->cost;
            if(pos[t->nod]!=-1)upheap(pos[t->nod]);
            else
                {
                heap[++dim]=t->nod;
                pos[heap[dim]]=dim;
                upheap(dim);
                }
            }
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

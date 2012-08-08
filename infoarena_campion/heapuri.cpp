#include<fstream>
#define inf "heapuri.in"
#define outf "heapuri.out"
#define NMax 200010
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int Heap[NMax];//heap[i]=pozitia in v a elementului de pe nodul i
int v[NMax];//v[i]=al i-lea element
int pos[NMax];//pos[i]=pozitia in heap al celui de-al i-lea element
int N,dim;

int father(int nod){return nod/2;}
int lson(int nod){return nod*2;}
int rson(int nod){return nod*2+1;}

void percolate(int nod)
{
while(nod>1 && v[Heap[nod]]<v[Heap[father(nod)]])
    {
    swap(pos[Heap[nod]],pos[Heap[father(nod)]]);
    swap(Heap[nod],Heap[father(nod)]);
    nod=father(nod);
    }
}

void sift(int nod)
{
int son=0;
do
    {
    son=0;
    if(lson(nod)<=dim)
        {
        son=lson(nod);
        if(rson(nod)<=dim && v[Heap[rson(nod)]]<v[Heap[son]])son=rson(nod);
        }
    if(son)
        {
        swap(pos[Heap[nod]],pos[Heap[son]]);
        swap(Heap[nod],Heap[son]);
        nod=son;
        }
    }
while(son);
}

void cut(int nrord)
{
int nod=pos[nrord];
pos[Heap[dim]]=nod;
Heap[nod]=Heap[dim];
dim--;
if(v[Heap[nod]]<v[Heap[father(nod)]])percolate(nod);
else sift(nod);
}

void Citire()
{
int c,x,nr=0;
f>>N;
for(int i=1;i<=N;i++)
    {
    f>>c;
    if(c==1)
        {
        f>>x;
        v[++nr]=x;
        dim++;
        pos[nr]=dim;
        Heap[dim]=nr;
        percolate(dim);
        }
    else if(c==2)
        {
        f>>x;
        cut(x);
        }
    else g<<v[Heap[1]]<<"\n";
    }
}

int main()
{
Citire();
/*g<<N<<"\n";
for(int i=1;i<=dim;i++)g<<v[Heap[i]]<<" ";*/
f.close();
g.close();
return 0;
}

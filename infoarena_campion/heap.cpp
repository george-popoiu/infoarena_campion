#include<fstream>
#define NMax 200001
#define inf "heap.in"
#define outf "heap.out"
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

typedef int Heap[NMax];
Heap H;
int N;

int father(int nod)
{
return nod/2;
}

int left_son(int nod)
{
return nod*2;
}

int right_son(int nod)
{
return nod*2+1;
}

int maxim(Heap H)
{
return H[1];
}

void sift(Heap H,int N,int K)//"cerne"
{
int son;
do
    {
    son=0;
    if(left_son(K)<=N)
        {
        son=left_son(K);
        if(right_son(K)<=N && H[son]<H[right_son(K)])son=right_son(K);
        if(H[son]<=H[K])son=0;
        }
    if(!son)
        {
        swap(H[K],H[son]); // functie din STL ce interschimba continutul a 2 variabile
        K=son;
        }
    }
while(son);
}

void percolate(Heap H,int N,int K)//"infiltrare"
{
int key=H[K];
while( (K>1) && (key>H[father(K)]) )
    {
    H[K]=H[father(K)];
    K=father(K);
    }
H[K]=key;
}

void build_heap(Heap H,int N)
{
for(int i=N/2;i>0;i--)sift(H,N,i);
}

void cut(Heap H,int& N,int K)
{
H[K]=H[N];
N--;
if((K>1) && (H[K]>H[father(K)]))percolate(H,N,K);
else sift(H,N,K);
}

void insert(Heap H,int& N,int key)
{
H[++N]=key;
percolate(H,N,N);
}

void heapsort(Heap H,int N)
{
for(int i=N;i>=2;i--)
    {
    swap(H[1],H[i]);
    sift(H,i-1,1);
    }
}

int main()
{
f.close();
g.close();
return 0;
}

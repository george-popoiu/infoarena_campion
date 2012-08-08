#include<fstream>
#include<list>
#include<algorithm>
#define inf "trilant.in"
#define outf "trilant.out"
#define NMax 100010
#define INF 100000000000000000LL
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int N,M,A,B,C,X;
int Heap[NMax],hdim;
long long int dA[NMax],dB[NMax],dC[NMax];
int TA[2][NMax],TB[2][NMax],TC[2][NMax];
int poz[NMax];//poz[i]=j <=> nodul i din graf se afla pe nodul j din heap ; -1 <=> nu este in heap
list< pair<int,long long int> > G[NMax]; //lista de adiacenta

void Citire()
{
int x,y,c;
f>>N>>M>>A>>B>>C;
for(int i=1;i<=M;i++)
    {
    f>>x>>y>>c;
    G[x].push_back( make_pair(y,c) );
    G[y].push_back( make_pair(x,c) );
    }
}

void init(long long int d[NMax],int poz[NMax])
{
for(int i=1;i<=N;i++)
    {
    d[i]=INF;
    poz[i]=-1;
    }
}

void downheap(int nodh,long long int d[NMax])
{
int son;
do
    {
    son=0;
    if( (nodh<<1) <= hdim )
        {
        son=(nodh<<1);
        if( son+1<=hdim && d[Heap[son]] > d[Heap[son+1]] ) son=son+1;
        if( d[Heap[nodh]] > d[Heap[son]] )
            {
            poz[Heap[son]]=nodh;
            poz[Heap[nodh]]=son;
            swap(Heap[son],Heap[nodh]);

            nodh=son;
            }
        else son=0;
        }
    }
while(son);
}

void upheap(int nodh,long long int d[NMax])
{
int f;
while(nodh>1)
    {
    f=(nodh>>1);
    if( d[Heap[f]] > d[Heap[nodh]] )
        {
        poz[Heap[nodh]]=f;
        poz[Heap[f]]=nodh;
        swap(Heap[f],Heap[nodh]);
        nodh=f;
        }
    else nodh=1;
    }
}

void Dijkstra(int s,long long int d[NMax],int T[2][NMax])
{
int t;
init(d,poz);
d[s]=0;
T[1][s]=0;//predecesorul
T[0][s]=1;//numarul de noduri prin care am mers ca sa ajung la s
hdim=0;
Heap[++hdim]=s;
poz[s]=hdim;
while(hdim)
    {
    t=Heap[1];
    Heap[1]=Heap[hdim];
    poz[Heap[hdim]]=1;
    hdim--;

    downheap(1,d);

    for( list< pair<int,long long int> >::iterator it=G[t].begin() ; it!=G[t].end(); it++ )
        if ( d[ (*it).first ] > d[t] + (*it).second )
            {
            T[1][ (*it).first ]=t;
            T[0][ (*it).first ]=T[0][t]+1;
            d[ (*it).first ] = d[t] + (*it).second ;
            if(poz[ (*it).first ] != -1 )upheap( poz[ (*it).first ] , d);
            else
                {
                hdim++;
                Heap[hdim]=(*it).first;
                poz[ (*it).first ]=hdim;
                upheap(hdim,d);
                }
            }
    }
}

void Rezolva()
{
long long int dmin=INF;
for(int i=1;i<=N;i++)
    if( dA[i] + dB[i] + dC[i] < dmin )
        {
        dmin = dA[i] + dB[i] + dC[i] ;
        X=i;
        }
g<<dmin<<"\n";
}

void Afis(int T[2][NMax],int nod)
{
g<<nod<<" ";
while(T[1][nod])
    {
    g<<T[1][nod]<<" ";
    nod=T[1][nod];
    }
g<<"\n";
}

int main()
{
Citire();
Dijkstra(A,dA,TA);
Dijkstra(B,dB,TB);
Dijkstra(C,dC,TC);
Rezolva();
g<<TA[0][X]<<" ";
Afis(TA,X);
g<<TB[0][X]<<" ";
Afis(TB,X);
g<<TC[0][X]<<" ";
Afis(TC,X);
//g<<X;
/*for(int i=1;i<=N;i++)g<<dA[i]<<" ";
g<<"\n";
for(int i=1;i<=N;i++)g<<dB[i]<<" ";
g<<"\n";
for(int i=1;i<=N;i++)g<<dC[i]<<" ";
g<<"\n";*/
f.close();
g.close();
return 0;
}

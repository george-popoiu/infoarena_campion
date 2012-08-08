//#include<fstream>
#include<stdio.h>
#include<stdlib.h>
#define inf "quicksort.in"
#define outf "quicksort.out"
#define NMax 500001
using namespace std;

//fstream f(inf,ios::in),g(outf,ios::out);

int v[NMax];
int N;

void Citire()
{
//f>>N;
scanf("%d",&N);
for(int i=1;i<=N;i++)//f>>v[i];
    scanf("%d",&v[i]);
}

int Partition(int a[],int p,int q)
{
int pivot;
int i,j;
int aux;
int poz;
i=p-1;
pivot=a[p+rand()%(q-p+1)];
for(j=p+1;j<=q;j++)
    {
    if(a[j]<=pivot)
        {
        i++;
        aux=a[i];
        a[i]=a[j];
        a[j]=aux;
        }
    }
aux=a[p];
a[p]=a[i];
a[i]=aux;
return i;
}

void QuickSort(int a[],int p,int q)
{
int r;
if(p<q)
    {
    r=Partition(a,p,q);
    QuickSort(a,p,r-1);
    QuickSort(a,r+1,q);
    }
}

void Afisare()
{
for(int i=1;i<=N;i++)//g<<v[i]<<" ";
    printf("%d ",v[i]);
}

int main()
{
freopen(inf,"r",stdin);
freopen(outf,"w",stdout);
Citire();
QuickSort(v,1,N);
Afisare();
//f.close();
//g.close();
return 0;
}

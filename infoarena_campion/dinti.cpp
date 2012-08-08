#include<fstream>
#include<string.h>
#define inf "dinti.in"
#define outf "dinti.out"
#define MaxN 1000001
#define MaxL 21
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int v[MaxN];
int a[MaxL];
int N,M,L;

int Compute(int array[MaxL])
{
int k=1,gasit=0;
while(k<=N-L+1)
    {
    gasit=0;
    for(int i=1;i<=L;i++)
        {
        if(array[i]==1 && array[i]==v[k+i-1]){gasit=0;break;}
        else if( array[i]+v[k+i-1]<=1 ) gasit=1;
        }
    if(gasit)return 1;
    k++;
    }
return 0;
}

void Citire()
{
char sir[MaxN];
f>>N>>M>>L;
f.get();
f.get(sir,MaxN);
for(int i=0;i<strlen(sir);i++){v[i+1]=sir[i]-'0';}
f.get();
*sir=NULL;
for(int i=1;i<=M;i++)
    {
    f.get(sir,MaxL);
    for(int i=0;i<strlen(sir);i++){a[i+1]=sir[i]-'0';}
    g<<Compute(a)<<"\n";
    f.get();
    *sir=NULL;
    *a=NULL;
    }
}

int main()
{
Citire();
f.close();
g.close();
return 0;
}

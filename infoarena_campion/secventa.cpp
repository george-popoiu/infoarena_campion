#include<fstream>
#include<iostream>
#define inf "secventa.in"
#define outf "secventa.out"
#define MaxN 500001
#define MINF -0x3f3f3f3f
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int N,K;
int v[MaxN];
int q[MaxN],Front,Back;
int st,sf;

void Citire()
{
f>>N>>K;
for(int i=1;i<=N;i++)f>>v[i];
}

int main()
{
int max=MINF;
Citire();
Back=0;
Front=1;
for(int i=1;i<=N;i++)
    {
    while( Front<=Back && v[i]<v[q[Back]])Back--;
    q[++Back]=i;
    if(i>=K){
    if(v[q[Front]]>max)
        {
        max=v[q[Front]];
        st=i-K+1;
        sf=K;
        }}
    /*else if(v[q[Front]]==max)
        {
        if(q[Front]<st)
            {
            st=q[Front];
            sf=q[Back];
            }
        else if(q[Front]==st)
            {
            if(q[Back]<sf)sf=q[Back];
            }
        }}*/
    if(i-q[Front]+1==K)Front++;
    }
g<<st<<" "<<st+sf-1<<" "<<max;
f.close();
g.close();
return 0;
}

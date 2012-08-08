#include<fstream>
#include<iostream>
#define inf "vila2.in"
#define outf "vila2.out"
#define MaxN 100001
#define MINF -0x3f3f3f3f
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int v[MaxN],N,K;
int MaxQ[MaxN],MaxFront,MaxBack;
int MinQ[MaxN],MinFront,MinBack;
int DifMax=MINF;

void Citire()
{
f>>N>>K;
for(int i=1;i<=N;i++)f>>v[i];
}

int main()
{
Citire();
MaxFront=1;MaxBack=0;
MinFront=1;MinBack=0;
for(int i=1;i<=N;i++)
    {
    while( MinFront<=MinBack && v[i]<=v[MinQ[MinBack]] ) MinBack--;
    MinQ[++MinBack]=i;
    //if(MinQ[MinFront]==i-K)MinFront++;
    while( MaxFront<=MaxBack && v[i]>=v[MaxQ[MaxBack]] ) MaxBack--;
    MaxQ[++MaxBack]=i;
    //if(MaxQ[MaxFront]==i-K)MaxFront++;
    if(i>=K)
        {
        if(v[MaxQ[MaxFront]]-v[MinQ[MinFront]]>=DifMax)
            {
            DifMax=v[MaxQ[MaxFront]]-v[MinQ[MinFront]];
            }
        }
    if(MinQ[MinFront]==i-K)MinFront++;
    if(MaxQ[MaxFront]==i-K)MaxFront++;
    }
g<<DifMax;
f.close();
g.close();
return 0;
}

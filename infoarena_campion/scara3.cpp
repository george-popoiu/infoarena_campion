#include<fstream>
#include<iostream>
#define inf "scara3.in"
#define outf "scara3.out"
#define MaxN 1202
#define PINF 0x3f3f3f3f
#define cmp(a,b,c,d) ( ((a)<(c)) || ((a)==(c) && (b)<(d)) )
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int N,K,L;
int pasi[MaxN],cost[MaxN];
int apa[MaxN],ener[MaxN];

void Citire()
{
int t,i,j;
f>>N>>K;
for(t=1;t<=K;t++)
    {
    f>>i>>j;
    apa[i]=j;
    }
f>>L;
for(t=1;t<=L;t++)
    {
    f>>i>>j;
    ener[i]=j;
    }
}

void Rezolvare()
{
pasi[1]=1;
for(int i=2;i<=N;i++)pasi[i]=PINF;
for(int i=1;i<=N;i++)
    {
    //pasi[i]=pasi[i-1]+1;
    //cost[i]=cost[i-1];
    if(i<N && cmp(pasi[i]+1,cost[i],pasi[i+1],cost[i+1]) )
        {
        pasi[i+1]=1+pasi[i];
        cost[i+1]=cost[i];
        }
    /*for(int j=1;j<i;j++)
        {
        if(apa[j]!=0 && j+apa[j]>=i && 1+pasi[j]<pasi[i])
            {
            pasi[i]=1+pasi[j];
            cost[i]=cost[j];
            }
        else if( apa[j]!=0 && j+apa[j]>=i && 1+pasi[j]==pasi[i] && cost[j]<cost[i])
            {
            cost[i]=cost[j];
            }
        if(ener[j]!=0 && j+(2*ener[j])>=i && pasi[j]+1<pasi[i] && (i-j)%2==0 )
            {
            pasi[i]=pasi[j]+1;
            cost[i]=cost[j]+((i-j)/2);
            }
        else if( ener[j]!=0 && j+(2*ener[j])>=i && pasi[j]+1==pasi[i] && (i-j)%2==0 && cost[j]+((i-j)/2)<cost[i])
            {
            cost[i]=cost[j]+((i-j)/2);
            }
        }*/
    if(apa[i])
        {
        for(int x=1;x<=apa[i] && i+x<=N;x++)
            {
            if(cmp(pasi[i]+1,cost[i],pasi[i+x],cost[i+x]))
                {
                pasi[i+x]=1+pasi[i];
                cost[i+x]=cost[i];
                }
            }
        }
    if(ener[i])
        {
        for(int q=1;i+2*q<=N && q<=ener[i]; q++)
            {
            if(pasi[i+2*q]>pasi[i]+1)
                {
                pasi[i+2*q]=pasi[i]+1;
                cost[i+2*q]=cost[i]+q;
                }
            else if(pasi[i+2*q]==pasi[i]+1 && cost[i+2*q]>cost[i]+q)
                {
                cost[i+2*q]=cost[i]+q;
                }
            }
        /*for(int q=1;q<=2*ener[i] && i+q<=N;q++)
            {
            if(cmp(pasi[i]+1,cost[i]+((q+1)/2),pasi[i+q],cost[i+q]))
                {
                pasi[i+q]=pasi[i]+1;
                cost[i+q]=cost[i]+((q+1)/2);
                }
            }*/
        }
    }
g<<pasi[N]<<" "<<cost[N];
}

int main()
{
Citire();
Rezolvare();
f.close();
g.close();
return 0;
}

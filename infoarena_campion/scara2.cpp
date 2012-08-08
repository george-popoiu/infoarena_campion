#include<stdio.h>
#define inf "scara2.in"
#define outf "scara2.out"
#define NMax 9
#define HMax 76
#define PINF 0x3f3f3f3f
using namespace std;

int N,H,M,P;
double ef[NMax],efmin=PINF;
int sol[NMax],solmin[NMax],uz[HMax],htot;

void Citire()
{
scanf("%d%d%d%d",&H,&N,&M,&P);
}

void Afisare()
{
printf("%.2f\n",efmin);
for(int i=1;i<N;i++)printf("%d ",solmin[i]);
printf("%d",solmin[N]);
}

double efort()
{
double x,sum;
for(int k=1;k<=N;k++)
    {
    x=ef[k-1]+sol[k];
    sum=sol[k];
    for(int j=2;k-j>=0;j++)
        {
        sum+=sol[k-j+1];
        if(sum>M)break;
        if(sum/j+P+ef[k-j]<x)x=sum/j+P+ef[k-j];
        }
    ef[k]=x;
    }
return ef[N];
}

void Gen(int k)
{
int i;
double x;
if(k==N+1)
    {
    if(htot==H)
        {
        x=efort();
        if(x<efmin && efmin-x>0.001)
            {
            efmin=x;
            for(i=1;i<=N;i++)solmin[i]=sol[i];
            }
        }
    }
else
    {
    for(i=1;i<=H && htot+i<=H && i<=M ;i++)
        {
        if(!uz[i])
            {
            sol[k]=i;htot+=i;uz[i]=1;
            Gen(k+1);
            htot-=i;uz[i]=0;
            }
        }
    }
}

int main()
{
freopen(inf,"r",stdin);
freopen(outf,"w",stdout);
Citire();
Gen(1);
Afisare();
return 0;
}

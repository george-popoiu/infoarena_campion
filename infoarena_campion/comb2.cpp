#include<iostream>
#define MaxN 101
#define inf "permut.in"
#define outf "permut.out"
using namespace std;

int N,St[MaxN],k,p;

void Init(){St[k]=0;}

void Tipar(){for(int i=1;i<=k;i++)cout<<St[i]<<" ";cout<<endl;}

int Succesor()
{
if(St[k]<N-p+k)
    {
    St[k]++;
    return 1;
    }
return 0;
}

int Valid()
{
return 1;
}

int Solutie()
{
return (k==p);
}

int main()
{
int AS;
cout<<"n=";cin>>N;
cout<<"p=";cin>>p;
k=1;
Init();
while(k>0)
    {
    do{}while( (AS=Succesor()) && !Valid() );
    if(AS)
        {
        if(Solutie())Tipar();
        else {k++;Init();}
        }
    else k--;
    }
return 0;
}

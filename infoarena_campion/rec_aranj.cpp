#include<iostream>
using namespace std;

void tipar(int k,int v[])
{
for(int i=1;i<=k;i++)cout<<v[i]<<" ";
cout<<"\n";
}

void aranj(int v[],int k,int n,int pas)
{
int i,j,max,m;
if(pas==k+1)tipar(k,v);
else
    {
    if(pas==1)
        {
        for(i=1;i<=n;i++)
            {
            v[pas]=i;
            aranj(v,k,n,pas+1);
            }
        }
    else
        {
        max=v[1];
        for(i=2;i<=pas-1;i++)
            {
            if(v[i]>max)max=v[i];
            }
        for(i=max+1;i<=n;i++)
            {
            v[pas]=i;
            for(j=1;j<=pas;j++)
                {
                m=v[pas];v[pas]=v[j];v[j]=m;
                aranj(v,k,n,pas+1);
                m=v[pas];v[pas]=v[j];v[j]=m;
                }
            }
        }
    }
}

int main()
{
int n,k,v[100];
cout<<"n=";cin>>n;
cout<<"k=";cin>>k;
aranj(v,k,n,1);
return 0;
}

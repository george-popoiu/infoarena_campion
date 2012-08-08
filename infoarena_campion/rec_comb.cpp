#include<iostream>
using namespace std;

void tipar(int v[],int k)
{
for(int i=1;i<=k;i++)cout<<v[i]<<" ";
cout<<"\n";
}

void comb(int v[],int n,int k,int pas)
{
int i;
if(pas==k+1)tipar(v,k);
else
    {
    if(pas==1)
        {
        for(i=1;i<=n;i++)
            {
            v[pas]=i;
            comb(v,n,k,pas+1);
            }
        }
    else
        {
        for(i=v[pas-1]+1;i<=n;i++)
            {
            v[pas]=i;
            comb(v,n,k,pas+1);
            }
        }
    }
}

int main()
{
int v[100],n,k;
cout<<"n=";cin>>n;
cout<<"k=";cin>>k;
comb(v,n,k,1);
return 0;
}

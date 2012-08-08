#include<iostream>
#include<fstream>
using namespace std;

fstream f("permutari.in",ios::in);

void tipar(int n,int v[])
{
for(int i=1;i<=n;i++)cout<<v[i]<<" ";
cout<<"\n";
}

void permut(int k,int n, int v[])
{
int i,c;
if(k==n+1)tipar(n,v);
else
    {
    v[k]=k;
    for(i=1;i<=k;i++)
        {
        c=v[i];v[i]=v[k];v[k]=c;
        permut(k+1,n,v);
        c=v[i];v[i]=v[k];v[k]=c;
        }
    }
}

int main()
{
int v[100],n;
//cout<<"n=";cin>>n;
f>>n;
permut(1,n,v);
f.close();
return 0;
}

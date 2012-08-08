#include<iostream>
using namespace std;

int n,k,s[100];

void tipar()
{
for(int i=1;i<=k;i++)cout<<s[i]<<" ";
cout<<endl;
}

void back(int pas)
{
int i;
if(pas==k+1)tipar();
else
    {
    for(i=s[pas-1]+1;i<=n;i++)
        {
        s[pas]=i;
        back(pas+1);
        }
    }
}

int main()
{
cin>>n>>k;
//for(i
back(1);
return 0;
}

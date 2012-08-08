#include<iostream>
using namespace std;

int main()
{
int n,st[100],rez=0;
cin>>n;
int i=1;
st[1]=n;
int cobor=0;
while(i>0)
    {
    if(st[i]>1 && !cobor){i++;st[i]=st[i-1]-1;}
    else
        {
        cobor=1;
        rez*=st[i];
        i--;
        }
    }
cout<<rez<<endl;
return 0;
}

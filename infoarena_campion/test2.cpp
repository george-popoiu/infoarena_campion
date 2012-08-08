#include<iostream>
using namespace std;

int n,sum=0;

void suma(int nr,int * sum)
{
if(nr!=0)
    {
    (*sum)+=nr;
    suma(nr-1,sum);
    }
}

int main()
{
cin>>n;
suma(n,&sum);
cout<<sum<<endl;
return 0;
}

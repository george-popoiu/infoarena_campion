#include<iostream>
#include<math.h>
using namespace std;

int main()
{
int n,m;
cout<<"Introdu numarul:";cin>>n;
cout<<"Introdu oridul radicalului:";cin>>m;
cout<<pow(n,(float)(1/m))<<endl;
return 0;
}

#include<fstream>
#include<iostream>
#include "grafuri.cpp"
#define inf "pag225ex25.in"
using namespace std;

int n,MA[50][50],areciclu,s[50];

void DF(int nod)
{
s[nod]=1;
int i;
for(i=1;i<=n;i++)
    {
    if(MA[nod][i]==1)
        {
        if(s[i]==0)
            {
            DF(i);
            }
        else areciclu=1;
        }
    }
}

int main()
{
CitireMatAd(inf,MA,&n);
DF(1);
if(areciclu)cout<<"DA";
else cout<<"NU";
return 0;
}

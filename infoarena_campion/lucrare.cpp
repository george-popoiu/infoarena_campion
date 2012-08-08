#include<fstream>
#include<iostream>
#include<string.h>
#define inf "lucrare.in"
#define outf "lucrare.out"
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int n,m;
char cuvinte[100][100];

void Citire()
{
char cuv[100],c;
int i=0,j=0,nr=0;
f>>n;
f.get();
do
    {
    f>>c;
    if(c==' ')
        {
        nr++;
        i=0;
        strcpy(cuvinte[j],cuv);
        cout<<cuvinte[j]<<" ";
        for(int k=0;k<strlen(cuv);k++)cuv[k]='\0';
        j++;
        }
    else cuv[i++]=c;
    }
while(nr<n);
}

int main()
{
Citire();
for(int i=1;i<=n;i++)
    {
    g<<cuvinte[i]<<endl;
    }
f.close();
g.close();
return 0;
}

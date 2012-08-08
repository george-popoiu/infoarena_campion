#include<fstream>
#include<iostream>
#define inf ""
#define outf ""
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int main()
{
int n,s=0,c[100][100];
cout<<"n=";cin>>n;
for(int i=1;i<=n;i++)
    {
    c[i][1]=1;
    c[i][i]=1;
    }
for(int i=2;i<=n;i++)
    {
    for(int j=2;j<=i;j++)
        {
        c[i][j]=c[i-1][j-1]+j*c[i-1][j];
        }
    }
for(int i=1;i<=n;i++)s+=c[n][i];
cout<<s;
f.close();
g.close();
return 0;
}

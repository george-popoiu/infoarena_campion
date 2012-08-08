#include<iostream>
using namespace std;

int n,mat[10][10];

void rotire()
{
int aux[10][10],i,j;
for(i=1;i<=n;i++)
    {
    for(j=1;j<=n;j++)
        {
        aux[i][j]=mat[j][n-i+1];
        }
    }
for(i=1;i<=n;i++)for(j=1;j<=n;j++)mat[i][j]=aux[i][j];
}

int main()
{
int i,j;
cin>>n;
for(i=1;i<=n;i++)
    {
    for(j=1;j<=n;j++)cin>>mat[i][j];
    }
for(i=1;i<=n;i++)
    {
    for(j=1;j<=n;j++)cout<<mat[i][j]<<" ";
    cout<<endl;
    }
rotire();
cout<<endl;
for(i=1;i<=n;i++)
    {
    for(j=1;j<=n;j++)cout<<mat[i][j]<<" ";
    cout<<endl;
    }
rotire();
cout<<endl;
for(i=1;i<=n;i++)
    {
    for(j=1;j<=n;j++)cout<<mat[i][j]<<" ";
    cout<<endl;
    }
return 0;
}

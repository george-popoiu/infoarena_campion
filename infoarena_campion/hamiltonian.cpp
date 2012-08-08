#include<fstream>
using namespace std;

fstream f("hamiltonian.in",ios::in),g("hamiltonian.out",ios::out);

int n,MA[50][50],st[50];

void citire()
{
int i,j;
f>>n;
while(f>>i>>j)
    {
    MA[i][j]=MA[j][i]=1;
    }
}

int succesor(int k)
{
if(st[k]<n){st[k]++;return 1;}
return 0;
}

int valid(int k)
{
if(MA[st[k-1]][st[k]]==0)return 0;
for(int i=1;i<=k-1;i++)
    if(st[i]==st[k])return 0;
if(k==n && MA[st[k]][1]==0) return 0;
return 1;
}

void tipar()
{
for(int i=1;i<=n;i++)g<<st[i]<<" ";
g<<st[1]<<endl;
}

void back(int k)
{
if(k==n+1)tipar();
else
    {
    st[k]=1;
    while(succesor(k))
        {
        if(valid(k))back(k+1);
        }
    }
}

int main()
{
citire();
st[1]=1;
st[2]=1;
back(2);
f.close();
g.close();
return 0;
}

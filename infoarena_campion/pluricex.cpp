// Combinari din n luate cate k
#include<fstream>
using namespace std;

fstream f("pluricex.in",ios::in),g("pluricex.out",ios::out);

int n,k,d,a[23][11],s[100];

void tipar(){for(int i=1;i<=k;i++)g<<s[i]<<" ";g<<endl;}

int solutie()
{
int uz[100],i,j,gasit=0;
for(i=1;i<=d;i++)uz[i]=0;
for(i=1;i<=k;i++)
    {
    for(j=1;j<=a[s[i]][0];j++)uz[a[s[i]][j]]=1;
    }
for(i=1;i<=d;i++)
    {
    if(!uz[i]){gasit=1;break;}
    }
if(gasit)return 0;
return 1;
}

void back(int pas)
{
int i;
if(pas==k+1)
    {
    if(solutie())tipar();
    }
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
int i,j;
f>>n>>k>>d;
for(i=1;i<=n;i++)
    {
    f>>a[i][0];
    for(j=1;j<=a[i][0];j++)f>>a[i][j];
    }
f.close();
back(1);
g.close();
return 0;
}

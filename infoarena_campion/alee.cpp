#include<fstream>
using namespace std;

fstream f("alee.in",ios::in),g("alee.out",ios::out);

int mat[176][176],c[176][176],n,m,x1,y1,x2,y2;

void citire();
int posibil();
int min(int a,int b,int c,int d);

int main()
{
int i,j;
citire();
f.close();
while(posibil()==1)
    {
    for(i=1;i<=n;i++)
        {
        for(j=1;j<=n;j++)
            {
            if(mat[i][j]==0 && (i!=x1 || j!=y1) )c[i][j]=1+min(c[i-1][j],c[i][j+1],c[i+1][j],c[i][j-1]);
            }
        }
    }
g<<c[x2][y2];
g.close();
return 0;
}

void citire()
{
int i,x,y;
f>>n>>m;
for(i=1;i<=m;i++)
    {
    f>>x>>y;
    mat[x][y]=-1;
    c[x][y]=-1;
    }
f>>x1>>y1>>x2>>y2;
//mat[x1][y1]=1;
c[x1][y1]=1;
}

int posibil()
{
int gasit=0,i,j;
for(i=1;i<=n;i++)
    {
    for(j=1;j<=n;j++)if(c[i][j]==0){gasit=1;break;}
    if(gasit==1)break;
    }
if(gasit==1)return 1;
return 0;
}

int min(int a,int b,int c,int d)
{
int v[5],dim=1,min;
for(int i=0;i<5;i++)v[i]=0;
if( (a!=0) && (a!=-1) ) v[dim++]=a;
if( (b!=0) && (b!=-1) ) v[dim++]=b;
if( (c!=0) && (c!=-1) ) v[dim++]=c;
if( (d!=0) && (d!=-1) ) v[dim++]=d;
min=v[1];
for(int i=1;i<dim;i++){if(v[i]<min)min=v[i];}
if(min==0)return -1;
return min;
}

#include<fstream>
#define N 101
#define K 199
using namespace std;

fstream f("sudest.in",ios::in),g("sudest.out",ios::out);

short A[N][N],B[N][N],Pasi[K],n,k;
short P[N][N];

void Citire()
{
f>>n;
for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)f>>A[i][j];
f>>k;
for(int i=1;i<=k;i++)f>>Pasi[i];
f.close();
}

void Rezolvare()
{
int i,j,t,max1,max2;
B[1][1]=A[1][1];
B[1][1+Pasi[1]]=A[1][1]+A[1][1+Pasi[1]];
P[1][1+Pasi[1]]=1;
B[1+Pasi[1]][1]=A[1][1]+A[1+Pasi[1]][1];
P[1+Pasi[1]][1]=1;
for(t=2;t<=k;t++)
    {
    for(i=1;i<=n;i++)
        {
        for(j=1;j<=n;j++)
            {
            max1=max2=0;
            if( ((i-Pasi[t]) >= 1) && P[i-Pasi[t]][j]==t-1)
                {
                max1=B[i-Pasi[t]][j];
                }
            if( ((j-Pasi[t])>=1) && P[i][j-Pasi[t]]==t-1)
                {
                max2=B[i][j-Pasi[t]];
                }
            if(max1!=0 || max2!=0)
                {
                if(max1<max2){B[i][j]=max2+A[i][j];P[i][j]=t;}
                else {B[i][j]=max1+A[i][j];P[i][j]=t;}
                }
            }
        }
    }
}

void Drum(int x,int y,int pas)
{
int gasit;
if(x==1 && y==1)g<<"1 1\n";
else
    {
    gasit=0;
    if(y-Pasi[pas]>=1 && P[x][y-Pasi[pas]]==pas-1 && B[x][y]==B[x][y-Pasi[pas]]+A[x][y])
        {
        Drum(x,y-Pasi[pas],pas-1);
        g<<x<<" "<<y<<"\n";
        gasit=1;
        }
    if(!gasit)
    if(x-Pasi[pas]>=1 && P[x-Pasi[pas]][y]==pas-1 && B[x][y]==B[x-Pasi[pas]][y]+A[x][y])
        {
        Drum(x-Pasi[pas],y,pas-1);
        g<<x<<" "<<y<<"\n";
        }
    }
}

int main()
{
Citire();
Rezolvare();
g<<B[n][n]<<"\n";
Drum(n,n,k);
g.close();
return 0;
}

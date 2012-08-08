#include<fstream>
#define inf "lacuri.in"
#define outf "lacuri.out"
#define NMax 110
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int N;
int mat[NMax][NMax];
int ptr[NMax][NMax];
int nrp=0;
bool drum=true;
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
int d[NMax][NMax];

struct coada
{
int lin;
int col;
};

coada c[NMax*NMax];

void Citire()
{
f>>N;
for(int i=1;i<=N;i++)
    for(int j=1;j<=N;j++){f>>mat[i][j];ptr[i][j]=mat[i][j];}
}

bool esingur(int i,int j)
{
for(int k=0;k<4;k++)
    {
    if(ptr[i+dx[k]][j+dy[k]]==1)return false;
    }
return true;
}

void patrat(int i,int j,int &x,int &y,int &l,int &c)
{
int k;
if(ptr[i][j]==1)
    {
    ptr[i][j]=0;
    if(i>x)x=i;
    if(j>y)y=j;
    if(i<l)l=i;
    if(j<c)c=j;
    for(k=0;k<4;k++)
        if(ptr[i+dx[k]][j+dy[k]]==1)patrat(i+dx[k],j+dy[k],x,y,l,c);
    }
}

bool eplin(int l,int c,int x,int y)
{
for(int i=l;i<=x;i++)
    for(int j=c;j<=y;j++)
        if(mat[i][j]!=1){drum=false;return false;}
return true;
}

void DetPatrate()
{
for(int i=1;i<=N;i++)
    {
    for(int j=1;j<=N;j++)
        {
        if(ptr[i][j]==1)
            {
            if(esingur(i,j)){ptr[i][j]=0;nrp++;}
            else
                {
                int x,y,l,c;
                x=l=i;
                y=c=j;
                patrat(i,j,x,y,l,c);
                if(x-l==y-c)
                    {
                    if(eplin(l,c,x,y))nrp++;
                    else drum=false;
                    }
                else drum=false;
                }
            }
        }
    }
g<<nrp<<"\n";
}

void Borderare()
{
for(int i=0;i<=N+1;i++)d[0][i]=d[N+1][i]=d[i][0]=d[i][N+1]=-1;
}

void Lee()
{
int st,sf;
st=sf=1;
c[st].lin=1;
c[sf].col=1;
d[1][1]=1;
Borderare();
while(st<=sf)
    {
    int cl=c[st].col;
    int li=c[st].lin;
    for(int k=0;k<4;k++)
        {
        if(d[li+dx[k]][cl+dy[k]]==0 && mat[li+dx[k]][cl+dy[k]]==0)
            {
            sf++;
            c[sf].lin=li+dx[k];
            c[sf].col=cl+dy[k];
            d[c[sf].lin][c[sf].col]=1+d[li][cl];
            }
        }
    st++;
    }
}

void Afisare(int i,int j)
{
int k;
if(i>=1 && j>=1)
    {
    for(k=0;k<4;k++)
        {
        if(d[i+dx[k]][j+dy[k]]==d[i][j]-1 && mat[i+dx[k]][j+dy[k]]==0)
            {
            Afisare(i+dx[k],j+dy[k]);
            g<<i<<" "<<j<<"\n";
            break;
            }
        }
    }
}

int main()
{
Citire();
DetPatrate();
if(drum==true)
    {
    Lee();
    g<<"1 1\n";
    Afisare(N,N);
    }
f.close();
g.close();
return 0;
}

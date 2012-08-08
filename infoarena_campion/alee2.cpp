#include<fstream>
#include<iostream>
#define inf "alee.in"
#define outf "alee.out"
#define MaxN 200
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

short N,M,X1,Y1,X2,Y2;
short mat[MaxN][MaxN],cost[MaxN][MaxN];
short st=1,sf=1;

struct coada
{
short lin;
short col;
};

coada c[MaxN*MaxN];

void Citire()
{
short a,b;
f>>N>>M;
for(short i=0;i<=N+1;i++)
    {
    mat[i][0]=-1;
    mat[i][N+1]=-1;
    mat[0][i]=-1;
    mat[N+1][i]=-1;
    }
for(short i=1;i<=M;i++)
    {
    f>>a>>b;
    mat[a][b]=-1;
    }
f>>X1>>Y1>>X2>>Y2;
}

void Lee()
{
c[st].lin=X1;
c[st].col=Y1;
cost[X1][Y1]=1;
while(st<=sf)
    {
    //S
    if( mat[c[st].lin+1][c[st].col]!=-1 && cost[c[st].lin+1][c[st].col]==0 )
        {
        cost[c[st].lin+1][c[st].col]=cost[c[st].lin][c[st].col]+1;
        sf++;
        c[sf].lin=c[st].lin+1;
        c[sf].col=c[st].col;
        }
    //E
    if( mat[c[st].lin][c[st].col+1]!=-1 && cost[c[st].lin][c[st].col+1]==0 )
        {
        cost[c[st].lin][c[st].col+1]=cost[c[st].lin][c[st].col]+1;
        sf++;
        c[sf].lin=c[st].lin;
        c[sf].col=c[st].col+1;
        }
    //N
    if( mat[c[st].lin-1][c[st].col]!=-1 && cost[c[st].lin-1][c[st].col]==0 )
        {
        cost[c[st].lin-1][c[st].col]=cost[c[st].lin][c[st].col]+1;
        sf++;
        c[sf].lin=c[st].lin-1;
        c[sf].col=c[st].col;
        }
    //W
    if( mat[c[st].lin][c[st].col-1]!=-1 && cost[c[st].lin][c[st].col-1]==0 )
        {
        cost[c[st].lin][c[st].col-1]=cost[c[st].lin][c[st].col]+1;
        sf++;
        c[sf].lin=c[st].lin;
        c[sf].col=c[st].col-1;
        }
    st++;
    }
g<<cost[X2][Y2];
}

int main()
{
Citire();
Lee();
f.close();
g.close();
return 0;
}

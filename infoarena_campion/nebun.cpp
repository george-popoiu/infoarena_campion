#include<fstream>
#include<iostream>
#define inf "nebun.in"
#define outf "nebun.out"
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int mat[100][100],n,x1,y1,x2,y2,st=1,sf=1;

struct coada
{
int lin;
int col;
int cost;
};

coada c[100];

void Citire()
{
f>>n;
for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)f>>mat[i][j];
f>>x1>>y1>>x2>>y2;
for(int i=0;i<=n+1;i++)
    {
    mat[i][0]=-1;mat[i][n+1]=-1;
    mat[0][i]=-1;mat[n+1][i]=-1;
    }
}

void lee()
{
c[st].lin=x1;
c[st].col=y1;
c[st].cost=1;
while(st<=sf)
    {
    if(mat[c[st].lin-1][c[st].col+1]==0){sf++;c[sf].lin=c[st].lin-1;c[sf].col=c[st].col+1;c[sf].cost=c[st].cost+1;mat[c[sf].lin][c[sf].col]=c[sf].cost;}
    if(mat[c[st].lin+1][c[st].col+1]==0){sf++;c[sf].lin=c[st].lin+1;c[sf].col=c[st].col+1;c[sf].cost=c[st].cost+1;mat[c[sf].lin][c[sf].col]=c[sf].cost;}
    if(mat[c[st].lin+1][c[st].col-1]==0){sf++;c[sf].lin=c[st].lin+1;c[sf].col=c[st].col-1;c[sf].cost=c[st].cost+1;mat[c[sf].lin][c[sf].col]=c[sf].cost;}
    if(mat[c[st].lin-1][c[st].col-1]==0){sf++;c[sf].lin=c[st].lin-1;c[sf].col=c[st].col-1;c[sf].cost=c[st].cost+1;mat[c[sf].lin][c[sf].col]=c[sf].cost;}
    st++;
    }
}

void gendrum(int lin,int col)
{
if(lin==x1 && col==y1){}
else
    {
    if(mat[lin-1][col+1]==mat[lin][col]-1)gendrum(lin-1,col+1);
    else if(mat[lin+1][col+1]==mat[lin][col]-1)gendrum(lin+1,col+1);
    else if(mat[lin+1][col-1]==mat[lin][col]-1)gendrum(lin+1,col-1);
    else if(mat[lin-1][col-1]==mat[lin][col]-1)gendrum(lin-1,col-1);
    }
g<<lin<<" "<<col<<endl;
}

int main()
{
Citire();
lee();
if(mat[x2][y2]!=0)
    {
    g<<mat[x2][y2]<<endl;
    g<<x1<<" "<<y1<<endl;
    gendrum(x2,y2);
    }
else g<<"-1";
f.close();
g.close();
return 0;
}

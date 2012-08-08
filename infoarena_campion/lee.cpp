#include<fstream>
#include<iostream>
using namespace std;

fstream f("lee.in",ios::in),g("lee.out",ios::out);

int mat[50][50],n,i_c=1,s_c=1,stlin,stcol,sflin,sfcol;

struct coada
{
int lin;
int col;
int cost;
};

coada c[1000];

void Citire()
{
f>>n;
for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)f>>mat[i][j];
f>>stlin>>stcol;
f>>sflin>>sfcol;
for(int i=0;i<=n+1;i++){mat[0][i]=-1;mat[n+1][i]=-1;mat[i][0]=-1;mat[i][n+1]=-1;}
}

void lee()
{
c[i_c].cost=1;
c[i_c].lin=stlin;
c[i_c].col=stcol;
while(i_c<=s_c)
    {
    if(mat[c[i_c].lin-1][c[i_c].col]==0){s_c++;c[s_c].lin=c[i_c].lin-1;c[s_c].col=c[i_c].col;c[s_c].cost=c[i_c].cost+1;mat[c[s_c].lin][c[s_c].col]=c[s_c].cost;}
    if(mat[c[i_c].lin-1][c[i_c].col+1]==0){s_c++;c[s_c].lin=c[i_c].lin-1;c[s_c].col=c[i_c].col+1;c[s_c].cost=c[i_c].cost+1;mat[c[s_c].lin][c[s_c].col]=c[s_c].cost;}
    if(mat[c[i_c].lin][c[i_c].col+1]==0){s_c++;c[s_c].lin=c[i_c].lin;c[s_c].col=c[i_c].col+1;c[s_c].cost=c[i_c].cost+1;mat[c[s_c].lin][c[s_c].col]=c[s_c].cost;}
    if(mat[c[i_c].lin+1][c[i_c].col+1]==0){s_c++;c[s_c].lin=c[i_c].lin+1;c[s_c].col=c[i_c].col+1;c[s_c].cost=c[i_c].cost+1;mat[c[s_c].lin][c[s_c].col]=c[s_c].cost;}
    if(mat[c[i_c].lin+1][c[i_c].col]==0){s_c++;c[s_c].lin=c[i_c].lin+1;c[s_c].col=c[i_c].col;c[s_c].cost=c[i_c].cost+1;mat[c[s_c].lin][c[s_c].col]=c[s_c].cost;}
    if(mat[c[i_c].lin+1][c[i_c].col-1]==0){s_c++;c[s_c].lin=c[i_c].lin+1;c[s_c].col=c[i_c].col-1;c[s_c].cost=c[i_c].cost+1;mat[c[s_c].lin][c[s_c].col]=c[s_c].cost;}
    if(mat[c[i_c].lin][c[i_c].col-1]==0){s_c++;c[s_c].lin=c[i_c].lin;c[s_c].col=c[i_c].col-1;c[s_c].cost=c[i_c].cost+1;mat[c[s_c].lin][c[s_c].col]=c[s_c].cost;}
    if(mat[c[i_c].lin-1][c[i_c].col-1]==0){s_c++;c[s_c].lin=c[i_c].lin-1;c[s_c].col=c[i_c].col-1;c[s_c].cost=c[i_c].cost+1;mat[c[s_c].lin][c[s_c].col]=c[s_c].cost;}
    i_c++;
    }
}

void gedrum(int sflin,int sfcol)
{
if(sflin==stlin && sfcol==stcol){}
else
    {
    if(mat[sflin-1][sfcol]==mat[sflin][sfcol]-1)gedrum(sflin-1,sfcol);
    else if(mat[sflin-1][sfcol+1]==mat[sflin][sfcol]-1)gedrum(sflin-1,sfcol+1);
    else if(mat[sflin][sfcol+1]==mat[sflin][sfcol]-1)gedrum(sflin,sfcol+1);
    else if(mat[sflin+1][sfcol+1]==mat[sflin][sfcol]-1)gedrum(sflin+1,sfcol+1);
    else if(mat[sflin+1][sfcol]==mat[sflin][sfcol]-1)gedrum(sflin+1,sfcol);
    else if(mat[sflin+1][sfcol-1]==mat[sflin][sfcol]-1)gedrum(sflin+1,sfcol-1);
    else if(mat[sflin][sfcol-1]==mat[sflin][sfcol]-1)gedrum(sflin,sfcol-1);
    else if(mat[sflin-1][sfcol-1]==mat[sflin][sfcol]-1)gedrum(sflin-1,sfcol-1);
    }
g<<sflin<<" "<<sfcol<<endl;
}

int main()
{
Citire();
lee();
g<<mat[sflin][sfcol]<<endl;
g<<stlin<<" "<<stcol<<endl;
gedrum(sflin,sfcol);
f.close();
g.close();
return 0;
}

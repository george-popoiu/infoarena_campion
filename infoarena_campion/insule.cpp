#include<fstream>
#define inf "insule.in"
#define outf "insule.out"
#define Max 102
#define CARD 4
#define INF 0x3f3f3f3f
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int mat[Max][Max],cp[Max][Max];
int dim[Max][Max];
int NR,NG,NB;
int N,M;
int dl[CARD]={-1,0,1,0};
int dc[CARD]={0,1,0,-1};

struct coada
{
int x;
int y;
};

void Citire()
{
char s[Max];
f>>N>>M;
f.get();
*s=NULL;
for(int i=1;i<=N;i++)
    {
    f.get(s,Max);
    for(int j=0;j<strlen(s);j++)
        {
        mat[i][j+1]=s[j]-'0';
        cp[i][j+1]=mat[i][j+1];
        }
    f.get();
    *s=NULL;
    }
}

void Fill(int x,int y,int nr)
{
int i;
cp[x][y]=0;
for(i=0;i<CARD;i++)
    {
    if(cp[x+dl[i]][y+dc[i]]==nr)Fill(x+dl[i],y+dc[i],nr);
    }
}

void Rezolvare()
{
for(int i=1;i<=N;i++)
    {
    for(int j=1;j<=M;j++)
        {
        if(cp[i][j]==1){Fill(i,j,1);NR++;}
        else if(cp[i][j]==2){Fill(i,j,2);NG++;}
        else if(cp[i][j]==3){Fill(i,j,3);NB++;}
        }
    }
g<<NR<<" "<<NG<<" "<<NB;
}

bool AreVecin(int i,int j,int nr)
{
for(int k=0;k<CARD;k++)
    if(mat[i+dl[k]][j+dc[k]]==nr)return true;
return false;
}

void CalcLg()
{
int Lg=INF;
int st=1,sf=0;
coada c[Max*Max];
for(int i=1;i<=N;i++)
    for(int j=1;j<=M;j++)
        {
        dim[i][j]=INF;
        if(mat[i][j]==1 || mat[i][j]==2 || mat[i][j]==3)cp[i][j]=-1;
        else cp[i][j]=0;
        if(mat[i][j]==0 && AreVecin(i,j,1))
            {
            sf++;
            c[sf].x=i;
            c[sf].y=j;
            dim[c[sf].x][c[sf].y]=1;
            }
        }
for(int i=0;i<=N+1;i++)cp[i][0]=cp[i][M+1]=-1;
for(int j=0;j<=M+1;j++)cp[0][j]=cp[N+1][j]=-1;
while(st<=sf)
    {
    for(int k=0;k<CARD;k++)
        if(cp[c[st].x+dl[k]][c[st].y+dc[k]]!=-1 && 1+dim[c[st].x][c[st].y]<dim[c[st].x+dl[k]][c[st].y+dc[k]])
            {
            sf++;
            c[sf].x=c[st].x+dl[k];
            c[sf].y=c[st].y+dc[k];
            dim[c[sf].x][c[sf].y]=1+dim[c[st].x][c[st].y];
            }
    st++;
    }
//g<<"\n";
for(int i=1;i<=N;i++)
    {
    for(int j=1;j<=M;j++)
        {
        //g<<dim[i][j]<<" ";
        if(mat[i][j]==0 && AreVecin(i,j,2) && dim[i][j]<Lg)Lg=dim[i][j];
        }
    //g<<"\n";
    }
g<<" "<<Lg;
}

int main()
{
Citire();
Rezolvare();
CalcLg();
f.close();
g.close();
return 0;
}

#include<fstream>
#define inf "taxe.in"
#define outf "taxe.out"
#define NMax 102
#define CARD 4
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int mat[NMax][NMax];
int cmin[NMax][NMax];
int dl[CARD]={-1,0,1,0};
int dc[CARD]={0,1,0,-1};
int S,N;

struct coada
{
int lin;
int col;
};

coada c[NMax*NMax*NMax];

void Citire()
{
f>>S>>N;
for(int i=1;i<=N;i++)
    for(int j=1;j<=N;j++)
        {
        f>>mat[i][j];
        }
//Borderare
for(int i=0;i<=N+1;i++)
    {
    cmin[0][i]=cmin[N+1][i]=cmin[i][0]=cmin[i][N+1]=-1;
    }
}

void Rezolva()
{
int st,sf;
st=sf=1;
cmin[1][1]=S;
c[st].lin=1;
c[st].col=1;
while(st<=sf)
    {
    int li=c[st].lin;
    int co=c[st].col;
    for(int i=0;i<CARD;i++)
        {
        if(cmin[li+dl[i]][co+dc[i]]!=-1 && cmin[li][co]-mat[li+dl[i]][co+dc[i]]>cmin[li+dl[i]][co+dc[i]])
            {
            sf++;
            cmin[li+dl[i]][co+dc[i]]=cmin[li][co]-mat[li+dl[i]][co+dc[i]];
            c[sf].lin=li+dl[i];
            c[sf].col=co+dc[i];
            }
        }
    st++;
    }
if(cmin[N][N]-mat[1][1]<0)g<<"-1";
else g<<cmin[N][N]-mat[1][1];
}

int main()
{
Citire();
Rezolva();
f.close();
g.close();
return 0;
}

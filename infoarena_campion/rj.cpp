#include<stdio.h>
#include<string.h>
#define inf "rj.in"
#define outf "rj.out"
#define Max 102
#define PINF 0x3f3f3f3f
#define CARD 8
using namespace std;

int R[Max][Max],J[Max][Max];
int N,M;
int lr,cr,lj,cj;
int dl[CARD]={-1,-1,0,1,1,1,0,-1};
int dc[CARD]={0,1,1,1,0,-1,-1,-1};

struct coada
{
int lin;
int col;
};

void Citire()
{
char s[Max];
scanf("%d%d",&N,&M);
gets(s);
*s=NULL;
for(int i=1;i<=N;i++)
    {
    gets(s);
    for(int j=0;j<strlen(s);j++)
        {
        if(s[j]=='R'){R[i][j+1]=1;lr=i;cr=j+1;}
        else if(s[j]=='J'){J[i][j+1]=1;lj=i;cj=j+1;}
        else if(s[j]=='X'){R[i][j+1]=J[i][j+1]=-1;}
        }
    *s=NULL;
    }
//Borderare
for(int i=0;i<=M+1;i++)
    {
    R[0][i]=J[0][i]=-1;
    R[N+1][i]=J[N+1][i]=-1;
    }
for(int i=0;i<=N+1;i++)
    {
    R[i][0]=J[i][0]=-1;
    R[i][M+1]=J[i][M+1]=-1;
    }
}

void Parcurgere(int mat[Max][Max],int x,int y)
{
int st,sf;
st=sf=1;
coada c[Max*Max];
c[st].lin=x;
c[st].col=y;
while(st<=sf)
    {
    for(int i=0;i<CARD;i++)
        {
        if(!mat[c[st].lin+dl[i]][c[st].col+dc[i]])
            {
            sf++;
            c[sf].lin=c[st].lin+dl[i];
            c[sf].col=c[st].col+dc[i];
            mat[c[sf].lin][c[sf].col]=1+mat[c[st].lin][c[st].col];
            }
        }
    st++;
    }
}

void DetSol(int &tmin,int &xmin,int &ymin)
{
for(int i=1;i<=N;i++)
    {
    for(int j=1;j<=M;j++)
        {
        if( R[i][j]!=-1 && R[i][j]!=0 && R[i][j]==J[i][j])
            {
            if(tmin>R[i][j])
                {
                tmin=R[i][j];
                xmin=i;
                ymin=j;
                }
            else if(tmin==R[i][j])
                {
                if(xmin>i){xmin=i;ymin=j;}
                else if(xmin==i)
                    {
                    if(ymin>j)ymin=j;
                    }
                }
            }
        }
    }
}

int main()
{
freopen(inf,"r",stdin);
freopen(outf,"w",stdout);

Citire();
Parcurgere(R,lr,cr);
Parcurgere(J,lj,cj);

int tmin,xmin,ymin;
tmin=xmin=ymin=PINF;

DetSol(tmin,xmin,ymin);
printf("%d %d %d",tmin,xmin,ymin);
return 0;
}

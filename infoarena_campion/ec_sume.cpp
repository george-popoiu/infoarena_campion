#include<stdio.h>
#include<string.h>
#define inf "ec_sume.in"
#define outf "ec_sume.out"
#define MaxN 501
using namespace std;

int smax[MaxN*3][MaxN];
int N,Lg;
int v[MaxN*3];

void Citire()
{
char sir[MaxN*3];
int l,j=0;
scanf("%d",&N);
gets(sir);
*sir=NULL;
gets(sir);
l=strlen(sir);
for(int i=0;i<l;i++)
    {
    if(sir[i]!=' ')
        {
        v[++j]=sir[i]-'0';
        }
    }
Lg=j;
}

void Rezolvare()
{
for(int i=1;i<=3;i++)
    for(int j=1;j<=N;j++)smax[i][j]=-1;
smax[1][1]=v[1];
smax[2][1]=v[1]*10+v[2];
if(v[2])smax[2][2]=v[1]*10+v[2];
smax[3][1]=v[1]*100+v[2]*10+v[1];
if(v[2])smax[3][2]=v[1]+v[2]*10+v[3];
if(v[3] && smax[3][2]<v[1]*10+v[2]+v[3])smax[3][2]=v[1]*10+v[2]+v[3];
if(v[2]&&v[3])smax[3][3]=v[1]+v[2]+v[3];
for(int i=4;i<=Lg;i++)
    {
    smax[i][1]=-1;
    for(int j=2;j<=i;j++)
        {
        if(v[i]==0)smax[i][j]=-1;
        else
            {
            if(smax[i-1][j-1]!=-1)smax[i][j]=smax[i-1][j-1]+v[i];
            }
        if(v[i-1]>0 && smax[i-2][j-1]!=-1 && smax[i-2][j-1]+v[i-1]*10+v[i]>smax[i][j])smax[i][j]=smax[i-2][j-1]+v[i-1]*10+v[i];
        if(v[i-2]>0 && smax[i-3][j-1]!=-1 && smax[i-3][j-1]+v[i-2]*100+v[i-1]*10+v[i]>smax[i][j])smax[i][j]=smax[i-3][j-1]+v[i-2]*100+v[i-1]*10+v[i];
        }
    }
printf("%d",smax[Lg][N]);
}

int main()
{
freopen(inf,"r",stdin);
freopen(outf,"w",stdout);
Citire();
Rezolvare();
return 0;
}

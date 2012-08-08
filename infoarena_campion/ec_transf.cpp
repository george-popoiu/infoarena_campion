#include<fstream>
#include<string.h>
#define inf "ec_transf.in"
#define outf "ec_transf.out"
#define Max 102
#define NrOp 6
#define COPY 0
#define DELETE 1
#define INSERT 2
#define REPLACE 3
#define TWIDDLE 4
#define KILL 5
#define PINF 0x3f3f3f3f
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int cmin[Max][Max],op[Max][Max];
int cost[NrOp];
int N,M;
char sursa[Max];
char destinatie[Max];

void Citire()
{
f.get(sursa+1,Max);
f.get();
f.get(destinatie+1,Max);
f.get();
for(int i=0;i<NrOp;i++)f>>cost[i];
N=strlen(sursa+1);
M=strlen(destinatie+1);
}

void Rezolvare()
{
for(int i=1;i<=M;i++)cmin[0][i]=i*cost[INSERT];
for(int i=1;i<=N;i++)
    {
    cmin[i][0]=PINF;
    if(cmin[i][0]>i*cost[DELETE])cmin[i][0]=i*cost[DELETE];
    if(cmin[i][0]>cost[KILL])cmin[i][0]=cost[KILL];
    }
for(int i=1;i<=N;i++)
    {
    for(int j=1;j<=M;j++)
        {
        cmin[i][j]=PINF;
        //COPY
        if(sursa[i]==destinatie[j] && cmin[i][j]>cost[COPY]+cmin[i-1][j-1]){cmin[i][j]=cost[COPY]+cmin[i-1][j-1];op[i][j]=COPY;}
        //DELETE
        if(cmin[i][j]>cost[DELETE]+cmin[i-1][j]){cmin[i][j]=cost[DELETE]+cmin[i-1][j];op[i][j]=DELETE;}
        //INSERT
        if(cmin[i][j]>cost[INSERT]+cmin[i][j-1]){cmin[i][j]=cost[INSERT]+cmin[i][j-1];op[i][j]=INSERT;}
        //REPLACE
        if(cmin[i][j]>cost[REPLACE]+cmin[i-1][j-1]){cmin[i][j]=cost[REPLACE]+cmin[i-1][j-1];op[i][j]=REPLACE;}
        //TWIDDLE
        if(sursa[i]==destinatie[j-1] && sursa[i-1]==destinatie[j] && cmin[i][j]>cost[TWIDDLE]+cmin[i-2][j-2]){cmin[i][j]=cost[TWIDDLE]+cmin[i-2][j-2];op[i][j]=TWIDDLE;}
        //KILL
        if(cmin[i][j]>cost[KILL]+cmin[0][j]){cmin[i][j]=cost[KILL]+cmin[0][j];op[i][j]=KILL;}
        }
    }
g<<cmin[N][M]<<"\n";
}

void Reconstituire(int i,int j)
{
if(i>=1 && j>=1)
    {
    switch(op[i][j])
        {
        case COPY :
            {
            Reconstituire(i-1,j-1); g<<"COPY ";
            for(int k=1;k<=i;k++)g<<destinatie[k];
            for(int k=i+1;k<=M;k++)g<<sursa[k];
            g<<"\n";
            break;
            }
        case DELETE :
            {
            Reconstituire(i-1,j); g<<"DELETE ";
            for(int k=1;k<=i;k++)g<<destinatie[k];
            for(int k=i+1;k<=M;k++)g<<sursa[k];
            g<<"\n";
            break;
            }
        case INSERT :
            {
            Reconstituire(i,j-1); g<<"INSERT\n"; break;
            /*for(int k=1;k<=i;k++)g<<destinatie[k];
            for(int k=i+1;k<=M;k++)g<<sursa[k];
            g<<"\n";*/
            }
        case REPLACE :
            {
            Reconstituire(i-1,j-1); g<<"REPLACE ";
            for(int k=1;k<=i;k++)g<<destinatie[k];
            for(int k=i+1;k<=M;k++)g<<sursa[k];
            g<<"\n";
            break;
            }
        case TWIDDLE :
            {
            Reconstituire(i-2,j-2); g<<"TWIDDLE ";
            for(int k=1;k<=i;k++)g<<destinatie[k];
            for(int k=i+1;k<=M;k++)g<<sursa[k];
            g<<"\n";
            break;
            }
        case KILL :
            {
            Reconstituire(0,j); g<<"KILL ";
            for(int k=1;k<=i;k++)g<<destinatie[k];
            for(int k=i+1;k<=M;k++)g<<sursa[k];
            g<<"\n";
            break;
            }
        }
    }
}

int main()
{
Citire();
Rezolvare();
Reconstituire(N,M);
f.close();
g.close();
return 0;
}

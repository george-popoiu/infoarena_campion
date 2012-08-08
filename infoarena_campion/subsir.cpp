#include<fstream>
#include<string.h>
#define inf "subsir.in"
#define outf "subsir.out"
#define LMax 510
#define NrC 27
#define MOD 666013
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

char a[LMax],b[LMax];
int cmls[LMax][LMax]; // cmls[i][j]=cel mai lung subsir comun pt prefixele a1,a2,...,ai si b1,b2,...,bj
int aultim[NrC][LMax]; // aultim[i][j]=ultima aparitie a celei de-a i-a litera in prefixul a1,a2,...,aj
int bultim[NrC][LMax]; // bultim[i][j]=ultima aparitie a celei de-a i-a litera in prefizul b1,b2,...,bj
int N,M;
int Nr[LMax][LMax]; // Nr[i][j]=nr de subsiruri comune de lung maxima pt prefixele a1,a2,...,ai si b1,b2,...,bj

void Citire()
{
f.get(a+1,LMax);
f.get();
f.get(b+1,LMax);
N=strlen(a+1);
M=strlen(b+1);
}

int max(int a,int b)
{
if(a>b)return a;
return b;
}

void CalcCmls()
{
for(int i=1;i<=N;i++)
    for(int j=1;j<=M;j++)
        {
        if(a[i]==b[j])cmls[i][j]=1+cmls[i-1][j-1];
        else cmls[i][j]=max(cmls[i-1][j],cmls[i][j-1]);
        }
}

void Preproc()
{
for(int i=1;i<NrC;i++)
    {
    char c='a'+(i-1);
    aultim[i][0]=-1;
    for(int j=1;j<=N;j++)
        {
        if(a[j]==c)aultim[i][j]=j;
        else aultim[i][j]=aultim[i][j-1];
        }
    bultim[i][0]=-1;
    for(int j=1;j<=M;j++)
        {
        if(b[j]==c)bultim[i][j]=j;
        else bultim[i][j]=bultim[i][j-1];
        }
    }
}

void Rezolva()
{
int ii,jj;
for(int i=1;i<=N;i++)
    for(int j=1;j<=M;j++)
        {
        if(cmls[i][j]==1 && a[i]==b[j])Nr[i][j]=1;
        else if(a[i]==b[j])
            {
            for(int k=1;k<NrC;k++)
                {
                ii=aultim[k][i-1];
                jj=bultim[k][j-1];
                if(ii!=-1 && jj!=-1 && cmls[i][j]==1+cmls[ii][jj]){Nr[i][j]+=(Nr[ii][jj]%MOD);Nr[i][j]%=MOD;}
                }
            }
        }
int rez=0;
bool adun=false;
for(int i=1;i<=N;i++)
    for(int j=1;j<=M;j++)
        {
        if(a[i]==b[j] && cmls[i][j]==cmls[N][M])
            {
            adun=true;
            for(int k=i+1;k<=N;k++)
                if(a[i]==a[k]){adun=false;break;}
            for(int k=j+1;k<=M;k++)
                if(b[j]==b[k]){adun=false;break;}
            if(adun){rez+=(Nr[i][j]%MOD);rez%=MOD;}
            }
        }
g<<rez;
}

int main()
{
Citire();
CalcCmls();
Preproc();
Rezolva();
/*g<<"\n";
for(int i=1;i<=N;i++)
    {
    for(int j=1;j<=M;j++)g<<Nr[i][j]<<" ";
    g<<"\n";
    }*/
f.close();
g.close();
return 0;
}

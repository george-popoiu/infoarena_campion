#include<fstream>
#define inf "ec_politie.in"
#define outf "ec_politie.out"
#define MaxT 501
#define MaxN 201
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int smax[MaxN][MaxT][MaxT];
int N,T;
int sum[4],dur[4];
int tip[MaxN],timp[MaxN];

void Citire()
{
f>>T;
for(int i=1;i<4;i++)f>>sum[i]>>dur[i];
f>>N;
for(int i=1;i<=N;i++)f>>tip[i]>>timp[i];
}

void Rezolvare()
{
for(int i=N;i>=1;i--)
    {
    int t=timp[i];
    int tp=tip[i];
    for(int t1=T;t1>=1;t1--)
        {
        for(int t2=T;t2>=1;t2--)
            {
            if(tp<3)
                {
                // Primul politist da amenda
                if(t1<=t)
                    if(smax[i][t1][t2]<sum[tp]+smax[i+1][t+dur[tp]][t2])smax[i][t1][t2]=sum[tp]+smax[i+1][t+dur[tp]][t2];
                // Al doilea politist da amenda
                if(t2<=t)
                    if(smax[i][t1][t2]<sum[tp]+smax[i+1][t1][t+dur[tp]])smax[i][t1][t2]=sum[tp]+smax[i+1][t1][t+dur[tp]];
                }
            else if(tp==3)
                {
                if(t1<=t && t2<=t)
                    {
                    if(smax[i][t1][t2]<sum[tp]+smax[i+1][t+dur[tp]][t+dur[tp]])smax[i][t1][t2]=sum[tp]+smax[i+1][t+dur[tp]][t+dur[tp]];
                    }
                }
            }
        }
    }
g<<smax[1][1][1];
}

int main()
{
Citire();
Rezolvare();
f.close();
g.close();
return 0;
}

#include<fstream>
#define inf "podm.in"
#define outf "podm.out"
#define Max 501
#define PINF 100000000000000000LL
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

unsigned long long C[Max][Max];
unsigned long long D[Max+1];
int N;

void Citire()
{
f>>N;
for(int i=1;i<=N+1;i++)f>>D[i];
}

void Rezolvare()
{
int t,i,j,k;
for(t=1;t<=N-1;t++)
    {
    for(i=1;i<=N-t;i++)
        {
        j=i+t;
        C[i][j]=PINF;
        for(k=i;k<j;k++)
            {
            if(C[i][j]>C[i][k]+C[k+1][j]+D[i]*D[k+1]*D[j+1])C[i][j]=C[i][k]+C[k+1][j]+D[i]*D[k+1]*D[j+1];
            }
        }
    }
g<<C[1][N];
}

int main()
{
Citire();
Rezolvare();
f.close();
g.close();
return 0;
}

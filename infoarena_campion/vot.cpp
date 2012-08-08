#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define inf "vot.in"
#define outf "vot.out"
#define NMax 1010
#define LMax 110
using namespace std;

char *data[NMax];
char *vot[NMax];
char *nume[NMax];

int N,nr;
int adj[NMax];

void read()
{
char *p;
data[0]=new char[LMax];
gets(data[0]);
N=atol(data[0]);
for(int i=1;i<=N;++i)
    {
    data[i]=new char[LMax];
    gets(data[i]);
    p=strtok(data[i],"-");
    nume[i]=strdup(p);
    p=strtok(NULL,"-");
    vot[i]=strdup(p);
    }
//for(int i=1; i<=N; ++i) printf("%s %s\n",nume[i],vot[i]);
}

void compute_adj()
{
for(int i=1; i<=N; ++i)
    for(int j=1; j<=N; ++j)
        if( !strcmp(vot[i],nume[j]) ) { adj[i]=j ; break ; }
}

void solve()
{
for(int i=1; i<=N; ++i)
    if( adj[ adj[i] ] == i ) ++nr;
printf("%d",nr);
}

int main()
{
freopen(inf,"r",stdin);
freopen(outf,"w",stdout);
read();
compute_adj();
solve();
return 0;
}

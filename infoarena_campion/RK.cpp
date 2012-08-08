//#include<fstream>
#include<string.h>
#include<stdio.h>
#define inf "strmatch.in"
#define outf "strmatch.out"
#define D 73
#define MOD1 100007
#define MOD2 100021
#define NMax 2000100
using namespace std;

//fstream f(inf,ios::in),g(outf,ios::out);

char P[NMax],T[NMax];
int N,M;
long long hp1,hp2,ht1,ht2;
int nr;
char sol[NMax];
void read()
{
/*f.get( P+1, NMax );
f.get();
f.get( T+1, NMax );*/
scanf("%s %s",P+1,T+1);
M = strlen( P+1 );
N = strlen( T+1 );
}

void solve()
{
//preprocesare pattern
long long put1=1,put2=1;
for(int i=1; i<=M; i++)
    {
    hp1 = ( hp1*D + P[i] ) % MOD1;
    hp2 = ( hp2*D + P[i] ) % MOD2;
    ht1 = ( ht1*D + T[i] ) % MOD1;
    ht2 = ( ht2*D + T[i] ) % MOD2;
    if( i!=M ) put1 = ( put1*D ) % MOD1 , put2 = (put2*D) % MOD2 ;
    }
//matching
if( M>N )
    {
    printf("0");
    return;
    }
for(int i=1; i<=N-M+1; i++)
    {
    if( hp1==ht1 && hp2==ht2 ) sol[i-1] = 1, ++nr;
    ht1 = ( ( ht1 - put1*T[i] ) % MOD1 + MOD1 ) % MOD1 ;
    ht1 = ( ht1*D + T[i+M] ) % MOD1;

    ht2 = ( ( ht2 - put2*T[i] ) % MOD2 + MOD2 ) % MOD2 ;
    ht2 = ( ht2*D + T[i+M] ) % MOD2;
    }
//g<< nr <<"\n";
//for(int i=1; i<=nr && i<=1000; i++) g<< sol[i] <<" ";
printf("%d\n",nr); nr=0;
for(int i=1; i<=N && nr<=1000; i++)
    if( sol[i] ) printf("%d ",i ) , ++nr ;
}

int main()
{
freopen(inf,"r",stdin);
freopen(outf,"w",stdout);
read(); solve();
//f.close(); g.close();
return 0;
}

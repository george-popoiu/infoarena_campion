#include<fstream>
#include<algorithm>
#include<bitset>
#define inf "cai.in"
#define outf "cai.out"
#define NMax 1100
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int T,N;
int a[NMax],b[NMax];

void solve()
{
int rez=0;
sort( a+1, a+N+1 );
sort( b+1, b+N+1 );
bool egal,mare;
bitset<NMax> uz;
for(int i=1; i<=N; i++)
    {
    egal = mare = false;
    for(int j=1; j<=N; j++)
        if( a[j]>b[i] && !uz[j] ) { mare = true ; uz[j]=1; rez+=200; break ;}
    if( !mare )
        for(int j=1; j<=N; j++)
            if( a[j]==b[i] && !uz[j] ) { uz[j]=1; egal=true; break; }
    if( !mare && !egal )
        for(int j=1; j<=N; j++)
            if( a[j]<b[i] && !uz[j] ) { uz[j]=1; rez-=200; break; }
    }
g<< rez<<"\n";
}

int main()
{
f>>T;
for( ; T; T--)
    {
    f>>N;
    for(int i=1; i<=N; i++) f>> a[i];
    for(int i=1; i<=N; i++) f>> b[i];
    solve();
    }
f.close(); g.close();
return 0;
}

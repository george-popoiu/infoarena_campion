#include<stdio.h>
#define inf "pc.in"
#define outf "pc.out"
#define Max 50
using namespace std;

int G,V;
long long Nr[Max][Max];

inline void read() { scanf("%d%d",&G,&V); }

void solve()
{
for(int i=1; i<=G; i++) Nr[i][0]=i;
for(int i=1; i<=G; i++)
    for(int j=1; j<=V; j++) Nr[i][j]=Nr[i-1][j-1]+Nr[i-1][j]+1;
printf("%lld",Nr[G][V]);
}

int main()
{
freopen(inf,"r",stdin);
freopen(outf,"w",stdout);
read();
solve();
return 0;
}

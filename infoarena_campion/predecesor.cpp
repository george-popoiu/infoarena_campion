#include<stdio.h>
#define inf "predecesor.in"
#define outf "predecesor.out"
#define NMax 500010
using namespace std;

int N,nr;
int v[NMax];
int st[NMax],k;
bool viz[NMax];

void read()
{
scanf("%d",&N);
for(int i=1; i<=N; ++i)scanf("%d",&v[i]);
}

void solve()
{
k=1; st[k]=v[1];
for(int i=2; i<=N; ++i)
    {
    if( v[i]>st[k] ) viz[k]=true , ++k , st[k]=v[i] ;
    else
        {
        while( k )
            {
            if( v[i]<=st[k] )
                {
                if( viz[k] ) viz[k--]=false ;
                else ++nr , --k ;
                }
            else break;
            }
        if( !k ) st[++k]=v[i];
        else viz[k]=true , st[++k]=v[i];
        }
    }
if( k )
    while( k )
        {
        if( !viz[k] ) ++nr;
        --k;
        }
printf("%d",nr);
}

int main()
{
freopen(inf,"r",stdin);
freopen(outf,"w",stdout);
read();
solve();
return 0;
}

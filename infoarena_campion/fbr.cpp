#include<stdio.h>
#include<algorithm>
#define inf "fbr.in"
#define outf "fbr.out"
#define NMax 1001
#define TMax 1000
using namespace std;

struct trupa
{
    int A, B, C;
};

int N;
int C[NMax][TMax+1];
trupa v[NMax];

struct rule
{
    bool operator () (trupa a, trupa b)
    {
        return ( a.B < b.B );
    }
};

void read()
{
    scanf("%d",&N);
    for(int i=1; i<=N; i++) scanf("%d%d%d", &v[i].A, &v[i].B, &v[i].C);
}

void solve()
{
    sort( v+1, v+N+1, rule() );
    for(int i=1; i<=N; i++)
    {
        for(int t=0; t<=TMax; t++)
        {
            C[i][t] = -1;
            if( v[i].B>=t && t-v[i].A>=0 )
            {
                C[i][t] = v[i].C;
                if( C[i-1][t-v[i].A]>=0 ) C[i][t] += C[i-1][t-v[i].A];
            }
        }
    }
    int maxim = -1;
    for(int i=0; i<=TMax; i++)
        if( C[N][i]>maxim ) maxim = C[N][i];
    printf("%d", maxim);
}

int main()
{
    freopen(inf,"r",stdin);
    freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

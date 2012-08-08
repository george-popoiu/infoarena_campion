#include<stdio.h>
#include<algorithm>
#define inf "vedete.in"
#define outf "vedete.out"
#define NMax 210
#define KMax 210
#define TMax 30100
#define VMax 310
using namespace std;

struct vedeta
{
    int t;
    int v;
    int r;
};

vedeta A[NMax];
int s[NMax][KMax];
int N, K, T;

struct rule
{
    bool operator () (vedeta a, vedeta b)
    {
        return ( a.t<b.t );
    }
};

void read()
{
    scanf("%d%d%d", &N, &K, &T);
    for(int i=1; i<=N; i++) scanf("%d", &A[i].t);
    for(int i=1; i<=N; i++) scanf("%d", &A[i].v);
    for(int i=1; i<=N; i++) scanf("%d", &A[i].r);
}

inline int min(int a, int b) { return ( a<b ? a : b ); }

inline int max(int a, int b) { return ( a>b ? a : b ); }

void solve()
{
    sort( A+1, A+N+1, rule() );
    //s[i][k] - suma maxima ce se poate obtine daca usa ramane in starea k
    int tc = 0;
    for(int i=1; i<=N; i++)
    {
        int dt = A[i].t - tc; //diferenta de timp intre vedeta curenta si cea precedenta
        for(int s1 = 0; s1<=K; s1++)
        {
            s[i][s1] = -1;
            for( int s2 = max(0, s1-dt); s2 <= min(K, s1+dt); s2++ ) //starile din care ar fi posibila trecerea din s2 in s1
                if( s[i-1][s2] >= 0 ) //s-a putut ajunge in s2
                {
                    int maxim = s[i-1][s2];
                    if( A[i].r == s1 ) //vedeta poate intra
                        maxim += A[i].v;
                    if( maxim > s[i][s1] ) s[i][s1] = maxim;
                }
        }
        tc = A[i].t;
    }
    int maxim = -1;
    for(int i=0; i<=K; i++)
        if( s[N][i]>=0 && s[N][i]>maxim ) maxim = s[N][i];
    printf("%d", maxim);
}

int main()
{
    freopen(inf,"r",stdin);
    freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

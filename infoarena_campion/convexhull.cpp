#include<stdio.h>
#include<algorithm>
#define inf "infasuratoare.in"
#define outf "infasuratoare.out"
#define NMax 121000
#define INF 0x3f3f3f3f
using namespace std;

struct punct { double x,y; };

int N;
punct A[NMax], S[NMax], P0; int vf;

void read()
{
    scanf("%d",&N);
    punct p; double x,y;
    for(int i=1; i<=N; i++)
    {
        scanf("%lf%lf",&x,&y); p.x=x; p.y=y;
        A[i] = p;
    }
}

struct cmp
{
    bool operator () (const punct &a, const punct &b)
    {
        return ( (double)( ( a.x - P0.x )*( b.y - P0.y) - ( b.x - P0.x )*( a.y - P0.y ) ) > 0 );
    }
};

bool turn_left(punct a, punct b, punct c)
{
    return ( (double)( (b.x - a.x)*(c.y - a.y) - (c.x - a.x)*(b.y - a.y) ) > 0 );
}

void solve()
{
    int minX = INF, minY = INF, ind;
    for(int i=1; i<=N; i++) {
        if( A[i].y < minY ) ind = i, minY = A[i].y, minX = A[i].x;
        else if( A[i].y == minY && A[i].x < minX ) ind = i, minX = A[i].x; }

    swap( A[1], A[ind] ); P0 = A[1];
    sort( A+2, A+N+1, cmp() );

    for(int i=1; i<=N; i++)
    {
        while( vf>=2 && !turn_left( S[vf-1], S[vf], A[i] ) ) vf--;
        S[++vf] = A[i];
    }

    printf("%d\n",vf);
    for(int i=1; i<=vf; i++) printf("%lf %lf\n", S[i].x, S[i].y);
    //for(int i=1; i<=N; i++) printf("%lf %lf\n", A[i].x, A[i].y);
}

int main()
{
    freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

#include<stdio.h>
#include<string.h>
#define inf "obstacole.in"
#define outf "obstacole.out"
#define NMax 200001
#define LgNMax 19
using namespace std;

int N, D, A[NMax];
int C[NMax], d, rez; //C[i] = 1, daca se poate ajunge cu un pantof de lungimea d cu vf in i : C[1] = C[N] = 0;

void read()
{
    scanf("%d%d", &N, &D);
    for(int i=1; i<=N; i++) scanf("%d", &A[i]);
}

bool works(int i)
{
    for(int j=i; j>=i-d+1; j--)
        if( A[j] ) return false;
    return true;
}

bool good()
{
    memset( C, 0, sizeof(C) );
    C[0] = 1;
    for(int i=2; i<N; i++)
    {
        if( A[i] ) continue;
        for(int j=D+d; j>=1; j--)
            if( i-j>=0 && C[i-j] && works(i) ) { C[i] = 1; break; }
    }
    return C[N-1];
}

void solve()
{
    int li = 1, ls = N-2;
    while( li<=ls )
    {
        d = (li+ls)/2;
        if( good() )
        {
            if( d>rez ) rez = d;
            li = d+1;
        }
        else ls = d-1;
    }
    printf("%d", rez);
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

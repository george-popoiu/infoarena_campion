#include<stdio.h>
#include<stack>
#include<math.h>
#define inf "telecab.in"
#define outf "telecab.out"
#define NMax 100001
#define KMax 1001
#define SMax 1001
#define INF 0x3f3f3f3f
using namespace std;

int N, K, S;
int H[NMax], next[NMax];
int tmin[KMax][SMax];

void read()
{
    scanf("%d%d%d", &N, &K, &S);
    for(int i=1; i<=N; i++) scanf("%d", &H[i]);
}

inline int dist(int i, int j) { return (int)( sqrt( (j-i)*(j-i) + (H[j]-H[i])*(H[j]-H[i]) ) ); }

inline int min(int a, int b) { return ( a<b ? a : b ); }

int pd(int i, int s)
{
    if( i>=K ) return 0;
    if( tmin[i][s]!=INF ) return tmin[i][s];

    int j = next[i];
    if( H[i]==H[j] )
    {
        tmin[i][s] = min( tmin[i][s], 1 + pd(j,s) ); //merg orizontal
        return tmin[i][s];
    }
    if( H[i]<H[j] && H[j]-H[i]<=s )
    {
        tmin[i][s] = min( tmin[i][s], dist(i,j) + pd(j, s-(H[j]-H[i])) ); //urc segmentul [i,j]
        return tmin[i][s];
    }
    tmin[i][s] = min( tmin[i][s], dist(i,j) + pd(j, s) ); //cobor normal
    if( H[i]-H[j]<=s ) tmin[i][s] = min( tmin[i][s], 1 + pd(j, s-(H[i]-H[j])) ); //cobor in 1 ora
    return tmin[i][s];
}

void solve()
{
    stack<int> st; st.push(1); next[1] = 2;
    for(int i=2; i<=N; i++)
    {
        while( !st.empty() && H[i] > H[st.top()] ) next[st.top()] = i, st.pop();
        st.push(i); next[i] = i+1;
    }

    //cerinta 1
    int dt = 0;
    for(int i=1; i!=N; )
    {
        dt += dist(i, next[i]);
        i = next[i];
    }
    printf("%d\n", dt);

    //cerinta 2
    for(int i=1; i<K; i++)
        for(int j=0; j<=S; j++) tmin[i][j] = INF;

    printf("%d", pd(1,S)); //programare dinamica cu memoizare
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

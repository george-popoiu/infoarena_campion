#include<stdio.h>
#include<queue>
#define inf "zmeu2.in"
#define outf "zmeu2.out"
#define PMax 201
#define NMax 501
#define INF 0x3f3f3f3f
using namespace std;

short P, N, K, d[PMax], c[PMax];
short A[PMax][PMax];
short best[PMax][NMax]; //best[i][j] - distant min pt a ajunge in povestea i cu j capete

struct stare {
    short D, C, p;
};

queue<stare> q;

void read()
{
    scanf("%hd%hd%hd", &N, &P, &K);

    for(short i=1; i<=P; i++) scanf("%hd%hd", &d[i], &c[i]);

    short p1, p2;
    for(short i=1; i<=K; i++) {
        scanf("%hd%hd", &p1, &p2);
        A[p1][p2] = 1;
    }

    for(short i=1; i<=P; i++) A[i][1] = A[P][i] = 1;
    A[1][P] = 1;
}

inline short min(short a, short b) { return ( a<b ? a : b ); }

void solve()
{
    for(short i=1; i<=P; i++)
        for(short j=1; j<=N; j++) best[i][j] = (short)INF;
    best[1][ N-c[1] ] = d[1];

    stare s, s2; s.p = 1; s.D = d[1]; s.C = N-c[1] ;
    q.push(s);
    while( !q.empty() ) {
        s = q.front(); q.pop();
        for(short i=1; i<=P; i++)
            if( i!=s.p && !A[s.p][i] && s.C-c[i]>=1 && best[i][s.C-c[i]] > d[i] + s.D ) {
                best[i][s.C-c[i]] = d[i] + s.D;
                s2.p = i; s2.D = d[i] + s.D; s2.C = s.C - c[i];
                q.push(s2);
            }
    }

    short rez = (short)INF;
    for(short i=1; i<=N; i++) rez = min(rez, best[P][i]);

    printf("%hd", rez == INF ? -1 : rez );
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

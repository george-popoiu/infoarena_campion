#include<stdio.h>
#include<queue>
#include<string.h>
#define inf "kubus2.in"
#define outf "kubus2.out"
#define DMax 6000001
#define INF 0x3f3f3f3f
using namespace std;

int N, M, nF, nZ;
int d[DMax], in[DMax], d2[DMax];

struct nod {
    int v, w;
    nod *next;
}; nod* G[DMax];

void add(int u, int v, int w) {
    nod *n;
    n->v = v; n->w = w;
    n->next = G[u];
    G[u] = n;
}

void read()
{
    scanf("%d", &N);

    int a, b, c, x, y, z, w, u, v;
    scanf("%d%d%d", &a, &b, &c); nF = (a-1)*N*N + (b-1)*N + c;
    scanf("%d%d%d", &a, &b, &c); nZ = (a-1)*N*N + (b-1)*N + c;

    scanf("%d", &M);
    for(int i=1; i<=M; ++i) {
        scanf("%d%d%d%d%d%d%d", &a, &b, &c, &x, &y, &z, &w);
        u = (a-1)*N*N + (b-1)*N + c;
        v = (x-1)*N*N + (y-1)*N + z;
        printf("%d %d %d\n", u, v, w);
        add(u, v, w); add(v, u, w);
    }
}

void BF(int *d, int S) {
    memset(in, 0, sizeof(in) );
    queue<int> q;

    for(int i=1; i<=6*N*N; ++i) d[i] = INF;
    d[S] = 0;

    q.push(S); in[S] = 1;

    while( !q.empty() ) {
        int u = q.front(); q.pop();
        in[u] = 0;

        nod *t = G[u];
        while(t) {
            int v = t->v, w = t->w;
            if( d[v] > d[u] + w ) {
                d[v] = d[u] + w;
                if( !in[v] ) { in[v] = 1; q.push(v); }
            }
            t = t->next;
        }
    }
}

void solve()
{
    //BF(d, nF);
    /*BF(d2, nZ);

    int sol = INF, sa, sz;
    for(int i=1; i<=6*N*N; ++i)
        if( d[i] + d2[i] < sol ) {
            sol = d[i] + d2[i];
            sa = d[i]; sz = d2[i];
        }
        else if( d[i] + d2[i] == sol && d[i] < sa ) { sa = d[i]; sz = d2[i]; }

    sol == INF ? printf("-1") : printf("%d\n%d %d", sol, sa, sz);*/

    /*nod *t = G[nF];
    while(t) {
        printf("%d %d\n", t->v, t->w);
        t = t->next;
    }*/

    printf("%d %d", nF, nZ);
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read();
	solve();
	return 0;
}

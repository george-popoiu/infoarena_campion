#include<stdio.h>
#include<math.h>
#define inf "retea2.in"
#define outf "retea2.out"
#define Dim 2010
#define ll long long
using namespace std;

const ll INF = 1LL<<60;
const int SN = 2001;

struct punct {
    int x, y;
} b[Dim], c[Dim];

int N, M;
ll D[Dim];
int S[Dim];

inline ll dist(punct a, punct b) {
    return ( 1LL * (a.x - b.x) * (a.x - b.x) ) + ( 1LL * (a.y - b.y) * (a.y - b.y) );
}

inline ll min(ll a, ll b) { return ( a<b ? a : b ); }

void read()
{
    scanf("%d%d", &N, &M);
    for(int i=1; i<=N; i++) scanf("%d%d", &c[i].x, &c[i].y);
    for(int i=1; i<=M; i++) scanf("%d%d", &b[i].x, &b[i].y);
}

void solve()
{
    for(int i = 1; i<=M; i++) {
        D[i] = INF;
        for(int j = 1; j<=N; j++) D[i] = min( D[i], dist(b[i], c[j]) );
    }

    for(int i=1; i<=M; i++) S[i] = SN;

    ll minim, c;
    double cost = 0;
    int j;
    for(int k=1; k<=M; k++) {
        minim = INF;
        for(int i=1; i<=M; i++)
            if(S[i]) {
               if( S[i]==SN ) c = D[i];
               else c = dist( b[i], b[S[i]] );
               if( minim>c ) {
                   minim = c;
                   j = i;
               }
            }
        cost += (long double)(sqrt(minim));
        S[j] = 0;
        for(int i=1; i<=M; i++)
            if( S[i] ) {
                if( S[i]==SN ) c = D[i];
                else c = dist( b[i], b[S[i]] );
                if( c > dist(b[i], b[j]) ) S[i] = j;
            }
    }
    if(!M) cost = 0;
    printf("%.7f\n", cost);
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

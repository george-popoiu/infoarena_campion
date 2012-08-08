#include<stdio.h>
#include<vector>
#include<math.h>
#define inf "dmin.in"
#define outf "dmin.out"
#define NMax 1501
#define MOD 104659
#define INF 100000000000000000LL
#define eps 1e-10
using namespace std;

double D[NMax];
int N, M, P[NMax];
vector< pair<int, double> > G[NMax];

int H[NMax], poz[NMax], hdim;

void read()
{
    scanf("%d%d", &N, &M);

    int a, b, c;
    double cd;
    for(int i=1; i<=M; i++) {
        scanf("%d%d%d", &a, &b, &c);
        cd = log(c);
        G[a].push_back( make_pair(b, cd) );
        G[b].push_back( make_pair(a, cd) );
    }
}

void downheap(int n) {
    int s;
    while( n<hdim ) {
        s = (n<<1);
        if( s<=hdim ) {
            if( s+1<=hdim && -D[ H[s+1] ]+D[ H[s] ] > eps ) s++;
            if( D[ H[n] ] > D[ H[s] ] ) {
                swap( poz[ H[n] ], poz[ H[s] ] );
                swap( H[n], H[s] );
                n = s;
            }
            else return;
        }
        else return;
    }
}

void upheap(int n) {
    int f;
    while( n>1 ) {
        f = (n>>1);
        if( D[ H[f] ] - D[ H[n] ] > eps ) {
            swap( poz[ H[f] ], poz[ H[n] ] );
            swap( H[n], H[f] );
            n = f;
        }
        else return;
    }
}

void solve()
{
    for(int i=1; i<=N; i++) D[i] = INF;
    D[1] = 0; P[1] = 1;

    H[++hdim] = 1; poz[1] = 1;
    while( hdim ) {
        int u = H[1];
        H[1] = H[hdim]; poz[ H[hdim] ] = 1;
        hdim--; downheap(1);

        for(int i=0; i<G[u].size(); i++) {
            int v = G[u][i].first; double w = G[u][i].second;
            if( D[v] - D[u] - w > eps ) {
                D[v] = D[u] + w; P[v] = P[u];
                if( P[v] >= MOD ) P[v] -= MOD;
                if( poz[v] ) upheap( poz[v] );
                else {
                    H[++hdim] = v; poz[v] = hdim;
                    upheap(hdim);
                }
            }
            else if( fabs( D[v] - D[u] - w ) <= eps ) {
                P[v] += P[u];
                if( P[v] >= MOD ) P[v] -= MOD;
            }
        }
    }

    for(int i=2; i<=N; i++) printf("%d ", P[i]);
    /*for(int i=2; i<=N; i++) printf("%llf ", D[i]);*/
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

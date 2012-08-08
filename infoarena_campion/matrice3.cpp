#include<stdio.h>
#define inf "matrice3.in"
#define outf "matrice3.out"
#define DMax 250
#define LMax 8
using namespace std;

short N, M, i, j, k, t;
unsigned char X[DMax][DMax];
unsigned char R[LMax][LMax][DMax][DMax], A[DMax][DMax], B[DMax][DMax], C[DMax][DMax], lg[DMax+1];
int Q;

void read()
{
    scanf("%hd%hd%d", &N, &M, &Q);
    for(int i=0; i<N; i++) scanf("%s", X[i]);
}

inline unsigned char min( unsigned char a, unsigned char b ) { return a<b ? a : b; }

inline unsigned char max( unsigned char a, unsigned char b ) { return a>b ? a : b; }

inline short minS( short a, short b ) { return a<b ? a : b; }

inline bool good(short x, short y, short a, short b, short L) {
    x += L-1; y += L-1;
    short h = a-x+1, w = b-y+1; short dh = lg[h], dw = lg[w];
    return max( R[dh][dw][x][y], max( R[dh][dw][x+h-(1<<dh)][y+w-(1<<dw)],
                max( R[dh][dw][x+h-(1<<dh)][y], R[dh][dw][x][y+w-(1<<dw)] ) ) ) >= L;
}

void solve()
{
    //computing C
    for(i=0; i<N; ++i)
        for(j=0; j<M; ++j)
            if( X[i][j]=='0' ) { A[i][j] = 1 + A[i][ j-1>-1 ? j-1 : j ]; B[i][j] = 1 + B[ i-1>-1 ? i-1 : i ][j]; }

    for(i=0; i<N; ++i)
        for(j=0; j<M; ++j) {
            C[i][j] = min( A[i][j], B[i][j] );
            if( i>0 && j>0 ) C[i][j] = min( C[i][j], 1 + C[i-1][j-1] );
        }
    //computing C

    //RMQ
    lg[1] = 0;
    for(i=2; i<=DMax; ++i) lg[i] = 1+lg[(i>>1)];

    for(i=0; i<N; ++i)
        for(j=0; j<M; ++j) R[0][0][i][j] = C[i][j];

    for(t=1; (1<<t) <= M; ++t)
        for(i=0; i<N; ++i)
            for(j=0; j + (1<<t) - 1 < M; ++j) R[0][t][i][j] = max( R[0][t-1][i][j], R[0][t-1][i][j+(1<<(t-1))] );

    for(k=1; (1<<k) <= N; ++k)
        for(i=0; i + (1<<k) - 1 < N; ++i)
            for(j=0; j < M; ++j) R[k][0][i][j] = max( R[k-1][0][i][j], R[k-1][0][i+(1<<(k-1))][j] );

    for(k=1; (1<<k) <= N; ++k)
        for(t=1; (1<<t) <= M; ++t)
            for(i=0; i + (1<<k) - 1 < N; ++i)
                for(j=0; j + (1<<t) - 1 < M; ++j)
                    R[k][t][i][j] = max( R[k-1][t-1][i][j], max( R[k-1][t-1][i+(1<<(k-1))][j+(1<<(t-1))],
                                    max( R[k-1][t-1][i+(1<<(k-1))][j], R[k-1][t-1][i][j+(1<<(t-1))] ) ) );
    //RMQ

    short x, y, a, b;
    short st, dr, m, ans, g;
    for(; Q; --Q) {
        scanf("%hd%hd%hd%hd", &x, &y, &a, &b); --x; --y; --a; --b;

        st = 1; dr = minS( a-x+1, b-y+1 ); m; g = 0;
        while( st<=dr ) {
            m = st + ((dr-st)>>1);
            if( good(x, y, a, b, m) ) {
                ans = m;
                st = m+1; g = 1;
            }
            else dr = m-1;
        }

        printf("%hd\n", g ? ans : 0);
    }
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

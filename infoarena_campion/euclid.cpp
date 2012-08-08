#include<stdio.h>
#include<vector>
#define inf "euclid.in"
#define outf "euclid.out"
#define DMax 401
#define LMax 10
using namespace std;

int T, N, M, h, w, R[LMax][LMax][DMax][DMax];
int lg[DMax];

int gcd(int a, int b) {
    while(b) {
        int r = a%b;
        a = b; b = r;
    }
    return a;
}

inline int max(int a, int b) { return ( a>b ? a : b ); }

void solve(int t)
{
	for(int l=1; 1<<l <= M; l++)
		for(int i=1; i<=N; i++)
			for(int j=1; j + (1<<l) -1 <=M; j++) R[0][l][i][j] = gcd( R[0][l-1][i][j], R[0][l-1][i][j+(1<<(l-1))] );

	for(int k=1; 1<<k <= N; k++)
		for(int j=1; j<=M; j++)
			for(int i=1; i + (1<<k) -1 <=N; i++) R[k][0][i][j] = gcd( R[k-1][0][i][j], R[k-1][0][i+(1<<(k-1))][j] );

    for(int k=1; 1<<k <= N; k++)
        for(int l=1; 1<<l <= M; l++)
            for(int i=1; i + (1<<k) - 1 <= N; i++)
                for(int j=1; j + (1<<l) - 1 <= M; j++)
                    R[k][l][i][j] = gcd( R[k-1][l-1][i][j], gcd( R[k-1][l-1][i+(1<<(k-1))][j+(1<<(l-1))],
                                    	gcd( R[k-1][l-1][i+(1<<(k-1))][j], R[k-1][l-1][i][j+(1<<(l-1))] ) ) );

    int dh = lg[h], dw = lg[w], sol = 0;
    for(int i=1; i+h-1<=N; i++)
        for(int j=1; j+w-1<=M; j++)
            sol = max( sol, gcd( R[dh][dw][i][j], gcd( R[dh][dw][i+h-(1<<dh)][j+w-(1<<dw)],
                        gcd( R[dh][dw][i+h-(1<<dh)][j], R[dh][dw][i][j+w-(1<<dw)] ) ) ) );

    printf("Case #%d: %d\n", t, sol);
}

void read()
{
    lg[1] = 0;
    for(int i=2; i<DMax; i++) lg[i] = lg[i/2] + 1;

    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d%d%d%d", &N, &M, &h, &w);
        for(int i=1; i<=N; i++)
            for(int j=1; j<=M; j++) scanf("%d", &R[0][0][i][j]);
        solve(t);
    }
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read();
	return 0;
}

#include<stdio.h>
#include<string.h>
#define inf "zip.in"
#define outf "zip.out"
#define NMax 101
#define KMax 110
#define INF 0x3f3f3f3f
using namespace std;

int N, M, K;
int C[NMax][NMax]; //C[i][j] = lung cuvantului obtinut daca se pune in arhivare cuvintele i si j
char A[NMax][KMax];
int best[NMax][NMax]; //best[i][j] = lung minima a unui drum de i noduri ce se termina in nodul j

void read()
{
    scanf("%d%d%d", &N, &M, &K);
    for(int i=1; i<=N; i++) scanf("%s", A[i]+1 );
}

inline int max(int a, int b) { return a>b ? a : b; }

int prefix(char a[], char b[]) { //calc. cel mai lung sufix al lui a[] care este si prefix al lui b[]
    int p[KMax], k = 0;
    p[1] = 0;
    for(int i=2; i<=K; i++) {
        while( k>0 && b[k+1]!=a[i] ) k = p[k];
        if( b[k+1]==a[i] ) k++;
        p[i] = k;
    }
    return p[K] == K ? K-1 : p[K];

    /*int sol = 0, k;
    for(k = 1; k<=K; k++) {
        int g = 1;
        for(int i=1; i<=k; i++)
            if( a[K-k+i] != b[i] ) {
                g = 0;
                break;
            }
        if( g ) sol = max( sol, k );
    }

    return sol == K ? K-1 : sol;*/
}

void solve()
{
    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++) {
            C[i][j] = prefix(A[i], A[j]);
        }

    //for(int i=1; i<=N; i++) best[1][i] = K;

    for(int i=2; i<=M; i++)
        for(int j=1; j<=N; j++) {
            best[i][j] = -INF;
            for(int t=1; t<=N; t++) best[i][j] = max( best[i][j], best[i-1][t] + C[t][j] );
        }

    int sol = -INF;
    for(int i=1; i<=N; i++) sol = max( sol, best[M][i] );

    printf("%d\n", M==1 ? K : M*K - sol);

    char a[] = " abbaa", b[] = " baabb";
    printf("%d", prefix(a, b));
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

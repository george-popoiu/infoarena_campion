#include<stdio.h>
#include<vector>
#define inf "ksecv.in"
#define outf "ksecv.out"
#define NMax 100001
#define Dim 262145
using namespace std;

int A[NMax], N, K;
vector<int> AI[Dim];
int r, start, end, nr;

void read()
{
    scanf("%d%d", &N, &K);
    for(int i=1; i<=N; i++) scanf("%d", &A[i]);
}

void intercl(vector<int> &a, vector<int> b, vector<int> c) {
    int n = b.size(), m = c.size(), i = 0, j = 0;
    while( i<n && j<m ) {
        if( b[i]<=c[j] ) a.push_back(b[i]), i++;
        else a.push_back(c[j]), j++;
    }

    if( i<n )
        for( j=i; j<n; j++ ) a.push_back(b[j]);
    else
        for( i=j; i<m; i++ ) a.push_back(c[i]);
}

void build(int n, int left, int right) {
    if( left==right ) {
        AI[n].push_back(A[left]);
        return;
    }

    int m = (left+right)>>1;
    build(n<<1, left, m);
    build(n<<1 | 1, m+1, right);

    intercl( AI[n], AI[n<<1], AI[n<<1 | 1] );
}

int bs(int nr, vector<int> a) {
    int l = 1, r = a.size(), rez = -1, m;
    while( l<=r ) {
        m = (l+r)>>1;
        if( a[m-1]>nr ) {
            rez = m;
            r = m-1;
        }
        else l = m+1;
    }
    return rez;
}

void query(int n, int left, int right) {
    if( left>=start && right<=end ) {
        int p = bs( nr, AI[n] );
        if( p!=-1 ) r += AI[n].size()-p+1;
        return;
    }

    int m = (left+right)>>1;
    if( start<=m ) query(n<<1, left, m);
    if( m<end ) query(n<<1 | 1, m+1, right);
}

void solve()
{
    build(1, 1, N);

    int left = 1, right = N, m, sol, st, g;
    while( left<=right ) {
        m = (left+right)>>1;
        g = 0;
        for(int i=1; i+m-1<=N; i++) {
            nr = A[i];
            r = 0; start = i; end = i+m-1;
            query(1, 1, N);
            if( r<=K ) {
                sol = m; st = i; g = 1;
                break;
            }
        }
        if(g) left = m+1;
        else right = m-1;
    }

    printf("%d %d", st, st+sol-1);
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

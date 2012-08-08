//2D Segment Trees => Query - O(logN * logN)
#include<stdio.h>
#include<vector>
#include<algorithm>
#define inf "puncte.in"
#define outf "puncte.out"
#define NMax 100010
using namespace std;

struct punct {
    int x, y;
} P[NMax];

vector<int> A[4*NMax];
int start, end, rez;

int N, M;
int x1, y1, x2, y2;

struct cmp {
    bool operator () (const punct &a, const punct &b) {
        return ( a.x < b.x );
    }
};

void intercls(vector<int> &r, vector<int> a, vector<int> b) {
    int n = a.size(), m = b.size();
    int i = 0, j = 0;

    while( i<n && j<m )
        if( a[i] <= b[j] ) {
            r.push_back(a[i]);
            i++;
        }
        else {
            r.push_back(b[j]);
            j++;
        }

    if( i<n )
        for(j = i; j<n; j++) r.push_back(a[j]);
    else
        for(i = j; i<m; i++) r.push_back(b[i]);
}

void build(int n, int left, int right) {
    if( left==right ) {
        A[n].push_back(P[left].y);
        return;
    }

    int m = (left+right)>>1;
    build(n<<1, left, m);
    build(n<<1 | 1, m+1, right);

    intercls(A[n], A[n<<1], A[n<<1 | 1]);
}

int bsxm(int x, int st, int dr) {
    int m, pos = 0;

    while( st<=dr ) {
        m = (st+dr)>>1;
        if( P[m].x >= x ) {
            pos = m;
            dr = m-1;
        }
        else st = m+1;
    }

    return pos;
}

int bsxM(int x, int st, int dr) {
    int m, pos = 0;

    while( st<=dr ) {
        m = (st+dr)>>1;
        if( P[m].x <= x ) {
            pos = m;
            st = m+1;
        }
        else dr = m-1;
    }

    return pos;
}

int bs(int y, vector<int> v) {
    int st = 1, dr = v.size(), p = -1, m;

    while( st<=dr ) {
        m = (st+dr)>>1;
        if( v[m-1]>=y ) {
            p = m-1;
            dr = m-1;
        }
        else st = m+1;
    }

    return p;
}

void query(int n, int left, int right) {
    if( left>=start && right<=end ) {
        int p = bs(y2, A[n]);
        if( p==-1 ) return;
        for(int i = p; A[n][i] <= y1 && i < A[n].size(); i++) rez++;
        return;
    }

    int m = (left+right)>>1;
    if( m>=start ) query(n<<1, left, m);
    if( m<end ) query(n<<1 | 1, m+1, right);
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);


	scanf("%d%d", &N, &M);
	for(int i=1; i<=N; i++) scanf("%d%d", &P[i].x, &P[i].y);

	sort(P+1, P+N+1, cmp());
	build(1, 1, N);

	for(int k=1; k<=M; k++) {
	    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
	    start = bsxm(x1, 1, N); end = bsxM(x2, 1, N);
	    rez = 0; query(1, 1, N);
	    printf("%d\n", rez);
	}

	return 0;
}

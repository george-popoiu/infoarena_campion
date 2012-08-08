#include<stdio.h>
#include<set>
#define inf "bile4.in"
#define outf "bile4.out"
#define NMax 30001
#define DMax 65000
#define Max 30000
using namespace std;

set< pair<int, int> > A[DMax];
typedef set< pair<int, int> >::iterator tit;
//set<int> B[DMax];
int N, M;
int op, a, b, p, k;
int start, end;
int rez, val;

void insert_freq( set< pair<int,int> > &tree, int n, int f) {
    tit it = tree.lower_bound( make_pair(n, 0) );
    if( it!=tree.end() && it->first==n ) {
        int of = it->second;
        tree.erase(it);
        tree.insert( make_pair(n, of+f) );
    }
    else tree.insert( make_pair(n, f) );
}

bool intersect(int a, int b, int c, int d, int &len) {
    if( c<=a && b<=d ) {
        len = b-a+1;
        return true;
    }
    if( a<=c && d<=b && d>=a ) {
        len = d-a+1;
        return true;
    }
    if( c>=a && b<=d && c<=b ) {
        len = b-c+1;
        return true;
    }
    return false;
}

void update(int n, int left, int right) { //p, start, end
    if( left>=start && right<=end ) {
        insert_freq(A[n], p, right-left+1);
        return;
    }
    else {
        int len;
        if( intersect(start, end, left, right, len) ) insert_freq( A[n], p, len );
    }

    int m = (left+right)>>1;
    if( m>=start ) update(n<<1, left, m);
    if( m<end ) update(n<<1 | 1, m+1, right);
}

int query(int n, int left, int right) {//start, end, val => rez
    /*if( left>=start && right<=end ) {
        return;
    }

    int m = (left+right)>>1;
    if( m>=start ) query(n<<1, left, m);
    if( m<end ) query(n<<1 | 1, m+1, right);*/
    return 0;
}

void solve()
{
    scanf("%d%d", &N, &M);

    for(int i=1; i<=M; i++) {
        scanf("%d%d%d", &op, &a, &b);
        if( op==1 ) {
            scanf("%d", &p);
            start = a; end = b;
            update(1, 1, N);
            //printf("%d %d %d %d\n", op, a, b, p);
            continue;
        }
        scanf("%d", &k);
        start = a; end = b;
        //printf("%d %d %d %d\n", op, a, b, k);
        int l = 1, r = Max, m, g = 0;
        while( l<=r ) {
            m = (l+r)>>1;
            rez = 0; val = m; query(1, 1, N);
            if( rez==k-1 ) {
                printf("%d\n", m);
                g = 1;
                break;
            }
            if( rez<k ) l = m+1;
            else r = m-1;
        }
        if( !g ) printf("-1\n");
    }
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
    solve();
	return 0;
}

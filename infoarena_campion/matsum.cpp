#include<stdio.h>
#include<vector>
#include<string.h>
#define inf "matsum.in"
#define outf "matsum.out"
#define NMax 1025
using namespace std;

int T, N;
int M[NMax][NMax], AIB[NMax][NMax];
vector< pair<int, int> > set;
char op[3];

inline int bit(int i) { return (i & (-i)); }

void update(int x, int y, int val) {
    for(int i = x; i <= N; i += bit(i))
        for(int j = y; j <= N; j += bit(j))
            AIB[i][j] += val;
}

void update2(int x, int y, int val) {
    for(int i = x; i <= N; i += bit(i))
        for(int j = y; j <= N; j += bit(j))
            AIB[i][j] = val;
}

int query(int x, int y) {
    int rez = 0;
    if( !x || !y ) return rez;
    for(int i = x; i > 0; i -= bit(i))
        for(int j = y; j > 0; j -= bit(j))
            rez += AIB[i][j];
    return rez;
}

int main()
{
    //freopen(inf, "r", stdin); freopen(outf, "w", stdout);

    int x, y, val;
    int x1, y1, x2, y2;

    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        scanf("%d", &N);
        while(true) {
            scanf("%s", op);
            if( !strcmp(op, "END") ) break;
            else if( !strcmp(op, "SET") ) {
                scanf("%d%d%d", &x, &y, &val);
                x++; y++;
                set.push_back( make_pair(x,y) );
                update(x, y, val - M[x][y]);
                M[x][y] = val;
                //printf("%d %d %d\n", x, y, val);
            }
            else if( !strcmp(op, "SUM") ) {
                scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
                x1++; y1++; x2++; y2++;
                printf("%d\n", query(x2, y2) - query(x2, y1-1) - query(x1-1, y2) + query(x1-1, y1-1));
                //printf("%d %d %d %d\n", x1, y1, x2, y2);
            }
        }
        for(int i=0; i<set.size(); i++) {
            update2( set[i].first, set[i].second, 0 );
            M[set[i].first][set[i].second] = 0;
        }
        set.clear();
    }

	return 0;
}

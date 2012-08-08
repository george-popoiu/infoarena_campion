#include<stdio.h>
#include<string.h>
#include<vector>
#define inf "ratina.in"
#define outf "ratina.out"
#define NMax 10001
#define MMax 100001
#define LMax 2010
#define INF 0x3f3f3f3f
using namespace std;

struct Trie {
    Trie *fiu[26];

    Trie() {
        memset(fiu, 0, sizeof(fiu));
    }
};

Trie *T = new Trie();

vector<Trie*> C[NMax];
char S[NMax][LMax];
int N, M, x[10], t;

inline int ch(char *s) { return *s-'a'; }

void insert(Trie *nod, char *s, int c) {
    if( *s=='\n' ) return;

    int f = ch(s);
    if( nod->fiu[f]==0 ) nod->fiu[f] = new Trie();

    C[c].push_back(nod->fiu[f]);
    insert(nod->fiu[f], s+1, c);
}

void read()
{
    scanf("%d%d", &N, &M);
    for(int i=1; i<=N; i++) {
        scanf("%s", S[i]);
        S[i][strlen(S[i])] = '\n';
        insert(T, S[i], i);
    }
}

inline int max(int a, int b) { return a>b ? a : b; }
inline int min(int a, int b) { return a<b ? a : b; }

int bs() {
    int lim = 0, trsh = INF;
    for(int i=0; i<t; i++) {
        lim = max(lim, strlen(S[x[i]]));
        trsh = min(trsh, strlen(S[x[i]]));
    }

    int st = 1, dr = lim, m, rez = 0;
    while( st<=dr ) {
        m = (st+dr)>>1;
        if( m>trsh ) {
            dr = m-1;
            continue;
        }

        int g = 1, val = C[x[1]].size()-m+1;
        for(int i=1; i<t; i++)
            if( C[x[i]].size()-m+1 != val ) { g = 0; break; }

        if(g) {
            rez = m;
            st = m+1;
        }
        else dr = m-1;
    }

    return rez;
}

void solve()
{
    for(int i=1; i<=M; i++) {
        scanf("%d", &t);
        for(int i=0; i<t; i++) scanf("%d", &x[i]);
        printf("%d\n", bs());
    }
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

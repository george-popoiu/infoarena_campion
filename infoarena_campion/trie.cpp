#include<stdio.h>
#include<string.h>
#define inf "trie.in"
#define outf "trie.out"
#define DMax 30;
using namespace std;

char linie[30];

struct Trie {
    int cnt, nrfii;
    Trie *fiu[26];

    Trie() {
        cnt = nrfii = 0;
        memset( fiu, 0, sizeof(fiu) );
    }
};

Trie *T = new Trie();

inline int nchar(char *s) { return *s-'a'; }

void insert(Trie *nod, char *s) {
    if( *s=='\n' ) {
        nod->cnt++;
        return;
    }

    int f = nchar(s);
    if( nod->fiu[f]==0 ) {
        nod->nrfii++;
        nod->fiu[f] = new Trie;
    }

    insert( nod->fiu[f], s+1 );
}

int del(Trie *nod, char *s) {
    if( *s=='\n' ) {
        nod->cnt--;
    }
    else if( del(nod->fiu[nchar(s)], s+1) ) {
        nod->nrfii--;
        nod->fiu[nchar(s)] = 0;
    }

    if( nod->cnt==0 && nod->nrfii==0 && nod!=T ) {
        delete nod; return 1;
    }
    return 0;
}

int que(Trie *nod, char *s) {
    if( *s=='\n' ) return nod->cnt;

    int f = nchar(s);
    if( nod->fiu[f] ) return que( nod->fiu[f], s+1 );
    return 0;
}

int pre(Trie *nod, char *s, int k) {
    int f = nchar(s);
    if( *s=='\n' || nod->fiu[f]==0 ) return k;
    return pre(nod->fiu[f], s+1, k+1);
}

void solve()
{
    while( !feof(stdin) ) {
        if( fgets( linie, 30, stdin )==NULL ) continue;
        switch( linie[0] ) {
            case '0' : insert(T, linie+2); break;
            case '1' : del(T, linie+2); break;
            case '2' : printf("%d\n", que(T, linie+2)); break;
            case '3' : printf("%d\n", pre(T, linie+2, 0)); break;
        }
    }
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	solve();
	return 0;
}

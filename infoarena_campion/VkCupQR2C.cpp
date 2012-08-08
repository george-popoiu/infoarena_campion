#include<stdio.h>
#include<list>
#include<string.h>
#include<vector>
#include<algorithm>
#define inf "test.in"
#define outf "test.out"
#define kmax 2010
#define lmax 110
using namespace std;

int k, n, m;
char s[lmax];
list<int> poz[28];
list<int>::iterator it;

vector< pair<int,char> > V;

void read()
{
    scanf("%d%s%d", &k, s, &n);

    m = strlen(s);
    for(int i=0; i<m; i++) {
        int j = s[i]-'a';
        poz[j].push_back(i);
        for(int t=1; t<k; t++) poz[j].push_back( i+t*m );
    }

    /*for(int i=0; i<28; i++) {
        for(it=poz[i].begin(); it!=poz[i].end(); ++it) printf("%d ", *it);
        if( poz[i].size() ) printf("\n");
    }*/

    int p; char c;
    for(int t=1; t<=n; t++) {
        scanf("%d %c", &p, &c);

        int j = c-'a', i;
        for(i=1, it=poz[j].begin(); it!=poz[j].end() && i<p; ++it, ++i) ;
        poz[j].remove(*it);
    }

    for(int i='a'; i<='z'; i++) {
        c = (char)(i);
        for(it=poz[i-'a'].begin(); it!=poz[i-'a'].end(); ++it) V.push_back( make_pair(*it, c) );
    }

    sort( V.begin(), V.end() );
    for(int i=0; i<V.size(); i++) printf("%c", V[i].second);
}

int main()
{
//	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read();
	return 0;
}

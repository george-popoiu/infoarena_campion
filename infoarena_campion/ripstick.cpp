#include<stdio.h>
#include<set>
#define inf "ripstick.in"
#define outf "ripstick.out"
#define NMax 100001
using namespace std;

int N, A, B;
int best[NMax], s[NMax], v[NMax];
multiset< pair<int,int> > tree;
multiset< pair<int,int> >::iterator it;

void read()
{
    scanf("%d%d%d", &N, &A, &B);
    for(int i=1; i<=N; i++) {
        scanf("%d", &v[i]);
        s[i] = v[i]+s[i-1];
    }
}

void solve()
{
    best[1] = s[1];

    tree.insert( make_pair(0, 0) ); tree.insert( make_pair(s[1], 1) );

    for(int i=2; i<=N; i++) {
        //for( it=tree.begin(); it!=tree.end(); ++it ) printf("[%d %d] ", it->first, it->second);

        best[i] = v[i] + best[i-1];

        it = tree.lower_bound( make_pair(s[i]-B, 0) );
        while( it!=tree.end() && s[i] - it->first <= B ) {
            //printf("Gasit [%d %d] ", it->first, it->second);
            if( s[i] - it->first >= A && best[i] > A + best[ it->second ] ) best[i] = A + best[ it->second ];
            it++;
        }

        //printf(" Best : %d\n", best[i]);
        tree.insert( make_pair(s[i], i) );
    }

    printf("%d", best[N]);
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

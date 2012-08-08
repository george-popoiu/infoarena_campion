#include<stdio.h>
#include<bitset>
#include<vector>
#define inf "difprim.in"
#define outf "difprim.out"
#define Max 10000001
#define INF 0x3f3f3f3f
using namespace std;

int A, B;
bitset<Max> c;
vector<int> v;

void read()
{
    scanf("%d%d", &A, &B);
}

void solve()
{
    for(int i=2; i<=B; ++i)
        if( !c[i] ) {
            for(int j=i<<1; j<=B; j += i) c[j] = 1;
            if( i>=A ) v.push_back(i);
        }

    if( v.size()<2 ) { printf("-1"); return; }

    int ind = 1, sol = v[1] - v[0];
    for(int i=2; i<v.size(); i++)
        if( v[i]-v[i-1]>sol ) { sol = v[i]-v[i-1]; ind = i; }

    printf("%d %d", v[ind-1], v[ind]);
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

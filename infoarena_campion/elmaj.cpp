#include<fstream>
#include<map>
#define inf "elmaj.in"
#define outf "elmaj.out"
#define NMax 1000001
using namespace std;

fstream f(inf, ios::in), g(outf, ios::out);

int n, v[NMax];
map<int, int> H;

void read()
{
    //scanf("%d", &n);
    f>>n;
    for(int i=1; i<=n; i++) //scanf("%d", &v[i]);
        f>>v[i];
}

void solve()
{
    for(int i=1; i<=n; i++) H[ v[i] ]++;

    for(int i=1; i<=n; i++)
        if( H[ v[i] ] > n/2 ) {
            //printf("%d %d", v[i], H[ v[i] ] );
            g<<v[i] <<" "<< H[ v[i] ];
            return;
        }

    //printf("-1");
    g<<"-1";
}

int main()
{
	//freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	f.close(); g.close();
	return 0;
}

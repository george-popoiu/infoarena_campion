#include<fstream>
#include<set>
#define inf "sea2.in"
#define outf "sea2.out"
using namespace std;

fstream f(inf, ios::in), g(outf, ios::out);

int N;
set< pair<int, int> > Tree;
set< pair<int, int> >::iterator It, It2, t;

int main()
{
    f>>N;

    int x, y;
    for(int i=1; i<=N; i++) {
        f>>x>>y;
        It = Tree.upper_bound( make_pair(x,y) );
        if( It != Tree.end() && It->second > y ) {
            g<<"-1\n";
            continue;
        }
        if( Tree.size() ) {
            It2 = It;
            while( It2 != Tree.begin() ) {
                t = It2; t--;
                if( t->second < y ) It2 = t;
                else break;
            }
            Tree.erase(It2, It);
        }
        Tree.insert( make_pair(x,y) );
        g<<Tree.size()<<"\n";
    }

	f.close(); g.close();
	return 0;
}

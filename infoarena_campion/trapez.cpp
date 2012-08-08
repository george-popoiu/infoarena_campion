#include<fstream>
#include<list>
#include<vector>
#include<hash_map>
#define inf "trapez.in"
#define outf "trapez.out"
#define NMax 1100
#define MOD 666013
using namespace std;
using namespace __gnu_cxx;

fstream f(inf,ios::in),g(outf,ios::out);

const double Y = 0.6180339887;
const int M = 666013;

inline double frac( double x )
{
    int a = (int)x;
    if( x<0 ) return (double)( 1 + (double)(x - (double)(a)) );
    return (double)(x - (double)(a));
}

inline int intreg( double x )
{
    if( x<0 ) return ((int)(x) - 1);
    return (int)(x);
}

struct punct { double x,y; };
punct p[NMax];
int N, perpendiculare;
list< pair<double,int> > H[M+10];
list< pair<double,int> >::iterator it;
vector<int> positions; bool is_pos[M+10];

inline int h(double x)
{
    return intreg( (double)( (double)(M) * frac(Y*x) ) );
}

template<class T> int hashd(const T &x)
{
    return h(x);
}

hash_map< double, int, hashd > H;

inline void insert( double key )
{
    int poz = h(key);// g<<poz<<"\n";
    if( !is_pos[poz] ) is_pos[poz] = true, positions.push_back(poz) ;
    if( !H[poz].size() ) H[poz].push_back( make_pair(key,1) );
    else
    {
        for( it=H[poz].begin(); it!=H[poz].end(); it++ )
            if( (*it).first==key ) { (*it).second++; return; }
        H[poz].push_back( make_pair(key,1) );
    }
}

void read()
{
    f>>N; double x,y;
    for(int i=1; i<=N; i++)
    {
        f>>x>>y;
        p[i].x = x; p[i].y = y;
    }
}

void solve()
{
    for(int i=1; i<N; i++)
        for(int j=i+1; j<=N; j++)
            if( p[i].x == p[j].x ) perpendiculare++;
            else
            {
                double panta = (double)( (p[j].y-p[i].y)/(p[j].x-p[i].x) );
                insert(panta);
            }
    int nr = perpendiculare*(perpendiculare-1)/2;
    for(int j=0; j<positions.size(); j++)
    {
        int i = positions[j];
        if( H[i].size() )
            for( it=H[i].begin(); it!=H[i].end(); it++ ) nr += (*it).second * ( (*it).second - 1 ) / 2;
    }
    g<< nr <<"\n";
}

int main()
{
	read(); solve();
	f.close(); g.close();
	return 0;
}

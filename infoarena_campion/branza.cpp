#include<fstream>
#include<deque>
#define inf "branza.in"
#define outf "branza.out"
#define NMax 100100
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int N,S,T;
int C[NMax],P[NMax];
long long m[NMax];

struct elem { int ind; long long val; };

deque<elem> coada;

void read()
{
f>>N>>S>>T;
for(int i=1; i<=N; i++) f>> C[i] >> P[i] ;
}

void solve()
{
m[1] = C[1];
elem a;
a.val = C[1]+S*(N-1);
a.ind = 1;
coada.push_back( a );
for(int i=2; i<=N; i++)
    {
    m[i] = C[i];
    elem t = coada.front();
    if( m[i] > t.val - (long long)( (N-i)*S ) ) m[i] = t.val - (long long)( (N-i)*S );
    if( i-t.ind == T ) coada.pop_front();
    elem p;
    p.val = (long long) ( C[i]+(N-i)*S );
    p.ind = i;
    if( coada.empty() ) coada.push_back( p );
    else
        {
        t = coada.back();
        while( t.val > p.val && !coada.empty() )
            {
            coada.pop_back();
            if( !coada.empty() ) t = coada.back();
            }
        coada.push_back( p );
        }
    }
long long result=0;
for(int i=1; i<=N; i++) result += (m[i]*P[i]);
g<< result;
}

int main()
{
read(); solve();
f.close(); g.close();
return 0;
}

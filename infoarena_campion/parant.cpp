#include<fstream>
#define inf "parant.in"
#define outf "parant.out"
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int n;
int nd,ni;
char s[100];

void read()
{
f>>n;
}

void back(int k)
{
if( k==n ) g<<s<<"\n";
else
    {
    if( nd<n/2 )
        {
        nd++;
        s[k]='(';
        back(k+1);
        nd--;
        }
    if( ni<nd )
        {
        ni++;
        s[k]=')';
        back(k+1);
        ni--;
        }
    }
}

void solve()
{
back(0);
}

int main()
{
read();
solve();
f.close();
g.close();
return 0;
}

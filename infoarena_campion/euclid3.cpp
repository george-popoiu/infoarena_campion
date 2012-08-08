#include<fstream>
#define inf "euclid3.in"
#define outf "euclid3.out"
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

void euclid(int a,int b,int &d,int &x,int &y)
{
if( !b )
    {
    x=1;
    y=0;
    d=a;
    }
else
    {
    int x0,y0;
    euclid( b, a%b, d, x0, y0 );
    x= y0;
    y= x0 - (a/b)*y0;
    }
}

void read()
{
int T,a,b,c;
int d,x,y;
f>>T;
for( ; T; --T )
    {
    f>>a>>b>>c;
    euclid(a,b,d,x,y);
    if( c%d ) g<<"0 0\n";
    else g<< x*(c/d) <<" "<< y*(c/d)<<"\n";
    }
}

int main()
{
read();
f.close();
g.close();
return 0;
}

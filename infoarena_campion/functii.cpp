#include<fstream>
#define inf "functii.in"
#define outf "functii.out"
#define MOD 30103
#define NMax 10010
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int n,s;

void inv(int *x,int *y,int a,int b)
{
if( !b ) { *x=1; *y=0; }
else
    {
    int x0,y0;
    inv(&x0,&y0,b,a%b);
    *x=y0;
    *y=x0-(a/b)*y0;
    }
}

int inv_fact(int n)
{
int fn=1;

for( int i=1; i<=n; i++ ) fn = (fn*i) % MOD ;

int invn,y;

inv(&invn,&y,fn,MOD);

if( invn<0 ) invn = MOD + invn%MOD ;

return invn;
}

int mod_fact(int n)
{
int fn=1;
for(int i=1; i<=n; i++) fn = (fn*i) % MOD ;
return fn;
}

inline void read() { f>>n>>s; }

void solve()
{
if( s>n || s==n || s<0 ) { g<<"0"; return; }

int comn,nr=1,rez;

comn = ( mod_fact(n)*inv_fact(n-s) ) % MOD;

for(int i=1; i<=s; i++) nr = (nr*2)%MOD;
nr -= 2;

int x,y;
inv(&x,&y,mod_fact(s),MOD);
if( x<0 ) x = MOD + x%MOD;

rez = ( ( (comn*nr) % MOD )*x ) % MOD;
g<<rez;
}

int main()
{
read();
solve();
f.close();
g.close();
return 0;
}

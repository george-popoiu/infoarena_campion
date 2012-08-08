#include<fstream>
#include<string.h>
#define inf "prefix.in"
#define outf "prefix.out"
#define LMax 1000100
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int T;
char *s;
int urm[LMax],n;

int prefix()
{
int k=0,l=0,t;
urm[1]=0;
for(int i=2; i<=n; i++)
    {
    while( k>0 && s[k+1]!=s[i] ) k=urm[k];
    if( s[k+1]==s[i] ) k++;
    urm[i]=k;
    if( k && i%(i-k)==0 ) l = i;
    }
g<< l <<"\n";
}

void read()
{
f>>T; f.get();
for( ; T; T-- )
    {
    s = new char[LMax];
    f.get( s+1, LMax-1 ); f.get();
    n = strlen(s+1);
    memset( urm, 0, sizeof(int)*LMax );
    prefix();
    delete s;
    }
}

int main()
{
read();
f.close(); g.close();
return 0;
}

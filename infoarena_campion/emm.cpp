#include<fstream>
#include<string.h>
#include<stdlib.h>
#define inf "emm.in"
#define outf "emm.out"
#define LMax 100100
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

char s[LMax];
char fp[LMax][20];
int len,n;

inline void read()
{
f.get( s+1, LMax );
len = strlen( s+1 );
}

int prioritate(char op)
{
if( op=='(' ) return 0;
return 1;
}

void transforma()
{
int k=0,j,l;
char st[LMax];
for(int i=1; i<=len; i++)
    if( s[i]>='0' && s[i]<='9' )
        {
        n++;
        j=i;
        l=0;
        while( s[j]>='0' && s[j]<='9' ) fp[n][ l++ ] = s[j++] ;
        j--;
        i=j;
        }
    else if( s[i]=='(' ) st[++k] = s[i];
    else if( s[i]==')' )
        {
        while( st[k]!='(' ) fp[++n][0]=st[k--] ;
        k--;
        }
    else
        {
        if( k )
            while( prioritate( s[i] ) <= prioritate( st[k] ) && k ) fp[++n][0] = st[k--] ;
        k++;
        st[k] = s[i];
        }
while( k ) fp[++n][0] = st[k--] ;
}

inline int min(int a,int b) { return ( a<b ? a : b ) ; }

inline int max(int a,int b) { return ( a>b ? a : b ) ; }

void solve()
{
transforma();
//evaluarea expresiei in forma poloneza
int st[LMax],k=0,rez;
for( int i=1; i<=n; i++ )
    if( fp[i][0]>='0' && fp[i][0]<='9' ) st[++k] = atol( fp[i] );
    else
        {
        switch( fp[i][0] )
            {
            case 'm' : rez = min( st[k-1], st[k] ); break;
            case 'M' : rez = max( st[k-1], st[k] ); break;
            }
        st[--k]=rez;
        }
g<< st[k];
}

int main()
{
read(); solve();
f.close(); g.close();
return 0;
}

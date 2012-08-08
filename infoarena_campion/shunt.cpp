#include<fstream>
#include<stdlib.h>
#define inf "evaluare.in"
#define outf "evaluare.out"
#define LMax 100100
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

char s[LMax];
int len;
char fp[LMax][20];
int n;

inline void read()
{
f.get(s+1,LMax);
len = strlen(s+1);
}

inline int prioritate(char op)
{
if( op=='(' ) return 0;
if( op=='+' || op=='-' ) return 1;
return 2;
}

void transforma()
{
char st[LMax];
int k=0,l,j;
for( int i=1; i<=len; i++ )
    if( s[i]>='0' && s[i]<='9' )
        {
        n++;
        j = i;
        l=0;
        while( s[j]>='0' && s[j]<='9' ) fp[n][ l++ ] = s[j++] ;
        j--;
        i=j;
        }
    else if( s[i]=='(' )
        {
        k++;
        st[k] = '(';
        }
    else if( s[i]==')' )
        {
        while( st[k]!='(' ) n++, fp[n][0] = st[k--] ;
        k--;
        }
    else
        {
        if( k )
            while( prioritate( s[i] ) <= prioritate( st[k] ) && k  ) n++, fp[n][0]=st[k] , k-- ;
        k++;
        st[k] = s[i];
        }
while( k ) fp[++n][0] = st[k--];
}

void solve()
{
transforma();
int st[LMax],k=0,rez;
for( int i=1; i<=n; i++ )
    if( fp[i][0]>='0' && fp[i][0]<='9' ) st[++k] = atol( fp[i] );
    else
        {
        switch( fp[i][0] )
            {
            case '+' : rez = st[k-1]+st[k]; break;
            case '-' : rez = st[k-1]-st[k]; break;
            case '*' : rez = st[k-1]*st[k]; break;
            case '/' : rez = st[k-1]/st[k]; break;
            }
        k--;
        st[k]=rez;
        }
g<< st[k];
}

int main()
{
read(); solve();
f.close(); g.close();
return 0;
}

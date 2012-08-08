#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stack>
#define inf "text3.in"
#define outf "text3.out"
#define CMax 20100
#define LCMax 30
#define LMax 300
#define INF 0x3f3f3f3f
#define MOD 96
using namespace std;

char *c[CMax];
int nrc;
int A[LCMax];
int uz[LCMax];
int prec[CMax];
int m[CMax];

void read()
{
char *linie = new char[LMax];
while( scanf("%s",linie) != EOF )
    {
    char *p = strtok( linie," " );
    while( p )
        {
        nrc++;
        c[nrc] = new char[LCMax];
        strcpy( c[nrc], p );
        p = strtok(NULL, " " );
        }
    delete linie;
    linie = new char[LMax];
    //memset( linie, NULL, sizeof(char)*LMax );
    }
}

void afis(int poz)
{
stack<int> st;
while( poz )
    {
    st.push(poz);
    poz = prec[poz];
    }
int t;
while( !st.empty() )
    {
    t = st.top(); st.pop();
    if( t ) printf("%s\n",c[ t ] );
    }
}

void solve()
{
for( int i=1; i<=nrc; i++ )
    {
    tolower( c[i][ strlen(c[i])-1 ] );
    tolower( c[i][0] );
    char x = c[i][ strlen(c[i])-1 ] ;
    char y = c[i][0] ;
    int a = (int)(x)%MOD;
    int b = (int)(y)%MOD;
    m[i] = A[b]+1;
    uz[b] = i;
    if( m[i]>= ) A[a] = A[b]+1 , uz[a]=i , prec[i]=uz[b] ;
    }

int maxim=-INF;
int poz=0;
for( int i=1; i<=26; i++ )
    if( maxim < A[i] ) maxim = A[i] , poz=i ;
printf("%d\n%d\n",nrc,nrc-maxim);
afis(uz[poz]);
/*int k=0;
int p = uz[poz];
while( p )
    {
    c2[++k]=p;
    p = prec[p];
    }
for( int i=k; i>=1 ; i-- ) printf("%s\n", c[ c2[i] ] );*/
}

int main()
{
freopen(inf,"r",stdin);
freopen(outf,"w",stdout);
read(); solve();
//printf("%d", sizeof(short) );
return 0;
}

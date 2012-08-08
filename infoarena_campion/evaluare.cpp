//#include<stdio.h>
#include<fstream>
#include<string.h>
#include<stdlib.h>
#define inf "evaluare.in"
#define outf "evaluare.out"
#define LMax 100100
#define Max 60000
#define INF 0x3f3f3f3f
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int n;
int pfp[Max];
char efp[Max][20];
char sir[LMax];
int fp[Max];
int t;
int st[Max];

struct Nod
{
int nr;
Nod *as,*ad;
};

Nod *v;

void read()
{
f.get(sir+1,LMax);
int i,j=0,l,len,k;
len = strlen(sir+1);
for( i=1; i<=len; ++i )
    if( sir[i]=='(' ) { j+=10; continue; }
    else if( sir[i]==')' ) { j-=10; continue; }
    else if( sir[i]=='+' ) { ++n; pfp[n]=1+j; efp[n][0]='+'; continue; }
    else if( sir[i]=='-' ) { ++n; pfp[n]=1+j; efp[n][0]='-'; continue; }
    else if( sir[i]=='*' ) { ++n; pfp[n]=10+j; efp[n][0]='*'; continue; }
    else if( sir[i]=='/' ) { ++n; pfp[n]=10+j; efp[n][0]='/'; continue; }
    else if( sir[i]>='0' && sir[i]<='9' )
        {
        ++n;
        pfp[n]=INF;
        l=0;
        efp[n][l]=sir[i];
        k=i+1;
        while( sir[k]>='0' && sir[k]<='9' ) { efp[n][ ++l ] = sir[k] ; ++k; }
        k--;
        i=k;
        }
}

Nod* arb(int li,int ls)
{
int poz,min,i;
min = pfp[ls];
poz=ls;
for( i=ls-1; i>=li; --i )
    if( pfp[i]<min )
        {
        min=pfp[i];
        poz=i;
        }
Nod *c=new Nod;
c->nr = poz;
if( li==ls ) c->as = c->ad = 0;
else
    {
    c->as = arb(li,poz-1);
    c->ad = arb(poz+1,ls);
    }
return c;
}

void SDV(Nod *s)
{
if( s )
    {
    SDV( s->as );
    SDV( s->ad );
    fp[++t] = s->nr;
    }
}

void solve()
{
int i;
v = arb(1,n);
SDV(v);
t=0;
int rez,p;
for( i=1; i<=n; ++i )
    {
    p = fp[i];
    if( efp[p][0]=='+' || efp[p][0]=='-' || efp[p][0]=='*' || efp[p][0]=='/' )
        {
        switch( efp[p][0] )
            {
            case '+' : rez = st[t-1]+st[t]; break;
            case '-' : rez = st[t-1]-st[t]; break;
            case '*' : rez = st[t-1]*st[t]; break;
            case '/' : rez = st[t-1]/st[t]; break;
            }
        --t;
        st[t] = rez;
        }
    else
        {
        ++t;
        st[t] = atol( efp[p] );
        }
    }
g<< st[t];
}

int main()
{
read();
solve();
f.close(); g.close();
return 0;
}

/*for( i=1; i<=k; ++i )
    if( e[i][0]==')' ) j-=10;
    else if( e[i][0]=='(' ) j+=10;
    else if( e[i][0]=='+' )
        {
        ++n;
        pfp[n] = 1+j;
        efp[n][0]='+';
        }
    else if( e[i][0]=='-' )
        {
        ++n;
        pfp[n] = 1+j;
        efp[n][0] = '-';
        }
    else if( e[i][0]=='*' )
        {
        ++n;
        pfp[n] = 10+j;
        efp[n][0] = '*';
        }
    else if( e[i][0]=='/' )
        {
        ++n;
        pfp[n] = j+10;
        efp[n][0] = '/';
        }
    else
        {
        ++n;
        pfp[n]=INF;
        strcpy( efp[n], e[i] );
        }*/

/*if( sir[i]>='0' && sir[i]<='9' )
        {
        ++k;
        l=0;
        e[k][l] = sir[i];
        j=i+1;
        while( sir[j]>='0' && sir[j]<='9' ) { e[k][ ++l ] = sir[j] ; ++j ; }
        --j;
        i = j;
        }
    else
        {
        ++k;
        e[k][0] = sir[i];
        }*/

/*if( fp[i][0]=='+' || fp[i][0]=='-' || fp[i][0]=='*' || fp[i][0]=='/' )
        {
        int rez=0;
        switch( fp[i][0] )
            {
            case '+' : rez = st[t]+st[t-1]; break;
            case '-' : rez = st[t-1]-st[t]; break;
            case '*' : rez = st[t]*st[t-1]; break;
            case '/' : rez = st[t-1]/st[t]; break;
            }
        --t;
        st[t]=rez;
        }
    else {
        ++t ;
        st[t] = atol( fp[i] );
        }*/

//st[t] = numar( fp[i] );

//for(int i=1; i<=n; i++) printf("%s ",fp[i]);

//for(; t; t-- ) printf("%d ",st[t]);
//printf("%d",st[t]);

//freopen(inf,"r",stdin);
//freopen(outf,"w",stdout);

/*switch( e[i][0] )
        {
        case ')' : j-=10 ; break;
        case '(' : j+=10 ; break;
        case '+' : p[i]=1+j; break;
        case '-' : p[i]=1+j; break;
        case '*' : p[i]=10+j; break;
        case '/' : p[i]=10+j; break;
        default : p[i]=INF;
        }*/
/*for( i=1; i<=k; ++i )
    if( e[i][0]!='(' && e[i][0]!=')' )
        {
        n++;
        strcpy( efp[n], e[i] );
        pfp[n] = p[i];
        }*/

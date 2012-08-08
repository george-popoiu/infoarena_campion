#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<complex>
#include<vector>
#define inf "triang.in"
#define outf "triang.out"
#define EPS 0.001
#define NMax 1510
#define pb push_back
using namespace std;

struct punct { double x,y; };
int N, nr;
punct P[NMax];
struct tr { int v[3]; };
vector<tr> v;

void read()
{
    scanf("%d", &N); double x,y;
    for(int i=1; i<=N; i++)
    {
        scanf("%lf%lf", &x, &y);
        P[i].x = x; P[i].y = y;
    }
}

struct cmp
{
    bool operator () (const punct &a, const punct &b) { return ( floor( a.x*1000 ) / 1000.0 ) < ( floor( b.x*1000 ) / 1000.0 ); }
};

bool cauta(double x, double y, int &p)
{
    int m, poz=0, st=1, dr=N, i;
    while( st<=dr )
    {
        m = (st+dr)>>1;
        if( fabs(P[m].x-x)<=EPS ) { poz = m; break; }
        if( ( floor( P[m].x*1000 ) / 1000.0 ) < ( floor( x*1000 ) / 1000.0 ) ) st = m+1;
        else dr = m-1;
    }
    if( !poz ) return false;
    i = poz;
    while( fabs(P[i].x-x)<=EPS && i<=N ) {
        if( fabs(P[i].y-y)<=EPS ) { p=i; return true; }
        i++;
    }
    i = poz;
    while( fabs(P[i].x-x)<=EPS && i>=1 ) {
        if( fabs(P[i].y-y)<=EPS ) { p=i; return true; }
        i--;
    }
    return false;
}

bool egal_tr(tr A, tr B) { return ( A.v[0]==B.v[0] && A.v[1]==B.v[1] && A.v[2]==B.v[2] ); }

bool e_tr(int a,int b,int c)
{
    tr t; t.v[0]=a; t.v[1]=b; t.v[2]=c; sort(t.v, t.v+3);
    if( !v.size() ) return false;
    for(int i=0; i<v.size(); i++)
        if( egal_tr(t,v[i]) ) return true;
    return false;
}

void solve()
{
    sort(P+1,P+N+1,cmp());
    //for(int i=1; i<=N; i++) printf("%lf %lf\n", P[i].x, P[i].y);
    complex<double> e( 1/2.0, sqrt(3)/2.0 ), aux(-1.0,0.0);
    tr t;
    int poz;
    //printf("%.7lf %.7lf", e.real(), e.imag() );
    for(int i=1; i<N; i++)
        for(int j=i+1; j<=N; j++)
        {
            complex<double> a(P[i].x,P[i].y), b(P[j].x,P[j].y);
            complex<double> c1 = aux*(e*a + e*e*b);
            complex<double> c2 = aux*(e*e*a + e*b);
            //printf("%.7lf %.7lf\n", c1.imag(), c1.real() );
            //printf("%.7lf %.7lf\n", c2.imag(), c2.real() );
            if( cauta(c1.imag(), c1.real(), poz) )
            {
                if( e_tr(i,j,poz) ) continue;
                t.v[0]=i,t.v[1]=j,t.v[2]=poz;
                sort(t.v, t.v+3);
                nr++; v.pb(t);
            }
            if( cauta(c2.imag(), c2.real(), poz) )
            {
                if( e_tr(i,j,poz) ) continue;
                t.v[0]=i,t.v[1]=j,t.v[2]=poz;
                sort(t.v,t.v+3);
                nr++; v.pb(t);
            }
        }
    printf("%d\n",nr);
    //for(int i=0; i<v.size(); i++) printf("%d %d %d\n", v[i].v[0], v[i].v[1], v[i].v[2]);
}

int main()
{
    freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

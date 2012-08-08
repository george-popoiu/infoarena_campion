#include<stdio.h>
#include<algorithm>
#include<math.h>
#define inf "triang.in"
#define outf "triang.out"
#define NMax 2000
#define eps 1000
using namespace std;

struct punct { int x,y; };
punct p[NMax];
int N, nr;

void read()
{
    scanf("%d",&N); double x,y;
    for(int i=1; i<=N; i++)
    {
        scanf("%lf%lf",&x,&y);
        p[i].x = (int)(eps*x); p[i].y = (int)(y*eps);
    }
}

struct cmp
{
    bool operator() (const punct &a, const punct &b)
    {
        if( a.x==b.x ) return (a.y<b.y);
        return (a.x<b.x);
    }
};

class complex
{
    public:
    int real,imag;
    complex operator + (complex aux)
    {
        complex rez;
        rez.real = real + aux.real;
        rez.imag = imag + aux.imag;
        return rez;
    }
    complex operator * (complex aux)
    {
        complex rez;
        rez.real = real*aux.real - imag*aux.imag ;
        rez.imag = real*aux.imag + imag*aux.real;
        return rez;
    }
    complex operator * (int aux)
    {
        complex rez;
        rez.real = aux*real; rez.imag = aux*imag;
        return rez;
    }
};

bool cauta(int real, int imag)
{
    int st=1, dr=N, m, poz = -1;
    printf("%d %d\n", real, imag);
    while( st<=dr )
    {
        m = (st+dr)>>1;
        printf("%d | %d %d\n",m, p[m].x, p[m].y);
        if( p[m].x == real ) { printf("DA\n"); poz = m; st=N+1; }
        else if( p[m].x > real ) dr = m-1;
        else st = m+1;
    }
    printf("%d\n",poz);
    if( poz==-1 ) return false;
    printf("%lf %dlf\n", p[poz].y, imag);
    if( p[poz].y == imag ) return true;

    for(int i=poz-1; i>=1 && p[i].x==real; i--)
        if( p[i].y == imag ) return true;
    for(int i=poz+1; i<=N && p[i].x == real; i++)
        if( p[i].y == imag ) return true;
    return false;
}

void solve()
{
    sort( p+1, p+N+1, cmp() );
    //for(int i=1; i<=N;i++) printf("%lf %lf\n", p[i].x, p[i].y);
    complex e; e.real = (int)(0.5*eps); e.imag = (int)( ( (double)(sqrt(3)) / (double)(2) )* eps );
    complex e2 = e*e;
    complex a, b, c1, c2;
    for(int i=1; i<N; i++)
        for(int j=i+1; j<=N; j++)
        {
            a.real = p[i].x; a.imag = p[i].y;
            b.real = p[j].x; b.imag = p[j].y;
            c1 = e*a + e2*b; c1 = c1 * (-1);
            c2 = e2*a + e*b; c2  = c2 * (-1);
            swap(c1.real,c1.imag); swap(c2.real,c2.imag);
            if( cauta(c1.real, c1.imag) ) nr++;
            if( cauta(c2.real, c2.imag) ) nr++;
        }
    printf("%d",nr);
    /*printf("\n%lf", p[3].x );
    double y = 2.0000001;
    printf("\n%lf", y );
    if( (int)(y*1000) == (int)(p[3].x*1000) ) printf("DA");*/
}

int main()
{
    freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

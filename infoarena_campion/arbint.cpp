#include<stdio.h>
#define inf "arbint.in"
#define outf "arbint.out"
#define NMax 100001
#define buffSize 32762
using namespace std;

int MaxArb[4*NMax+66];
int N, M;
int start, end, value, pos, maxim;
int op, A, B;
int ind, ok = 1; char buffer[buffSize];

inline int Max(int a, int b) {
    if( a>b ) return a;
    return b;
    }

void read(int &x)
{
    if(ok)
    {
        fread( buffer, 1, buffSize, stdin );
        ok = 0; ind = 0;
    }
    x = 0;
    while( buffer[ind]>='0' && buffer[ind]<='9' )
    {
        x = x*10 + (buffer[ind]-'0');
        ind++;
        if( ind==buffSize )
        {
            fread( buffer, 1, buffSize, stdin );
            ind = 0;
        }
    }
    while( buffer[ind]<'0' || buffer[ind]>'9' )
    {
        ind++;
        if( ind==buffSize )
        {
            fread( buffer, 1, buffSize, stdin );
            ind = 0;
        }
    }
}

void Update(int, int, int);
void Query(int, int, int);

int main()
{
    freopen(inf,"r", stdin); freopen(outf,"w",stdout);
	read(N); read(M);
    for(int i=1; i<=N; i++)
    {
        read(value);
        pos = i;
        Update(1,1,N);
    }

    for(int i=1; i<=M; i++)
    {
        read(op); read(A); read(B);
        if( op==0 )
        {
            maxim = -1;
            start = A; end = B;
            Query(1,1,N);
            printf("%d\n", maxim);
        }
        else
        {
            pos = A; value = B;
            Update(1,1,N);
        }
    }
	return 0;
}

void Update(int nod, int left, int right)
{
    if( left==right )
    {
        MaxArb[nod] = value;
        return;
    }

    int m = (left+right)/2;
    if( pos<=m ) Update(2*nod, left, m);
    else Update(2*nod+1, m+1, right);

    MaxArb[nod] = Max( MaxArb[2*nod], MaxArb[2*nod+1] );
}

void Query(int nod, int left, int right)
{
    if( right<=end && left>=start )
    {
        maxim = Max( maxim, MaxArb[nod] );
        return;
    }

    int m = (left+right)/2;
    if( start<=m ) Query(2*nod, left, m);
    if( end > m ) Query(2*nod+1, m+1, right);
}

#include<stdio.h>
#define inf "datorii.in"
#define outf "datorii.out"
#define DIM 40000
#define buffSize 32762
using namespace std;

int ArbSum[DIM];
int N, M;
int pos, val;
int st, dr;
int sum;
int ok = 1, ind; char buffer[buffSize];

void Update(int nod, int left, int right)
{
    if( left==right )
    {
        ArbSum[nod] -= val;
        return;
    }
    int m = (left+right)/2;
    if( pos<=m ) Update(2*nod, left, m);
    else Update(2*nod+1, m+1, right);

    ArbSum[nod] = ArbSum[2*nod] + ArbSum[2*nod+1];
}

void Query(int nod, int left, int right)
{
    if( left>=st && right<=dr )
    {
        sum += ArbSum[nod];
        return;
    }
    int m = (left+right)/2;
    if( st <= m ) Query(2*nod, left, m);
    if( m < dr ) Query(2*nod+1, m+1, right);
}

void read(int &x)
{
    if(ok)
    {
        fread(buffer, 1, buffSize, stdin);
        ind = 0;
        ok = 0;
    }

    x = 0;
    while( buffer[ind]>='0' && buffer[ind]<='9' )
    {
        x = x*10 + (buffer[ind]-'0');
        ind++;
        if( ind==buffSize )
        {
            fread(buffer, 1, buffSize, stdin);
            ind = 0;
        }
    }

    while( buffer[ind]<'0' || buffer[ind]>'9' )
    {
        ind++;
        if( ind==buffSize )
        {
            fread(buffer, 1, buffSize, stdin);
            ind = 0;
        }
    }
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(N); read(M);
    for(int i=1; i<=N; i++)
    {
        read(val);
        val = -val; pos = i;
        Update(1,1,N);
    }
    int op, A, B;
    for(int i=1; i<=M; i++)
    {
        read(op); read(A); read(B);
        if( op==0 )
        {
            pos = A; val = B;
            Update(1,1,N);
        }
        else
        {
            st = A; dr = B;
            sum = 0;
            Query(1,1,N);
            printf("%d\n", sum);
        }
    }
	return 0;
}

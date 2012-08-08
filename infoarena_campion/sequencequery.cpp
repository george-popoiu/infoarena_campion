#include<fstream>
#define inf "sequencequery.in"
#define outf "sequencequery.out"
#define NMax 100010
#define Dim 262144
#define INF 0x3f3f3f3f
using namespace std;

fstream f(inf,ios::in), g(outf,ios::out);

int N, M, V[NMax]; int start, end;
long long A[Dim], B[Dim], C[Dim], D[Dim];
long long s, sol;

inline long long max(long long x, long long y) { return ( x>y ? x : y ); }

void build(int n, int left, int right)
{
    if( left==right ) {
        A[n] = B[n] = C[n] = D[n] = V[left];
        return;
    }

    int m = (left+right)/2;
    build(2*n, left, m);
    build(2*n+1, m+1, right);

    A[n] = max( A[2*n], D[2*n]+A[2*n+1] );
    B[n] = max( B[2*n+1], D[2*n+1]+B[2*n] );
    C[n] = max( max(C[2*n],C[2*n+1]), B[2*n]+A[2*n+1]);
    D[n] = D[2*n]+D[2*n+1];
}

void query(int n, int left, int right) //start, end
{
    if( left>=start && right<=end ) {
        if( s<0 ) s = 0;
        sol = max(sol, max(s+A[n], C[n]));
        s = max(s+D[n], B[n]);
        return;
    }

    int m = (left+right)/2;
    if( start<=m ) query(2*n, left, m);
    if( m<end ) query(2*n+1, m+1, right);
}

int main()
{
    f>>N>>M;
    for(int i=1; i<=N; i++) f>>V[i];
    build(1,1,N);

    for(int i=1; i<=M; i++)
    {
        f>>start>>end;
        s = 0; sol = -INF;
        query(1,1,N);
        g<<sol<<"\n";
    }

	f.close(); g.close();
	return 0;
}

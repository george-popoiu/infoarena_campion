#include<fstream>
#define inf "maxq.in"
#define outf "maxq.out"
#define NMax 200010
#define ArbDim 524288
using namespace std;

fstream f(inf,ios::in), g(outf,ios::out);

int N, M, V[NMax];
long long A[ArbDim], B[ArbDim], C[ArbDim], D[ArbDim];
/*
* A[nod] = subsecv de suma maxima situata la stanga int curent
* B[nod] = subsecv de suma maxima situata la dreapta int curent
* C[nod] = subsecv de suma maxima situata oriunde in int curent
* D[nod] = suma tuturor elementelor din intervalul curent
*/
int pos, val;
int start, end;
long long sum, sol;

inline long long max(long long x, long long y) { return ( x>y ? x : y ); }

void build(int n, int left, int right)
{
    if( left==right ) {
        A[n] = B[n] = C[n] = max(0, V[left]);
        D[n] = V[left];
        return;
    }

    int m = (left+right)/2;
    build(2*n, left, m);
    build(2*n+1, m+1, right);

    A[n] = max( A[2*n], D[2*n] + A[2*n+1] );
    B[n] = max( B[2*n+1], D[2*n+1] + B[2*n] );
    C[n] = max( max(C[2*n], C[2*n+1]), B[2*n] + A[2*n+1] );
    D[n] = D[2*n] + D[2*n+1];
}

void update(int n, int left, int right) //pos, val
{
    if( left==right ) {
        V[left] = val;
        A[n] = B[n] = C[n] = max(0, V[left]);
        D[n] = V[left];
        return;
    }

    int m = (left+right)/2;
    if( pos<=m ) update(2*n, left, m);
    else update(2*n+1, m+1, right);

    A[n] = max( A[2*n], D[2*n] + A[2*n+1] );
    B[n] = max( B[2*n+1], D[2*n+1] + B[2*n] );
    C[n] = max( max(C[2*n], C[2*n+1]), B[2*n] + A[2*n+1] );
    D[n] = D[2*n] + D[2*n+1];
}

void query(int n, int left, int right) //start, end
{
    if( left>=start && right<=end ) {
        if( sum < 0 ) sum = 0;
        sol = max( sol, max(sum+A[n], C[n]) );
        sum = max( sum+D[n],B[n] );
        return;
    }

    int m = (left+right)/2;
    if( start<=m ) query(2*n, left, m);
    if( end>m ) query(2*n+1, m+1, right);
}

int main()
{
	//freopen(inf,"r",stdin); freopen(outf,"w",stdout);

    //scanf("%d",&N);
    f>>N;
    for(int i=1; i<=N; i++) //scanf("%d", &V[i]);
        f>>V[i];


    build(1,1,N);

    //scanf("%d", &M);
    f>>M;
    int op, a, b;
    for(int i=1; i<=M; i++)
    {
        //scanf("%d%d%d", &op, &a, &b);
        f>>op>>a>>b;
        if( !op ) {
            pos = a+1; val = b;
            update(1,1,N);
        }
        else {
            start = a+1; end = b+1;
            sum = sol = 0;
            query(1,1,N);
            //printf("%d\n", sol);
            g<<sol<<"\n";
        }
    }
    f.close(); g.close();
	return 0;
}

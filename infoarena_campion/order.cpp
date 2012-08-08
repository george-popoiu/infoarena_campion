#include<fstream>
#define inf "order.in"
#define outf "order.out"
#define NMax 30010
#define Dim 65536
using namespace std;

fstream f(inf, ios::in), g(outf, ios::out);

int N, A[Dim];
int pos, val, m, answer;

void update(int n, int left, int right)
{
    if( left==right ) {
        A[n] += val;
        return;
    }

    m = (left+right)>>1;
    if( pos<=m ) update(n<<1, left, m);
    else update((n<<1)+1, m+1, right);

    A[n] = A[n<<1] + A[(n<<1)+1];
}

void query(int n, int left, int right, int p)
{
    if( left==right ) {
        answer = left;
        return;
    }

    m = (left+right)>>1;
    if( p<=A[n<<1] ) query(n<<1, left, m, p);
    else query((n<<1)+1, m+1, right, p-A[n<<1]);
}

int main()
{
    f>>N;
    for(int i=1; i<=N; i++)
    {
        pos = i; val = 1;
        update(1,1,N);
    }

    int j = 1;
    for(int i=0; i<N; i++)
    {
        j = (j+i)%(N-i);
        query(1, 1, N, j+1);
        g<<answer<<" ";

        pos = answer; val = -1;
        update(1, 1, N);
    }

	f.close(); g.close();
	return 0;
}

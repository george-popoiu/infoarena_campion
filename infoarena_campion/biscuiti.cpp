#include<fstream>
#define inf "biscuiti.in"
#define outf "biscuiti.out"
#define NMax 100010
#define ll long long
using namespace std;

fstream f(inf, ios::in), g(outf, ios::out);

const ll INF = 1LL<<60;

int N, V[NMax]; ll sol;
struct elem {
    ll min, val;
    int pos;
} A[NMax<<2];

void buildTree(int n, int left, int right) {
    if( left==right ) {
        A[n].pos = left;
        A[n].min = V[left];
        return;
    }

    int m = (left+right)>>1;
    buildTree(n<<1, left, m);
    buildTree(n<<1 | 1, m+1, right);

    if( A[n<<1].min <= A[n<<1 | 1].min ) {
        A[n].min = A[n<<1].min;
        A[n].pos = A[n<<1].pos;
    }
    else {
        A[n].min = A[n<<1 | 1].min;
        A[n].pos = A[n<<1 | 1].pos;
    }
}

void update(int n, int left, int right, int pos, int val) {
    if( left==right ) {
        A[n].min = INF;
        return;
    }

    int m = (left+right)>>1;
    if( pos<=m ) update(n<<1, left, m, pos, val);
    else {
        A[n<<1].val += val;
        update(n<<1 | 1, m+1, right, pos, val);
    }

    if( A[n<<1].min + A[n<<1].val <= A[n<<1 | 1].min + A[n<<1 | 1].val ) {
        A[n].min = A[n<<1].min + A[n<<1].val;
        A[n].pos = A[n<<1].pos;
    }
    else {
        A[n].min = A[n<<1 | 1].min + A[n<<1 | 1].val;
        A[n].pos = A[n<<1 | 1].pos;
    }
}

int main()
{
    f>>N;
    for(int i=1; i<=N; i++) f>>V[i];
    buildTree(1, 1, N);

    for(int i=1; i<=N; i++) {
        sol += ( A[1].min - V[ A[1].pos ] );
        update(1, 1, N, A[1].pos, i);
    }
    g<<sol;

	f.close(); g.close();
	return 0;
}

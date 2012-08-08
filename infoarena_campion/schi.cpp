#include<fstream>
#define inf "schi.in"
#define outf "schi.out"
#define NMax 30010
#define Dim 65536
using namespace std;

fstream f(inf, ios::in), g(outf, ios::out);

int N, v[NMax], sol[NMax];
int A[4*NMax], pos, val, ans;

void build(int n, int left, int right) {
    if( left==right ) {
        A[n] += val;
        return;
    }

    int m = (left+right)/2;
    if(m>=left)build(2*n, left, m);
    if(m<right)build(2*n+1, m+1, right);

    A[n] = A[2*n] + A[2*n+1];
}

int m;

void query(int n, int left, int right, int p) { // => pos
    if( left==right ) {
        ans = left;
        return;
    }

    m = (left+right)/2;
    if( p<=A[2*n] ) query(2*n, left, m, p);
    else query(2*n+1, m+1, right, p-A[2*n]);
}

void update(int n, int left, int right) {//pos, val
    if( left==right ) {
        A[n] += val;
        return;
    }

    m = (left+right)/2;
    if( pos<=m ) update(2*n, left, m);
    else update(2*n+1, m+1, right);

    A[n] = A[2*n] + A[2*n+1];
}

int main()
{
    f>>N;
    for(int i=1; i<=N; i++) { f>>v[i];} //pos = i; val = 1; update(1,1,N); }
    val = 1; build(1, 1, N);
    //g<<A[1]<<" "<<A[2]<<" "<<A[3]<<endl;
    g<<A[1]<<endl;

    for(int i=N; i>=1; i--) {
        query(1, 1, N, v[i]);
        pos = ans;
        sol[pos] = i; val = -1;
        update(1, 1, N);
    }

    for(int i=1; i<=N; i++) {
        g<< sol[i] <<"\n";
    }

	f.close(); g.close();
	return 0;
}

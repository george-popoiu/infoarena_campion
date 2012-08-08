//#include<fstream>
#include<stdio.h>
#define inf "eliminare.in"
#define outf "eliminare.out"
#define NMax 1000001
#define Dim 2100000
#define INF 0x3f3f3f3f
#define buffSize 32762
using namespace std;

//fstream f(inf, ios::in), g(outf, ios::out);

int N, M, v[NMax];
struct elem { int m, p; } A[Dim];
int B[Dim], val, pos;
int start, end, maxim;

char buffer[buffSize]; int ok = 1, ind;

inline int max(int a, int b) { return ( a<b ? a : b ); }

void buildB(int n, int left, int right) {
    if( left==right ) {
        B[n] = 1;
        return;
    }

    int m = (left+right)>>1;
    buildB(n<<1, left, m);
    buildB(n<<1 | 1, m+1, right);

    B[n] = B[n<<1] + B[n<<1 | 1];
}

void queryB(int n, int left, int right, int p) {
    if( left==right ) {
        pos = left;
        return;
    }

    int m = (left+right)>>1;
    if( p<=B[n<<1] ) queryB(n<<1, left, m, p);
    else queryB(n<<1 | 1, m+1, right, p-B[n<<1]);
}

void updateB(int n, int left, int right) {
    if( left==right ) {
        B[n] += val;
        return;
    }

    int m = (left+right)>>1;
    if( pos<=m ) updateB(n<<1, left, m);
    else updateB(n<<1 | 1, m+1, right);

    B[n] = B[n<<1] + B[n<<1 | 1];
}

void updateA(int n, int left, int right) {
    if( left==right ) {
        A[n].m = val;
        A[n].p = pos;
        return;
    }

    int m = (left+right)>>1;
    if( pos<=m ) updateA(n<<1, left, m);
    else updateA(n<<1 | 1, m+1, right);

    if( A[n<<1].m > A[n<<1 | 1].m ) {
        A[n].m = A[n<<1].m; A[n].p = A[n<<1].p;
    }
    else {
        A[n].m = A[n<<1 | 1].m; A[n].p = A[n<<1 | 1].p;
    }
}

void queryA(int n, int left, int right) {
    if( left>=start && right<=end ) {
        if( A[n].m > maxim ) {
            maxim = A[n].m;
            pos = A[n].p;
        }
        return;
    }

    int m = (left+right)>>1;
    if( m>=start ) queryA(n<<1, left, m);
    if( end>m ) queryA(n<<1 | 1, m+1, right);

}

void read(int&);

int main()
{
    freopen(inf, "r", stdin); freopen(outf, "w", stdout);
    //f>>N>>M;
    read(N); read(M);
    for(int i=1; i<=N; i++) {
        //f>>v[i];
        read(v[i]);
        val = v[i]; pos = i;
        updateA(1, 1, N);
    }
    buildB(1, 1, N);

    int a, b;
    for(int i=1; i<=M; i++) {
        //f>>a>>b;
        read(a); read(b);
        queryB(1, 1, N, a); start = pos;
        queryB(1, 1, N, b); end = pos;
        maxim = -INF; queryA(1, 1, N);
        v[pos] = 0;
        val = -1; updateB(1, 1, N);
        val = -INF; updateA(1, 1, N);
    }

    for(int i=1; i<=N; i++)
        if( v[i] ) //g<<v[i]<<"\n";
            printf("%d\n", v[i]);

	//f.close(); g.close();
	return 0;
}

void read(int &x) {
    if( ok ) {
        fread(buffer, 1, buffSize, stdin);
        ok = ind = 0;
    }

    x = 0;
    while( buffer[ind]>='0' && buffer[ind]<='9' ) {
        x = x*10 + (buffer[ind]-'0');
        ind++;
        if( ind==buffSize ) {
            fread(buffer, 1, buffSize, stdin);
            ind = 0;
        }
    }

    while( buffer[ind]<'0' || buffer[ind]>'9' ) {
        ind++;
        if( ind==buffSize ) {
            fread(buffer, 1, buffSize, stdin);
            ind = 0;
        }
    }
}

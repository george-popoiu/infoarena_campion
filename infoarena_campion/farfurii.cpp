#include<fstream>
#define inf "farfurii.in"
#define outf "farfurii.out"
#define NMax 100010
#define Dim 262144
#define LL long long
using namespace std;

fstream f(inf, ios::in), g(outf, ios::out);

int A[Dim], N; //A[n] - cate elemente mai avem in intervalul corespunzator nodului "n"
LL K;
int pos, val, m;
int answer;
int sol[NMax];

void update(int n, int left, int right) //pos, val - adds or removes the pos element
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

void query(int n, int left, int right, int p) //get p'th element
{
    if( left==right ) {
        answer = left;
        return;
    }

    m = (left+right)>>1;
    if( p<=A[n<<1] ) query(n<<1, left, m, p);
    else query((n<<1)+1, m+1, right, p-A[n<<1]);
}

inline LL max(LL x, LL y) { return ( x>y ? x : y ); }

int main()
{
    int i;
    f>>N>>K;
    for(i=1; i<=N; i++)
    {
        pos = i; val = 1;
        update(1,1,N);
    }

    LL contor_inversiuni = 0, t, inversiuni_ramase, inversiuni_de_alcatuit;
    int p;
    for(i=1; i<=N; i++)
    {
        t = N-i;
        inversiuni_ramase = (t-1)*t/2;
        //daca se pot face inca cel putin K inversiuni pun cel mai mic elem
        inversiuni_de_alcatuit = max(0, K - inversiuni_ramase - contor_inversiuni);
        contor_inversiuni += inversiuni_de_alcatuit;

        p = inversiuni_de_alcatuit + 1;
        query(1,1,N,p);
        sol[i] = answer;
        pos = answer; val = -1;
        update(1,1,N);
    }

    for(i=1; i<=N; i++) g<<sol[i]<<" ";

	f.close(); g.close();
	return 0;
}

#include<stdio.h>
#define inf "concurs1.in"
#define outf "concurs1.out"
#define NMax 50010
#define Dim 131072
using namespace std;

int I[NMax], N, A[Dim];
int pos, val, answer;
int sol[NMax];

void update(int n, int left, int right) //pos, val : adds or removes the pos element
{
    if( left==right ) {
        A[n] += val;
        return;
    }

    int m = (left+right)/2;
    if( pos<=m ) update(2*n, left, m);
    else update(2*n+1, m+1, right);

    A[n] = A[2*n] + A[2*n+1];
}

void query(int n, int left, int right, int p) //gets the p'th element from the current interval
{
    if( left==right ) {
        answer = left;
        return;
    }

    int m = (left+right)/2;
    if( p<=A[2*n] ) query(2*n, left, m, p);
    else query(2*n+1, m+1, right, p-A[2*n]);
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);

	scanf("%d", &N);
	for(int i=1; i<=N; i++)
	{
        scanf("%d", &I[i]);
        if( I[i] > N-i ) {
            printf("NU ARE SOLUTIE");
            return 0;
        }
        pos = i; val = 1;
        update(1,1,N);
	}

    for(int i=1; i<=N; i++)
    {
        query(1, 1, N, I[i]+1);
        sol[i] = answer;

        pos = answer; val = -1;
        update(1, 1, N);
    }

    for(int i=1; i<=N; i++) printf("%d ", sol[i]);

	return 0;
}

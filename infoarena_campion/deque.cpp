#include<fstream>
#define MaxN 5000010
using namespace std;

fstream f("deque.in",ios::in),g("deque.out",ios::out);

int A[MaxN],Deque[MaxN],N,K,Back,Front;
long long Sum;

int main()
{
int i;
f>>N>>K;
for(i=1;i<=N;i++)f>>A[i];
f.close();
Back=0;
Front=1;
for(i=1;i<=N;i++)
    {
    while(Front<=Back && A[i]<=A[Deque[Back]])Back--;
    Deque[++Back]=i;
    if(Deque[Front]==i-K)Front++;
    if(i>=K)Sum+=A[Deque[Front]];
    }
g<<Sum;
g.close();
return 0;
}

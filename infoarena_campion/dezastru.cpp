#include<fstream>
#include<iostream>
#define inf "dezastru.in"
#define outf "dezastru.out"
#define MaxN 26
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int st[MaxN],N,P,k;
float prob[MaxN],sum;

void Citire()
{
f>>N>>P;
for(int i=1;i<=N;i++)f>>prob[i];
}

int main()
{
Citire();
f.close();
g.close();
return 0;
}

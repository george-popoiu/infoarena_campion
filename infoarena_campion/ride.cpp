/*
ID : georgep2
PROG : ride
LANG : C++
*/
#include<fstream>
#include<string.h>
#define inf "ride.in"
#define outf "ride.out"
#define MOD 47
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

char *s1=new char[10];
char *s2=new char[10];

void Read()
{
f.get(s1,10); f.get();
f.get(s2,10);
}

void Solve()
{
char c='A';
long long int nr1=1,nr2=1;
for(int i=0;i<strlen(s1);i++) { nr1*= ( ( (int)(s1[i]) - ( (int)(c)-1 ) ) % MOD ) ; nr1 %= MOD ; }
for(int i=0;i<strlen(s2);i++) { nr2*= ( ( (int)(s2[i]) - ( (int)(c)-1 ) ) % MOD ) ; nr2 %= MOD ; }
if( nr1 == nr2 ) g<<"GO\n";
else g<<"STAY\n";
}

int main()
{
Read();
Solve();
f.close();
g.close();
return 0;
}

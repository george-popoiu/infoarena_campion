#include<fstream>
#define inf "jap2.in"
#define outf "jap2.out"
#define PMax 100010
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int P,Q,A,B;
int fp[PMax];

void c_fp()
{
   fp[0]=1;
   for(int i=1; i<P; i++) fp[i] = ( fp[i-1]*i ) % P ;
}

void read()
{
   f>>P>>Q;
   c_fp();
}

int main()
{
   read();
   f.close(); g.close();
   return 0;
}

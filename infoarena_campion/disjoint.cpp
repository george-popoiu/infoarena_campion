#include<fstream>
#define inf "disjoint.in"
#define outf "disjoint.out"
#define Max 100100
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int N,M;
int T[Max],H[Max];

int Root(int nod)
{
   while( T[nod] ) nod=T[nod];
   return nod;
}

void Add(int x,int y)
{
   int v1,v2;
   v1 = Root(x);
   v2 = Root(y);
   if( H[v1]==H[v2] ) T[v2]=v1 , H[v1]++;
   else
   {
      if( H[v1]<H[v2] ) T[v1]=v2;
      else T[v2]=v1;
   }
}

void read()
{
   f>>N>>M;
   int code,x,y;
   for(int i=1; i<=M; i++)
   {
      f>>code>>x>>y;
      if( code==1 ) Add(x,y);
      else
      {
         if( Root(x)==Root(y) ) g<<"DA\n";
         else g<<"NU\n";
      }
   }
}

int main()
{
   read();
   f.close(); g.close();
   return 0;
}

#include<fstream>
#define inf "motel.in"
#define outf "motel.out"
#define NMax 4010
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

struct interval
{
int st;
int dr;
int ord;
};

struct zi
{
int nr;
int ord;
};

typedef interval Heap[NMax];
Heap H;
zi zile[NMax];
interval grup[NMax];
int N,nrnod;

void Citire()
{
f>>N;
for(int i=1;i<=N;i++)
    {
    f>>grup[i].st>>grup[i].dr;
    grup[i].ord=i;
    }
for(int i=1;i<=N;i++)
    {
    f>>zile[i].nr;
    zile[i].ord=i;
    }
}

bool rule_interval(interval a,interval b)
{
if(a.st<b.st)return true;
return false;
}

bool rule_zile(zi a,zi b)
{
if(a.nr<b.nr)return true;
return false;
}

int lson(int nod){return 2*nod;}
int rson(int nod){return 2*nod+1;}
int father(int nod){return nod/2;}

void add(Heap H,int& nrnod,interval a)
{
nrnod++;
H[nrnod]=a;
}

void Rezolvare()
{
sort(grup+1,grup+N+1,rule_interval);
sort(zile+1,zile+N+1,rule_zile);
}

int main()
{
Citire();
Rezolvare();
/*for(int i=1;i<=N;i++)
    {
    g<<grup[i].st<<" "<<grup[i].dr<<" "<<grup[i].ord<<"\n";
    }
for(int i=1;i<=N;i++)
    {
    g<<zile[i].nr<<" "<<zile[i].ord<<"\n";
    }*/
f.close();
g.close();
return 0;
}

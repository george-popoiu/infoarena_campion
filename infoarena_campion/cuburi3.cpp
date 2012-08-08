#include<fstream>
#define inf "cuburi3.in"
#define outf "cuburi3.out"
#define NMax 4002
#define INF 0x3f3f3f3f
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int N;
int best[NMax];
int lung[NMax];
int pred[NMax];

struct cutie
{
int l;
int g;
int indice;
};

cutie v[NMax];

void Citire()
{
f>>N;
for(int i=1;i<=N;i++)
    {
    f>>v[i].l>>v[i].g;
    v[i].indice=i;
    }
}

bool rule(cutie a,cutie b)
{
if(a.l>b.l)return true;
else if(a.l==b.l)
    {
    if(a.g>b.g)return true;
    return false;
    }
return false;
}

void Rezolva()
{
int p;
sort(v+1,v+N+1,rule);
//for(int i=1;i<=N;i++)g<<v[i].l<<" "<<v[i].g<<"\n";
for(int i=1;i<=N;i++)
    {
    best[i]=v[i].l;
    lung[i]=1;
    pred[i]=-1;
    for(int j=1;j<=i-1;j++)
        {
        if(v[j].g>=v[i].g && best[i]<best[j]+v[i].l)
            {
            best[i]=best[j]+v[i].l;
            lung[i]=lung[j]+1;
            pred[i]=j;
            }
        }
    }
}

void Afis(int i)
{
if(pred[i]!=-1)Afis(pred[i]);
g<<v[i].indice<<"\n";
}

void Afisare()
{
int max=-INF;
int poz;
for(int i=1;i<=N;i++)
    {
    if(max<best[i])
        {
        max=best[i];
        poz=i;
        }
    else if(max==best[i])
        {
        if(lung[i]>lung[poz])poz=i;
        }
    }
g<<lung[poz]<<" "<<best[poz]<<"\n";
Afis(pred[poz]);
g<<v[poz].indice;
}

int main()
{
Citire();
Rezolva();
Afisare();
f.close();
g.close();
return 0;
}

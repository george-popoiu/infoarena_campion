#include<fstream>
#define inf "ciclueuler.in"
#define outf "ciclueuler.out"
#define NMax 100010
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

struct nod
{
int info;
nod *next;
};

int N,M;
nod *a[NMax];//lista de adiacenta
nod *st,*sf;//inceputul si sfarsitul listei in care tin ciclul eulerian
int viz[NMax];
nod *p,*z,*w;

void add(int x,int y)//adaug in lista de adiac. a nodului x,pe nodul y
{
nod *t=new nod;
t->info=y;
t->next=a[x];
a[x]=t;
}

void Citire()
{
int x,y;
f>>N>>M;
for(int i=1;i<=M;i++)
    {
    f>>x>>y;
    if(x!=y){add(x,y);add(y,x);}
    else add(x,y);//self-loop
    }
}

bool aregradpar()//determin daca toate nodurile din graf au grad par
{
nod *t;
int k;
for(int i=1;i<=N;i++)
    {
    k=0;
    t=a[i];
    while(t)
        {
        if(t->info==i)k+=2;//daca e self-loop, gradul nodului se incrementeaza cu 2
        else k++;
        t=t->next;
        }
    if(k%2!=0)return false;
    }
return true;
}

void dfs(int s)//parcurgere in adancime de la nodul s
{
nod *t=a[s];
viz[s]=1;
while(t)
    {
    if(!viz[t->info])dfs(t->info);
    t=t->next;
    }
}

bool econex()//det. daca graful este conex
{
dfs(1);
for(int i=1;i<=N;i++)
    if(!viz[i])return false;
return true;
}

void sterg(int x,int y)//sterg nodul y din lista de adiacenta a nodului x
{
nod *t=a[x];
if(t)
    {
    if(t->info==y){a[x]=a[x]->next;return;}
    else
        while(t)
            {
            if(t->next && t->next->info==y)
                {
                if(t->next->next)t->next=t->next->next;
                else t->next=0;
                return;
                }
            t=t->next;
            }
    }
}

void ciclu(int x)
{
p=a[x];
a[x]=a[x]->next;
sterg(p->info,x);

w=new nod;
w->info=p->info;

if(z->next)w->next=z->next;
else w->next=0;

z->next=w;
z=w;
if(a[p->info])ciclu(p->info);
}

int main()
{
Citire();
if(aregradpar())
    {
    //g<<"Are grad par.\n";
    if(econex())
        {
        //g<<"Este conex.\n";
        st=new nod;
        st->info=1;
        st->next=0;
        sf=st;
        while(sf)
            {
            z=sf;
            if(a[sf->info])ciclu(sf->info);
            sf=sf->next;
            }
        nod *t=st;
        while(t->next)
            {
            g<<t->info<<" ";
            t=t->next;
            }
        }
    else g<<"-1";
    }
else g<<"-1";
//f.close();
//g.close();
return 0;
}

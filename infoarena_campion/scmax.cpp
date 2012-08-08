#include<fstream>
#define inf "scmax.in"
#define outf "scmax.out"
#define NMax 100001
#define PINF 0x3f3f3f3f
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int N,nr;
int v[NMax],S[NMax],L[NMax];

void Citire()
{
f>>N;
for(int i=1;i<=N;i++)f>>v[i];
}

int cauta(int st,int dr,int num)
{
int mij,poz=PINF;
int gasit=0;
while(st<=dr)
    {
    mij=(st+dr)/2;
    if(S[mij]>=num)
        {
        if(poz>mij)poz=mij;
        dr=mij-1;
        gasit=1;
        }
    else if(S[mij]<num)st=mij+1;
    }
if(gasit==1)return poz;
return -1;
}

void Rezolva()
{
int p;
nr=1;
S[nr]=v[1];
L[1]=1;
for(int i=2;i<=N;i++)
    {
    p=cauta(1,nr,v[i]);
    if(p==-1)
        {
        S[++nr]=v[i];
        L[i]=nr;
        }
    else
        {
        S[p]=v[i];
        L[i]=p;
        }
    }
g<<nr<<"\n";
}

void Afisare()
{
int st[NMax]={};
int max=0;
int k=0;
int poz=0;
for(int i=1;i<=N;i++)
    if(L[i]>=max && i>poz){poz=i;max=L[i];}
k++;
st[k]=poz;
for(int i=poz-1;i>=1;i--)
    {
    if(L[i]==L[st[k]]-1)
        {
        k++;
        st[k]=i;
        }
    }
for(int i=k;i>=1;i--)g<<v[st[i]]<<" ";
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

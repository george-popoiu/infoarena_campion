#include<fstream>
#define inf "restante.in"
#define outf "restante.out"
#define NMax 36010
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int N,nr;
char sir[NMax][20];

void Citire()
{
f>>N;
f.get();
for(int i=1;i<=N;i++)
    {
    f.get(sir[i],20);
    f.get();
    }
}

bool rule_char(char a,char b)
{
if((int)a<=(int)b)return true;
return false;
}

void merge(int st,int dr,int m)
{
int i,j,k;
char aux[NMax][20];
k=0;
i=st;
j=m+1;
while(i<=m && j<=dr)
    {
    if(strcmp(sir[i],sir[j])<=0){strcpy(aux[++k],sir[i]);i++;}
    else {strcpy(aux[++k],sir[j]);j++;}
    }
if(i<=m)
    {
    for(j=i;j<=m;j++)strcpy(aux[++k],sir[j]);
    }
else if(j<=dr)
    {
    for(i=j;i<=dr;i++)strcpy(aux[++k],sir[i]);
    }
j=st;
for(i=1;i<=k;i++)
    {
    strcpy(sir[j++],aux[i]);
    }
}

void sorteaza(int st,int dr)
{
char aux[20];
if(strcmp(sir[st],sir[dr])>0)
    {
    strcpy(aux,sir[st]);
    strcpy(sir[st],sir[dr]);
    strcpy(sir[dr],aux);
    }
}

void mergesort(int st,int dr)
{
int m;
if(dr-st>=1)sorteaza(st,dr);
else
    {
    m=(st+dr)/2;
    mergesort(st,m);
    mergesort(m+1,dr);
    merge(st,dr,m);
    }
}

void Rezolva()
{
for(int i=1;i<=N;i++)sort(sir[i],sir[i]+strlen(sir[i]),rule_char);
mergesort(1,N);
if(strcmp(sir[1],sir[2])!=0)nr++;
for(int i=2;i<N;i++)
    {
    if( strcmp(sir[i],sir[i-1])!=0 && strcmp(sir[i],sir[i+1])!=0 )nr++;
    }
if(strcmp(sir[N],sir[N-1])!=0)nr++;
g<<nr;
//for(int i=1;i<=N;i++)g<<sir[i]<<"\n";
}

int main()
{
Citire();
Rezolva();
//for(int i=1;i<=N;i++)g<<sir[i]<<"\n";
f.close();
g.close();
return 0;
}

#include<fstream>
#include<string.h>
#define inf "dir.in"
#define outf "dir.out"
#define MaxS 1700
#define MaxF 101
#define MaxC 300
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

typedef char *TStiva[MaxC];
char sir[MaxS];
char *Rez[MaxF];
TStiva ST;
int VF;
int nrsol;
int N;

void Citire()
{
f.get(sir,MaxS);
}

void Add(char *s)
{
if(VF<MaxF)
    {
    VF++;
    ST[VF]=strdup(s);
    }
}

void Rezolva()
{
N=strlen(sir);
char dirc[MaxC];//directorul radacina
int i=0;
dirc[i]='\0';
while(sir[i]!='('){dirc[i]=sir[i];i++;}//pun directorul radacina in stiva
dirc[i]='\0';
Add(dirc);
while(VF) //cat timp stiva nu este vida
    {
    }
}

int main()
{
Citire();
Rezolva();
f.close();
g.close();
return 0;
}

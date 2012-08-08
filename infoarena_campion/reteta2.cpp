#include<fstream>
#include<string.h>
#define inf "reteta2.in"
#define outf "reteta2.out"
#define Max 1010
#define MaxIng 101
using namespace std;

fstream f,g(outf,ios::out);

//char sir[Max];
char cp[Max];
char ing[MaxIng][30];
int dur[MaxIng];
int nring;
char numere[10]={'0','1','2','3','4','5','6','7','8','9',};

void Citire()
{
/*f.open(inf,ios::in);
f.get(sir,Max);
f.close();*/
f.open(inf,ios::in);
f.get(cp,Max);
f.close();
}

void CalcTimpTotal()
{
int timp=0;
bool gasit;
char *p;
char *ant;
ant=cp;
do
    {
    gasit=false;
    p=NULL;
    p=strchr(ant,')');
    if(p!=NULL)
        {
        gasit=true;
        timp+=atol(p+1);
        ant=p+1;
        }
    }
while(gasit);
g<<timp<<"\n";
}

bool enumar(char c)
{
for(int i=0;i<10;i++)
    if(c==numere[i])return true;
return false;
}

void getrid()
{
char *ant;
char *p;
ant=cp;
do
    {
    p=NULL;
    p=strchr(ant,')');
    if(p!=NULL)
        {
        ant=p+1;
        for(int i=0;i<strlen(p);i++)
            {
            if(p[i]==')' || p[i]==' ')continue;
            else if(!enumar(p[i]))break;
            else p[i]=' ';
            }
        }
    }
while(p!=NULL);
}

/*void Test(char *p)
{
for(int i=0;i<strlen(p);i++)g<<p[i];
}*/

void DetIng(char *p)
{
char cuv[30];
int j=0;
bool cuvant=false;
for(int i=0;i<strlen(p);i++)
    {
    if(p[i]==" ")continue;
    else if(!enumar(p[i]))
        {
        cuvant=true;
        cuv[j++]=p[i];
        }
    else if(enumar(p[i]))
        {
        cuvant=false;
        }
    }
}

void Rez()
{
char *p;
p=strtok(cp,"()");
while(p)
    {
    DetIng(p);
    p=strtok(NULL,"()");
    }
}

int main()
{
Citire();
CalcTimpTotal();
getrid();
Rez();
g.close();
return 0;
}

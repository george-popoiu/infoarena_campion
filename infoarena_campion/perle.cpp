#include<fstream>
#define MaxL 10005
#define inf "perle.in"
#define outf "perle.out"
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

char x[MaxL],y[MaxL];
int L,lg,poz,eposibil,ok,N,existaneterminal;

void DeterminStart()
{
if(L>=6 && x[1]=='2'){y[1]='b';ok=1;}
else if(L>=5 && x[1]=='1'){y[1]='b';ok=1;}
else if(L>=7 && x[1]=='3'){y[1]='c';ok=1;}
else ok=0;
}

void DeterminNeterminal()
{
existaneterminal=0;
while(poz<=lg-1)
    {
    if(y[poz]==x[poz])poz++;
    else {existaneterminal=1;break;}
    }
if(poz>lg-1)poz=lg-1;
}

void Insert2B()
{
for(int i=lg;i>=poz+1;i--)y[i+1]=y[i];
lg++;
y[poz]='2';y[poz+1]='b';
}

void Insert1A3AC()
{
for(int i=lg;i>=poz+1;i--)y[i+4]=y[i];
lg+=4;
y[poz]='1';y[poz+1]='a';y[poz+2]='3';y[poz+3]='a';y[poz+4]='c';
}

void Insert3BC()
{
for(int i=lg;i>=poz+1;i--)y[i+2]=y[i];
lg+=2;
y[poz]='3';y[poz+1]='b';y[poz+2]='c';
}

void Insert12A()
{
for(int i=lg;i>=poz+1;i--)y[i+2]=y[i];
lg+=2;
y[poz]='1';y[poz+1]='2';y[poz+2]='a';
}

void SchimbNeterminal()
{
if(y[poz]=='a')y[poz]=x[poz];
else if(y[poz]=='b' && x[poz]=='2')Insert2B();
else if(y[poz]=='b' && x[poz]=='1')Insert1A3AC();
else if(y[poz]=='c' && x[poz]=='3')Insert3BC();
else if(y[poz]=='c' && x[poz]=='1')Insert12A();
else if(y[poz]=='c' && x[poz]=='2')y[poz]=x[poz];
else eposibil=0;
}

int main()
{
f>>N;
for(int i=1;i<=N;i++)
    {
    for(int i=1;i<=L;i++){y[i]='0';x[i]='0';}
    f>>L;
    for(int i=1;i<=L;i++)f>>x[i];
    if(L==1)g<<"1"<<endl;
    else if(L==3 && x[1]=='1' && x[2]=='2')g<<"1"<<endl;
    else
        {
        DeterminStart();
        if(ok)
            {
            lg=2;poz=1;eposibil=1;
            while( eposibil==1 && lg<=L+1 )
                {
                DeterminNeterminal();
                if(existaneterminal)SchimbNeterminal();
                else break;
                }
            for(int i=1;i<=L;i++)
                {
                if(x[i]!=y[i]){g<<"0"<<endl;break;}
                if(x[i]==y[i] && i==L){g<<"1"<<endl;}
                }
            }
        else g<<"0"<<endl;
        }
    }
f.close();
g.close();
return 0;
}

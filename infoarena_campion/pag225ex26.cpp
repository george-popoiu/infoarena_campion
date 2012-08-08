#include<fstream>
#include<iostream>
#include "grafuri.cpp"
#define inf "pag225ex26.in"
using namespace std;

int LA[2][50],Start[50],n,s[50];

/*struct Nod
{
int nd;
Nod * adr_urm;
};*/

Nod *i_c,*s_c;

void BF(int nod)
{
Nod * p;
int aux;
i_c->nd=nod;
s[nod]=1;
while(i_c->adr_urm)
    {
    aux=Start[i_c->nd];
    while(aux)
        {
        if(s[LA[0][aux]]==0)
            {
            s[LA[0][aux]]=1;
            p=new Nod;
            p->nd=LA[0][aux];
            s_c->adr_urm=p;
            s_c=p;
            }
        aux=LA[1][aux];
        }
    i_c=i_c->adr_urm;
    }
}

int main()
{
CitireLAStatic(inf,LA,Start,&n);
i_c=new Nod;
s_c=new Nod;
s_c=i_c;
BF(1);
for(int i=1;i<=n;i++)cout<<s[i]<<" ";
return 0;
}

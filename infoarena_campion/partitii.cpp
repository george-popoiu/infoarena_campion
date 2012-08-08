#include<fstream>
#include<iostream>
#include "stivaobiect.h"
#define inf "aranjamente.out"
#define outf "aranjamente.out"
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int n,s;
Stiva st;

void Tipar(Stiva st)
{
for(int i=1;i<=st.Height();i++)cout<<st.GetValueAt(i)<<" ";
cout<<endl;
}

void Init(Stiva * st)
{
(*st).Push(0);
}

int Succesor(Stiva * st)
{
if( (*st).GetValue() < n-(s-(*st).GetValue()) )
    {
    s-=(*st).GetValue();
    (*st).Modify((*st).Height(),(*st).GetValue()+1);
    s+=(*st).GetValue();
    return 1;
    }
return 0;
}

int Valid(Stiva st)
{
return 1;
}

int Solutie(Stiva st)
{
return (s==n);
}

void Back()
{
int AS;
Init(&st);
while(st.Height()>0)
    {
    do{}while( (AS=Succesor(&st)) && !Valid(st) );
    if(AS)
        {
        if(Solutie(st))Tipar(st);
        else Init(&st);
        }
    else {s-=st.GetValue();st.Pop();}
    }
}

int main()
{
cout<<"n=";cin>>n;
Back();
f.close();
g.close();
return 0;
}

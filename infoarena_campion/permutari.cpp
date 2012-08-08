#include<fstream>
#include<iostream>
#include "stivaobiect.h"
#define inf "permutari.in"
#define outf "permutari.out"
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int n;
Stiva st;

void Tipar(Stiva st)
{
for(int i=1;i<=n;i++)cout<<st.GetValueAt(i)<<" ";
cout<<"\n";
}

void Init(Stiva * st)
{
(*st).Push(0);
}

int Succesor(Stiva * st)
{
if( (*st).GetValue() < n )
    {
    (*st).Modify((*st).Height(),(*st).GetValue()+1);
    return 1;
    }
return 0;
}

int Valid(Stiva st)
{
for(int i=1;i<st.Height();i++)
    {
    if(st.GetValueAt(i)==st.GetValue())return 0;
    }
return 1;
}

int Solutie(Stiva st)
{
return (st.Height()==n);
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
    else st.Pop();
    }
}

int main()
{
//cout<<"n=";cin>>n;
f>>n;
Back();
f.close();
g.close();
return 0;
}

#include<fstream>
#include<iostream>
#define inf ""
#define outf ""
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int n,st[100],k,s;

void init()
{
st[k]=0;
}

void tipar()
{
for(int i=1;i<=k;i++)cout<<st[i]<<" ";
cout<<endl;
}

int valid(){return 1;}

int succ()
{
if(st[k]<n-(s-st[k]))
    {
    s-=st[k];
    st[k]++;
    s+=st[k];
    return 1;
    }
return 0;
}

int sol()
{
return (s==n);
}

void bkt()
{
int as;
k=1;
init();
while(k>0)
    {
    do{}while( (as=succ()) && !valid() );
    if(as)
        {
        if(sol())tipar();
        else {k++;init();}
        }
    else {s-=st[k];k--;}
    }
}

int main()
{
cout<<"n=";cin>>n;
bkt();
f.close();
g.close();
return 0;
}

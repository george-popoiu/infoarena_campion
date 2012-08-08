#include<fstream>
#define MaxHeight 100
using namespace std;

struct Stiva
{
int Stack[MaxHeight];
int Top;
};

void Push(Stiva * stiva,int val)
{
if(stiva->Top<MaxHeight)
    {
    stiva->Top++;
    stiva->Stack[stiva->Top]=val;
    }
}

void Pop(Stiva * stiva)
{
if(stiva->Top>0)
    {
    stiva->Top--;
    }
}

int main()
{
Stiva stiva;
int n,cobor=0;
long long rez=1;
fstream f("fact3.in",ios::in);
f>>n;
f.close();
stiva.Top=1;
stiva.Stack[stiva.Top]=n;
while(stiva.Top>0)
    {
    if(stiva.Stack[stiva.Top]>1 && !cobor)
        {
        Push(&stiva,stiva.Stack[stiva.Top]-1);
        }
    else
        {
        cobor=1;
        rez*=stiva.Stack[stiva.Top];
        Pop(&stiva);
        }
    }
fstream g("fact3.out",ios::out);
g<<rez;
g.close();
return 0;
}

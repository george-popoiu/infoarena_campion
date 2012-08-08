#include<fstream>
using namespace std;

fstream f("piata.in",ios::in),g("piata.out",ios::out);

int n,it,jt,im,jm;
unsigned long long suma;

unsigned long long calc_sum(int i,int j)
{
unsigned long long sum=0;
int nr_start,col,numar;
if(i==1)
    {
    numar=j;
    while(numar){sum+=numar%10;numar/=10;}
    }
else
    {
    nr_start=n-(i-2);
    col=n-nr_start+2;
    if(j<col)numar=nr_start+j-1;
    else if(j==col)numar=1;
    else numar=1+j-col;
    while(numar){sum+=numar%10;numar/=10;}
    }
return sum;
}

int main()
{
int i,j;
f>>n>>it>>jt>>im>>jm;
f.close();
i=it;
while(i<=im)
    {
    j=jt;
    while(j<=jm)
        {
        suma+=calc_sum(i,j);
        j++;
        }
    i++;
    }
g<<suma;
g.close();
return 0;
}

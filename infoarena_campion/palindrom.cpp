#include<fstream>
#include<string.h>
#define LgMax 101
using namespace std;

fstream f("palindrom.in",ios::in),g("palindrom.out",ios::out);

char s[LgMax];
int rez,lg;

void citire();
int palindrom(int st,int sf);
void rezolvare();
void afisare();

int main()
{
citire();
rezolvare();
afisare();
return 0;
}

void citire()
{
f.getline(s,LgMax);
lg=strlen(s);
f.close();
}

int palindrom(int st,int sf)
{
while(st<sf)
    {
    if(s[st]!=s[sf])return 0;
    st++;sf--;
    }
return 1;
}

void rezolvare()
{
int nrp[lg],nrmin,i,j;
for(i=0;i<lg;i++)
    {
    if(palindrom(0,i))nrp[i]=1;
    else
        {
        nrmin=LgMax+2;
        for(j=0;j<i;j++)
            {
            if( palindrom(j+1,i) && nrp[j]<nrmin ) nrmin=nrp[j];
            }
        nrp[i]=1+nrmin;
        }
    }
rez=nrp[lg-1];
}

void afisare()
{
g<<rez<<endl;
g.close();
}

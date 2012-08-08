#include<fstream>
#include<string.h>
#define inf "ec_palind.in"
#define outf "ec_palind.out"
#define Max 102
#define PINF 0x3f3f3f3f
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int pal[Max];
int lg;
char sir[Max];

void Citire()
{
f.get(sir+1,Max);
lg=strlen(sir+1);
}

int Palindrom(char s[],int i,int j)
{
while(i<j)
    {
    if(s[i]!=s[j])return 0;
    i++;j--;
    }
return 1;
}

void Rezolvare()
{
for(int i=1;i<=lg;i++)
    {
    if(Palindrom(sir,1,i))pal[i]=1;
    else
        {
        pal[i]=PINF;
        for(int j=1;j<i;j++)
            {
            if(Palindrom(sir,j+1,i) && pal[i]>pal[j]+1)pal[i]=pal[j]+1;
            }
        }
    }
g<<pal[lg];
}

int main()
{
Citire();
Rezolvare();
f.close();
g.close();
return 0;
}

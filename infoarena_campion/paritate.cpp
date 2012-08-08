#include<fstream>
#include<string.h>
#include<vector>
#define inf "paritate.in"
#define outf "paritate.out"
#define Max 500000
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

char *sir=new char[Max];
vector<int> gresite;
vector<char> decoda;
bool gresit=false;
int N;

void Citire(){f.get(sir+1,Max);}

bool corect(int st,int sf,int& nr)
{
bool par;
int nr1=0;
if(sir[st]-'0')par=false;
else par=true;
for(int i=st+1;i<=sf;i++)
    if(sir[i]-'0')
        {
        nr1++;
        nr+=( 1<<(sf-i) );
        }
if(nr1%2==0 && !par)return false;
else if(nr1%2==1 && par)return false;
return true;
}

void Rezolva()
{
int nr;
N=strlen(sir+1)/8;
for(int i=0;i<N;i++)
    {
    nr=0;
    if(corect(i*8+1,i*8+8,nr))
        {
        if(nr==10)decoda.push_back('\n');
        else decoda.push_back((char)(nr));
        }
    else
        {
        gresit=true;
        gresite.push_back(i);
        }
    }
if(gresit)
    {
    g<<"NU\n";
    vector<int>::iterator it;
    for(it=gresite.begin();it<gresite.end();it++)g<<*it<<" ";
    }
else
    {
    g<<"DA\n";
    vector<char>::iterator it;
    for(it=decoda.begin();it<decoda.end();it++)g<<*it;
    }
}

int main()
{
Citire();
Rezolva();
f.close();
g.close();
return 0;
}

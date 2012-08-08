#include<fstream>
#include<string.h>
//#include<stdio.h>
#define inf "ecuatii2.in"
#define outf "ecuatii2.out"
#define MaxL 256
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int N;
int cx,l;
char s[MaxL];

void Rezolvare()
{
int egal=0;
cx=l=0;
for(int i=0;i<strlen(s);i++)
    {
    if(!egal)
        {
        if(i==0 && s[i]=='x')cx+=1;
        else if(s[i]=='x' &&  (s[i-1]=='-' || s[i-1]=='+') )
            {
            if(s[i-1]=='-')cx-=1;
            else if(s[i-1]=='+')cx+=1;
            }
        else if(s[i]-'0'<=9 && s[i]-'0'>=0 && s[i+1]=='x')
            {
            if(i>0 && s[i-1]=='-')cx-=(s[i]-'0');
            else if(i>0 && s[i-1]=='+')cx+=(s[i]-'0');
            else if(i==0)cx+=s[i]-'0';
            }
        else if(i==0 && s[i]-'0'<=9 && s[i]-'0'>=0 && s[i+1]!='x')l+=s[i]-'0';
        else if(s[i]-'0'<=9 && s[i]-'0'>=0 && s[i+1]!='x' && (s[i-1]=='-' || s[i-1]=='+') )
            {
            if(s[i-1]=='-')l-=(s[i]-'0');
            else if(s[i-1]=='+')l+=(s[i]-'0');
            }
        else if(s[i]=='=')egal=1;
        }
    else
        {
        if(s[i]=='x' && s[i-1]=='=')cx-=1;
        else if(s[i]=='x' && (s[i-1]=='-' || s[i-1]=='+'))
            {
            if(s[i-1]=='-')cx+=1;
            else if(s[i-1]=='+')cx-=1;
            }
        else if(s[i]-'0'<=9 && s[i]-'0'>=0 && s[i+1]=='x')
            {
            if(s[i-1]=='=')cx-=(s[i]-'0');
            else if(s[i-1]=='-')cx+=(s[i]-'0');
            else if(s[i-1]=='+')cx-=(s[i]-'0');
            }
        else if(s[i]-'0'<=9 && s[i]-'0'>=0 && s[i-1]=='=' && s[i+1]!='x')l-=s[i]-'0';
        else if(s[i]-'0'<=9 && s[i]-'0'>=0 && (s[i-1]=='-' || s[i-1]=='+') && s[i+1]!='x')
            {
            if(s[i-1]=='+')l-=(s[i]-'0');
            else if(s[i-1]=='-')l+=(s[i]-'0');
            }
        }
    }
if(cx==0 && l==0)g<<"infinit\n";
else if(cx==0 && l!=0)g<<"imposibil\n";
else g<<(float) ( (float)(-l)/(float)cx )<<"\n" ;
//else printf("%.4f\n",(float) ( (float)(-l)/(float)cx ) );
}

void Citire()
{
f>>N;
for(int i=1;i<=N;i++)
    {
    f.get();
    f.get(s,256);
    //g<<s[0]-'0'<<"\n";
    Rezolvare();
    }
}

int main()
{
//freopen(outf,"w",stdout);
Citire();
f.close();
g.close();
return 0;
}

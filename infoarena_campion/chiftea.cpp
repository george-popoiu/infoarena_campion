/*#include<fstream>
#include<iostream>*/
#include<stdio.h>
#include<math.h>
#define inf "chiftea.in"
#define outf "chiftea.out"
using namespace std;

//fstream f(inf,ios::in),g(outf,ios::out);

int T;
unsigned long long N,rez1,rez2;

int main()
{
freopen(inf,"r",stdin);
freopen(outf,"w",stdout);
//f>>T;
scanf("%d",&T);
for(int i=1;i<=T;i++)
    {
    //f>>N;
    scanf("%lld",&N);
    rez1=4*(unsigned long long)(sqrt(N));
    rez2=(unsigned long long)(sqrt(N))*(unsigned long long)(sqrt(N));
    if(N==1)printf("4\n");//g<<"4"<<endl;
    else if(N==2)printf("6\n");//g<<"6"<<endl;
    else if( rez2 == N)
        {
        //g<<rez1<<endl;
        printf("%lld\n",rez1);
        }
    else
        {
        if( N - rez2  <= (unsigned long long)sqrt(N) )
            {
            //g<<rez1+2<<endl;
            printf("%lld\n",rez1+2);
            }
        else
            {
            //g<<rez1+4<<endl;
            printf("%lld\n",rez1+4);
            }
        }
    }
//f.close();
//g.close();
return 0;
}

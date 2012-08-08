#include<stdio.h>
#define inf "inversmodular.in"
#define outf "inversmodular.out"

void euclid(int &x,int &y, int a,int b)
{
if( !b ) { x=1; y=0; }
else
    {
    int x0,y0;
    euclid(x0,y0,b,a%b);
    x=y0;
    y=x0-(a/b)*y0;
    }
}

int main()
{
freopen(inf,"r",stdin);
freopen(outf,"w",stdout);

int A,N;
int X,Y;

scanf("%d%d",&A,&N);
euclid(X,Y,A,N);
for( ; X<0; ) X+=N;
printf("%d",X);

return 0;
}

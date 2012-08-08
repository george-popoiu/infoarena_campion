#include<fstream>
#include<string.h>
#define maxn 2000
using namespace std;

fstream f("suma.in",ios::in),g("suma.out",ios::out);

int a[maxn],L,n;
long smax[4][maxn];

void Citire()
{
f>>n;
char s[3*maxn];
f.get();
f.getline(s,3*maxn);
int i,j=1;
for(i=0;i<strlen(s);i++)
    {
    if(s[i]!=' ' && s[i]!='\n')a[j++]=s[i]-'0';
    }
L=j-1;
f.close();
}

void Rezolvare()
{
int i,j;
long suma;
/*Initializare*/
for(i=0;i<4;i++)
    for(j=0;j<=n;j++)smax[i][j]=-1;
smax[0][0]=0;smax[1][1]=a[1];smax[2][1]=a[1]*10+a[2];
if(a[2])smax[2][2]=a[1]+a[2];
smax[3][1]=a[1]*100+a[2]*10+a[3];
if(a[2])smax[3][2]=a[1]+a[2]*10+a[3];
if(a[3] && smax[3][2]<a[1]*10+a[2]+a[3])smax[3][2]=a[1]*10+a[2]+a[3];
if( a[2] && a[3] )smax[3][3]=a[1]+a[2]+a[3];
/*Rezolvare*/
for(i=4;i<=L;i++)
    {
    smax[i%4][0]=smax[i%4][1]=-1;
    for(j=2;j<=i;j++)
        {
        if(a[i]==0)smax[i%4][j]=-1;
        else
            {
            // Folosim o singura cifra
            if( smax[(i-1+4)%4][j-1]!=-1)
                {
                suma=smax[(i-1+4)%4][j-1]+a[i];
                smax[i%4][j]=suma;
                }
            }
        if( a[i-1]>0 )
            {
            //Folosim doua cifre
            if( smax[(i-2+4)%4][j-1]!=-1)suma=smax[(i-2+4)%4][j-1]+a[i-1]*10+a[i];
            if(suma>smax[i%4][j])smax[i%4][j]=suma;
            }
        if(a[i-2]>0)
            {
            if( smax[ (i-3+4)%4 ][j-1] !=-1 ) suma=smax[ (i-3+4)%4 ][j-1] +a[i-2]*100+a[i-1]*10+a[i];
            if(suma>smax[i%4][j])smax[i%4][j]=suma;
            }
        }
    }
}

void Afisare()
{
g<<smax[L%4][n];
g.close();
}

int main()
{
Citire();
Rezolvare();
Afisare();
return 0;
}

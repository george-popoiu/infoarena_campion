#include<stdio.h>
#include<string.h>
#define inf "scmax3.in"
#define outf "scmax3.out"
using namespace std;

int d[100][100][100];
int l1,l2,l3;
//char s1[100],s2[100],s3[100];
int s1[]={1,2,3,4,5,6};
int s2[]={1,3,4,5,5,6};
int s3[]={1,5,6,3,4,5};

/*void read()
{
scanf("%s",s1+1); l1=strlen(s1+1);
scanf("%s",s2+1); l2=strlen(s2+1);
scanf("%s",s3+1); l3=strlen(s3+1);
//printf("%s %s %s",s1+1,s2+1,s3+1);
}*/

inline int max(int a,int b) { return ( a>b ? a : b ); }

void solve()
{
l1=l2=l3=5;
for(int i=1; i<=l1; i++)
    for(int j=1; j<=l2; j++)
        for(int k=1; k<=l3; k++)
            if( s1[i]==s2[j]==s3[k] ) d[i][j][k]=1+d[i-1][j-1][k-1];
            else d[i][j][k]= max( d[i-1][j][k], max(d[i][j-1][k],d[i][j][k-1]) );
printf("%d",d[l1][l2][l3]);
}

int main()
{
freopen(inf,"r",stdin);
freopen(outf,"w",stdout);
//read();
solve();
return 0;
}

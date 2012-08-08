#include<stdio.h>
#include<algorithm>
#define inf "numere8.in"
#define outf "numere8.out"
#define MOD 9973
#define Max 9100
using namespace std;

int nr[2][Max];
int a,b;

void read()
{
	scanf("%d%d",&a,&b);
}

void solve()
{
	int l1=0,l2=1;

	for(int i=1; i<=9; i++)
		if( b%i==0 ) nr[l1][i] = 1;

	for(int i=2; i<=a; i++)
	{
		for(int t=1; t<=9; t++)
			if( b%t==0 )
				for(int j=1; j<=b; j++)
				{
					if( j%t!=0 ) continue;
					nr[l2][j] = 0;
					nr[l2][j] += nr[l1][j/t] ; nr[l2][j] %= MOD;
				}
		swap(l1,l2);
	}
	printf("%d",nr[l1][b]);
}

int main()
{
	freopen(inf,"r",stdin);
	freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

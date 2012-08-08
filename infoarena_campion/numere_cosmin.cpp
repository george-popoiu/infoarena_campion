#include<stdio.h>
#define inf "numere.in"
#define outf "numere.out"
using namespace std;

int n, v[10001];
//v[i] = 1, daca numarul i a fost citit
//v[i] = 0, altfel

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);

    int a;

    do {
        scanf("%d", &a);
        v[a] = 1;
    } while( a!=0 );

    int raspuns = 10000;
    for(int i=1; i<=10000; i++) //scadem din 10000 numarul numerelor citite
    {
        if( v[i] ) raspuns--;
    }

    printf("%d", raspuns);

	return 0;
}

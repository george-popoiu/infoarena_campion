#include<stdio.h>
using namespace std;

int sol = 0;
int k, l, m, n, d;

int main()
{
	scanf("%d%d%d%d%d", &k, &l, &m, &n, &d);

	for(int i=1; i<=d; ++i) {
	    if( i%k==0 ) {
	        ++sol;
	        continue;
	    }
	    if( i%l==0 ) {
	        ++sol;
	        continue;
	    }
	    if( i%m==0 ) {
	        ++sol;
	        continue;
	    }
	    if( i%n==0 ) {
	        ++sol;
	        continue;
	    }
	}

	printf("%d", sol);

	return 0;
}

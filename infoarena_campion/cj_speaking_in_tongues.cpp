#include<stdio.h>
#include<string.h>
#define inf "cj_speaking_in_tongues.in"
#define outf "cj_speaking_in_tongues.out"
using namespace std;

int T;
char s[31][110];

void read()
{
    scanf("%d", &T);
    gets(s[0]);

    for(int i=1; i<=T; i++) {
        gets(s[i]);
    }
}

char map[] = { 'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l', 'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q' };

char* translate(char *a) {
    for(int i=0; i<strlen(a); i++) {
        if( !(a[i]>='a' && a[i]<='z') ) continue;
        a[i] = map[ a[i]-'a' ];
    }
    return a;
}

void solve()
{
    for(int i=1; i<=T; i++) {
        printf("Case #%d: %s\n", i, translate(s[i]));
    }
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

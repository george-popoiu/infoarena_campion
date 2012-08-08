#include<stdio.h>
#include<list>
#include<string.h>
#define inf "test.in"
#define outf "test.out"
using namespace std;

char s[200];
int p, n, neg;
list<char> r;

void read()
{
    scanf("%s", s);
    n = strlen(s);
    if( s[0]=='-' ) neg = 1;
}

void solve()
{
    p = n;
    for(int i=n-1; i>=0; i--)
        if( s[i]=='.' ) p = i;

    //printf("%d", p);

    int m = 0;
    for(int i=p-1; i>=0; i--)
        if( s[i]<'0' || s[i]>'9' ) continue;
        else {
            r.push_front(s[i]); m++;
            if(m==3) m = 0, r.push_front(',');
        }
    if( r.front()==',' ) r.pop_front();

    r.push_back('.'); int d = r.size();
    //for(list<char>::iterator it=r.begin(); it!=r.end(); ++it) printf("%c", *it);

    for(int i=p+1; i<n && i<p+3; i++) r.push_back(s[i]);
    if( r.size()!=d+2 )
        while( r.size()<d+2 ) r.push_back('0');

    if( neg ) printf("($");
    else printf("$");
    for(list<char>::iterator it=r.begin(); it!=r.end(); ++it) printf("%c", *it);
    if( neg ) printf(")");
}

int main()
{
	//freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

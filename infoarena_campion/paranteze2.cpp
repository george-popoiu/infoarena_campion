#include<stdio.h>
#include<string.h>
#include<stack>
#define inf "paranteze2.in"
#define outf "paranteze2.out"
#define nmax 1000010
using namespace std;

char s[nmax];
int n, dp[nmax], next[nmax];
stack<int> st;

void read()
{
    scanf("%s", s+1);
    n = strlen(s+1);
}

void solve()
{
    for(int i=1; i<=n; i++) {
        if( !st.empty() && s[st.top()]=='(' && s[i]==')' ) {
            next[st.top()] = i;
            st.pop();
        }
        else st.push(i);
    }

    long long ans = 0;
    for(int i=n; i>=1; i--) {
        if( !next[i] ) continue;
        dp[i] = 1+dp[next[i]+1];
        ans += 1LL*dp[i];
    }

    printf("%lld", ans);
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

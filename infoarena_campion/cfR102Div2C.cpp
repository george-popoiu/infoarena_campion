#include<iostream>
#include<vector>
#define ll long long
using namespace std;

ll n;
vector<int> divs;

void read()
{
    cin>>n;
}

void solve()
{
    for(int i=1; i<=n; i++)
        if( n%i==0 ) divs.push_back(i);
}

int main()
{
	read(); solve();
	return 0;
}

#include <fstream>
#include <queue>
using namespace std;

ifstream f("strung.in"); ofstream g("strung.out");

priority_queue <int, vector <int>, greater<int> > v;
int i, n, m, t, x, y;

int main(){
	f>>m>>n;
	for (i=1; i<=m; i++) v.push(0);
	for (i=1; i<=n; i++){
		f>>x;
		y=v.top();
		
		if (x+y>t) t=x+y;
		
		v.pop();
		v.push(x+y);
	}
	
	g<<t;
}

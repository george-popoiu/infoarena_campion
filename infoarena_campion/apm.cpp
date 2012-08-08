#include<stdio.h>
//#include<string.h>
#include<vector>
#include<list>
#include<queue>
#include<algorithm>
#define inf "apm.in"
#define outf "apm.out"
#define NMax 300
#define Max 32100
using namespace std;

int N, cost[NMax][NMax], m[NMax][NMax];
vector<int> LA[NMax];
int A[Max], nr, viz[NMax], uz[Max];

struct cuplu { int a,b,c; };
cuplu B[ NMax*(NMax-1)/2 + 100 ];

void read()
{
	scanf("%d",&N);
	int a,b,c;
	for(int i=1; i<N; i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		cost[a][b] = cost[b][a] = c;
		LA[a].push_back(b); LA[b].push_back(a);
	}
	while( scanf("%d",&a)!=EOF ) A[++nr] = a;
}

inline int max(int a,int b) { return ( a<b ? b : a ); }

void BFS(int nod,int t)
{
	queue<int> q;
	//memset( viz, 0, sizeof(viz) );
	viz[nod] = t; q.push(nod);
	while( !q.empty() )
	{
		int u = q.front(); q.pop();
		for(int i=0; i<LA[u].size(); i++)
		{
			int v = LA[u][i];
			if( viz[v]!=t )
			{
				viz[v] = t;
				m[nod][v] = max( m[nod][u], cost[u][v] );
				q.push(v);
			}
		}
	}
}

struct rule
{
	bool operator() (const cuplu &a,const cuplu &b)
	{
		return a.c < b.c;
	}
};

void solve()
{
	for(int i=1; i<=N; i++) BFS(i,i);

	int u=0;
	for(int i=1; i<N; i++)
		for(int j=i+1; j<=N; j++) { B[++u].a=i; B[u].b=j; B[u].c=m[i][j]; }

	sort( B+1, B+1+u, rule() );
	sort( A+1, A+1+nr );

	bool rez = false;
	for(int i=1; i<=u; i++)
	{
		if( cost[ B[i].a ][ B[i].b] ) continue;

		for(int j=1; j<=nr; j++)
			if( A[j]>=B[i].c && !uz[j] )
			{
				uz[j] = 1;
				printf("%d %d %d\n",B[i].a,B[i].b,A[j]); rez = true;
				break;
			}
	}

	if( !rez ) printf("0");
}

int main()
{
	freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	read(); solve();
	return 0;
}

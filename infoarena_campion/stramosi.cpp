#include<fstream>
using namespace std;

fstream f("stramosi.in",ios::in),g("stramosi.out",ios::out);

int n,m;
int v[251000],mat[300001][3];

void cauta(int q,int p,int i)
{
if(i==p)
	{
	g<<q<<"\n";
	return;
	}
else
	{

	if(q!=0)cauta(v[q],p,i+1);
	else {g<<"0"<<"\n";return;}
	}
}

int main()
{
int i;
f>>n>>m;
for(i=1;i<=n;i++)f>>v[i];
for(i=1;i<=m;i++)
	{
	f>>mat[i][1]>>mat[i][2];
	}
for(i=1;i<=m;i++)
	{
	if(mat[i][2]==1)g<<v[mat[i][1]]<<"\n";
	else cauta(v[v[mat[i][1]]],mat[i][2],2);
	}
f.close();
g.close();
return 0;
}

#include<fstream>
#include<list>
#include<stack>
#include<queue>
#define inf "ciclueuler.in"
#define outf "ciclueuler.out"
#define NMax 100010
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int N,M;
int viz[NMax];
//int grad[NMax];
int indeg[NMax], outdeg[NMax];
list<int> G[NMax];//lista de adiacenta
list<int> L;//lista in care retin ciclul
stack<int> S;
queue<int> Q;

void citire()
{
int u,v;
f>>N>>M;
for(int i=1;i<=M;i++)
    {
    f>>u>>v;
    //grad[u]++;grad[v]++;
    outdeg[u]++; indeg[v]++;
    G[u].push_back(v);
    //G[v].push_back(u);
    }
}

bool gradpar()
{
for(int i=1;i<=N;i++)
    //if(grad[i]%2!=0)return false;
    if( outdeg[i]!=indeg[i] ) return false;
return true;
}

bool conex()
{
int v;
//BFS
Q.push(1);viz[1]=1;
while( !Q.empty() )
    {
    v=Q.front(); Q.pop();
    for( list<int>::iterator it=G[v].begin() ; it != G[v].end() ; it ++ )
        if( !viz[*it] )
            {
            Q.push(*it);
            viz[*it]=1;
            }
    }
//BFS
for(int i=1;i<=N;i++)
    if(!viz[i])return false;
return true;
}

void sterge(int v,int w)
{
//grad[v]--;
//grad[w]--;
outdeg[v]--; indeg[w]--;
G[v].pop_front();
/*for( list<int>::iterator it=G[w].begin() ; it != G[w].end() ; it ++ )
    if( *it == v )
        {
        G[w].erase(it);
        return;
        }*/
}

void euler(int v)
{
int w;
while(true)
    {
    if( G[v].empty() )break;
    w=G[v].front();
    S.push(v);
    sterge(v,w);
    v=w;
    }
}

void rez()
{
int v=1;
do
    {
    euler(v);
    v=S.top(); S.pop();
    L.push_back(v);
    }
while( !S.empty() );
}

int main()
{
citire();
if(gradpar() && conex())
    {
    rez();
    for( list<int>::iterator it=L.begin(); it!= L.end(); it++ )g<<*it<<" ";
    }
else g<<"-1";
f.close();
g.close();
return 0;
}

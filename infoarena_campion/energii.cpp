#include<fstream>
#define inf "energii.in"
#define outf "energii.out"
#define GMax 1010
#define INF 0x3f3f3f3f
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int G,W;
int rez=INF;
int c[GMax],e[GMax];
int cmin[ 200*GMax ]; //cmin[i]=costul minim necesar pentru a avea energia i

void read()
{
f>>G>>W;
for(int i=1; i<=G; i++) f>>e[i]>>c[i];
}

inline int min(int a,int b) { return ( a<b ? a : b ); }

inline int max(int a,int b) { return ( a>b ? a : b ); }

void solve()
{
int lim=0;
cmin[0]=1;
for(int i=1; i<=G; i++)
    for(int j=lim; j>=0; j--)
        {
        if( cmin[j] )
            if( !cmin[ j+e[i] ] || cmin[ j+e[i] ] > cmin[j]+c[i] )
                {
                cmin[j+e[i]]=cmin[j]+c[i];
                if( j+e[i]>=W ) rez=min(rez,cmin[j+e[i]]);
                lim=max(lim,j+e[i]);
                }
        lim=min(lim,W);
        }
if( rez==INF ) g<<"-1";
else g<<rez-1;
}

int main()
{
read();
solve();
f.close();
g.close();
return 0;
}

#include<stdio.h>
#include<string.h>
#define inf "transport.in"
#define outf "transport.out"
#define Max 1010
using namespace std;

int N,K,M,D;
int m[Max][Max];//m[i][j]=numarul maxim de animale vii ce le pot obtine prin incarcarea a animalelor 1,...,i in j vagoane
int slab[Max][Max];// slab[i][j]=inseamna ca animalul i este mai slab de cat valoarea lui slav[i][j]
int tare[Max][Max];// tare[i][j]=la fel ca slab
int lg[Max];//lg[i]=cate animale mai tari si mai slabe decat el are animaul i
int raman[Max][Max];//ramane[i][j]=cate animale raman daca incarc animalele i,i+1,...,j in acelasi vagon
int viu[Max];

void read()
{
int x,y,z;
scanf("%d %d %d %d", &N, &K, &M, &D);
for(int i=1; i<=D; i++)
    {
    scanf("%d %d %d", &x, &y, &z);
    lg[x]++;
    slab[x][ lg[x] ]=y;
    tare[x][ lg[x] ]=z;
    }
}

void preproc_raman()
{
bool mor=true;
for(int i=1; i<=N; i++)
    for(int j=i; j<i+M && j<=N; j++)
    //urcam vacile i...j in acelasi vagon
        {
        mor=true;
        memset( viu, 1, Max*sizeof(int) ); //initial toate sunt vii
        while( mor ) //cat timp mai mor
            {
            mor=false;
            for(int k=i; k<=j; k++)
                if( viu[k] )
                    for(int z=1; z<=lg[k]; z++) //parcurg vacile mai slabe decat vaca k in vagon
                        if( slab[k][z]>=i && slab[k][z]<=j && viu[ slab[k][z] ] )
                            if( tare[k][z]<i || tare[k][z]>j || !viu[ tare[k][z] ] )
                                {
                                viu[ slab[k][z] ]=0;
                                mor=true;
                                }
            }
        for(int k=i; k<=j; k++)
            if( viu[k] ) raman[i][j]++;
        }
}

void solve()
{
for(int i=1; i<=M; i++) m[i][1]=raman[1][i];
for(int i=M+1; i<=N; i++) m[i][1]=-1;
for(int i=1; i<=N; i++)
    for(int j=2; j<=K; j++) m[i][j]=-1;
//rezolvare
for(int k=2; k<=K; k++) //incarc vagonul k
    for(int i=k; i<=k*M && i<=N; i++)
        for(int j=i-M+1; j<=i; j++)
            {
            if( j-1<k-1 )continue;
            if( m[j-1][k-1]==-1 ) continue;
            if( m[i][k] < m[j-1][k-1] + raman[j][i] ) m[i][k]=m[j-1][k-1]+raman[j][i];
            }
printf("%d",m[N][K]);
}

int main()
{
freopen(inf,"r",stdin);
freopen(outf,"w",stdout);
read();
preproc_raman();
solve();
return 0;
}

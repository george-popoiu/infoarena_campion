#include<fstream>
#define inf "subsir2.in"
#define outf "subsir2.out"
#define NMax 5001
using namespace std;

const int INF = 0x3f3f3f3f;

fstream f(inf,ios::in),g(outf,ios::out);

int N, v[NMax];
int best[NMax], T[NMax];

void Citire()
{
    f>>N;
    for(int i=1; i<=N; i++) f>>v[i];
}

int works(int i) {
    for(int j=i-1; j>=1; j--)
        if( v[j]<=v[i] ) return 0;
    return 1;
}

void Rezolva()
{
    int valmin, poz = 1;
    for(int i=N; i>=1; i--) {
        best[i] = INF;
        T[i] = i;
        valmin = INF;
        for(int j=i+1; j<=N; j++)
            if(v[j]>=v[i] && v[j]<valmin) {
                valmin=v[j];
                if( best[j] + 1 < best[i] ) {
                    best[i] = best[j]+1;
                    T[i]=j;
                }
                else if( best[j]+1==best[i] && v[j]<v[T[i]]) T[i]=j;
            }
        if( best[i]==INF ) best[i] = 1;
    }

    int sol = INF, st;
    for(int i=1; i<=N; i++)
        if( works(i) ) {
            if( best[i]<sol ) sol = best[i], st = i;
            else if( best[i]==sol && v[i]<v[st] ) st = i;
        }

    g<<sol<<"\n";
    while(1) {
        g<<st<<" ";
        if(T[st]==st)break;
        st = T[st];
    }
}

int main()
{
    Citire(); Rezolva();
    f.close(); g.close();
    return 0;
}

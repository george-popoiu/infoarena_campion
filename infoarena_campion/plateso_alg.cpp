#include<fstream>
#include<string.h>
#include<vector>
#define inf "plateso_alg.in"
#define outf "plateso_alg.out"
#define Dim 100
#define ReportBigger 2
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

class PosData
{
    private:
    int _start1;
    int _start2;
    int _length;
    public:
    PosData(int start1,int start2,int length)
    {
        _start1 = start1;
        _start2 = start2;
        _length = length;
    }
    int GetStart1(){return _start1;}
    int GetStart2(){return _start2;}
    int GetLength(){return _length;}
    ~PosData()
    {
    }
};

char *a,*b;
int c[Dim][Dim];
int n,m;
vector<PosData> positions;

void read()
{
    a = new char[Dim];
    b = new char[Dim];
    f.get(a,Dim); f.get();
    f.get(b,Dim);
    n = strlen(a)-1;
    m = strlen(b)-1;
}

void clear(int start_lin,int start_col,int length,int c[][100])
{
    int l=0;
    int i=start_lin,j=start_col;
    while( l<length )
    {
        c[i][j]=0;
        i++; j++;
        l++;
    }
}

void solve()
{
    for(int i=0; i<strlen(a); i++)
        for(int j=0; j<strlen(b); j++)
            if( a[i]==b[j] )
            {
                if( i==0 || j==0 ) c[i][j] = 1;
                else c[i][j] = 1 + c[i-1][j-1];
            }
            else c[i][j] = 0;

    for(int i=0; i<strlen(a); i++)
    {
        for(int j=0; j<strlen(b); j++) g<<c[i][j]<<" ";
        g<<"\n";
    }

    bool merge=true;
    while(merge)
    {
        merge = false;

        int cur_max=0;
        int lin,col;

        for(int i=0; i<=n; i++)
            for(int j=0; j<=m; j++)
                if( c[i][j]>ReportBigger && c[i][j]>cur_max )
                {
                    cur_max = c[i][j];
                    lin = i; col = j;
                    merge = true;
                }
        if(merge)
        {
            clear( lin-cur_max+1, col-cur_max+1, cur_max, c );
            PosData data(lin-cur_max+1,col-cur_max+1,cur_max);
            positions.push_back(data);
        }
    }

    for(int i=0; i<positions.size(); i++)
    {
        g<< positions[i].GetStart1() <<" "<< positions[i].GetStart2() <<" " << positions[i].GetLength() <<"\n";
    }

    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=m; j++) g<<c[i][j]<<" ";
        g<<"\n";
    }
}

int main()
{
    read(); solve();
    f.close(); g.close();
    return 0;
}

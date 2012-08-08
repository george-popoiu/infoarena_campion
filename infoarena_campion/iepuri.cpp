#include<fstream>
#define inf "iepuri.in"
#define outf "iepuri.out"
#define MOD 666013
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int T, N, X, Y, Z, A, B, C;
int P;

class matrix
{
    public:
        long long M[4][4];
        matrix()
        {
            for(int i=0; i<4; i++)
                for(int j=0; j<4; j++) M[i][j] = 0;
        }

        matrix operator * ( matrix b )
        {
            matrix c;
            for(int i=1; i<=3; i++)
                for(int j=1; j<=3; j++)
                    for(int k=1; k<=3; k++) c.M[i][j] += ( ( M[i][k] * b.M[k][j] ) % MOD ) , c.M[i][j] %= MOD;
            return c;
        }
};

matrix power(matrix a, int P)
{
    if( P==0 )
    {
        matrix b;
        b.M[1][1] =  b.M[2][2] = b.M[3][3] = 1;
        return b;
    }
    else if( P==1 ) return a;
    else
    {
        if( P%2 == 0 )
        {
            matrix b; b = power(a,P/2);
            return (b*b);
        }
        else
        {
            matrix b; b = power(a,P/2);
            return (a*(b*b));
        }
    }
}

int compute()
{
    matrix R;
    int T[4][2];
    T[1][1] = Z; T[2][1] = Y; T[3][1] = X;

    R.M[1][1] = A; R.M[1][2] = B; R.M[1][3] = C;
    R.M[2][1] = R.M[3][2] = 1;
    R.M[2][3] = R.M[2][2] = R.M[3][1] = R.M[3][3] = 0;

    if( N==0 ) return T[3][1];
    if( N==1 ) return T[2][1];
    if( N==2 ) return T[1][1];

    // R^(N-2)
    P = N-2;
    matrix b = power(R,P);

    long long Rez[4][2]; Rez[1][1] = Rez[2][1] = Rez[3][1] = 0;
    for(int i=1; i<=3; i++)
        for(int k=1; k<=3; k++) //Rez[i][1] += ( (b.M[i][k] * T[k][1]) % MOD ) , Rez[i][1] %= MOD;
        Rez[i][1] += b.M[i][k] * T[k][1];

    return Rez[1][1];
}

void read()
{
    f>>T;
    for(; T; T--)
    {
        f>>X>>Y>>Z>>A>>B>>C>>N;
        g<< compute() <<"\n";
    }
}

int main()
{
	read();
	f.close(); g.close();
	return 0;
}

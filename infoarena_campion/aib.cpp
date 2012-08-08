#include<fstream>
#define inf "aib.in"
#define outf "aib.out"
#define NMax 100010
using namespace std;

fstream f(inf, ios::in), g(outf, ios::out);

int A[NMax], N, M;

int Query(int);
void Update(int, int);
int Search(int);

int main()
{
    /*f>>N>>M;

    int a, b, c;
    for(int i=1; i<=N; i++) {
        f>>a;
        Update(i, a);
    }

    for(int i=1; i<=M; i++) {
        f>>c;
        if( !c ) {
            f>>a>>b;
            Update(a, b);
        }
        else if( c==1 ) {
            f>>a>>b;
            g<< Query(b) - Query(a-1) <<"\n";
        }
        else {
            f>>a;
            g<< Search(a) <<"\n";
        }
    }


	f.close(); g.close();*/

	for(int i=1; i<=1000000; i++);
	return 0;
}

int Search(int val) {
    int st = 1, dr = N, k = -1, m, sum;
    while( st<=dr ) {
        m = (st+dr)>>1;
        sum = Query(m);
        if( sum == val ) {
            k = m;
            dr = m-1;
        }
        else if( sum > val ) dr = m-1;
        else st = m+1;
    }
    return k;
}

void Update(int ind, int val) {
    int poz = 0;
    while( ind<=N ) {
        A[ind] += val;
        //while( !(ind & (1<<poz)) ) poz++;
        //ind += (1<<poz);
        //poz++;
        ind += (ind & -ind);
    }
}

int Query(int ind) {
    int poz = 0, rez = 0;
    while( ind>0 ) {
        rez += A[ind];
        //while( !(ind & (1<<poz)) ) poz++;
        //ind -= (1<<poz);
        //poz++;
        ind -= (ind & -ind);
    }
    return rez;
}

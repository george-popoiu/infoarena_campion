#include<fstream>
using namespace std;

fstream f("numere.in", ios::in), g("pare.out", ios::out), h("impare.out", ios::out);

int main()
{
    int a;
    do {
        f>>a;
        if( a!=0 ) {
            if( a%2 ) h<<a<<" ";
            else g<<a<<" ";
        }
    }
    while( a!=0 );

    f.close(); g.close();
    h.close();
	return 0;
}

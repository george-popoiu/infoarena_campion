#include<fstream>
using namespace std;

fstream f("numere.in", ios::in), g("numere.out", ios::out);

int prim(int x)
{
    for(int i=2; i<x; i++)
        if( x%i==0 ) return 0;
    return 1;
}

int main()
{
	int a;
	do {
	    f>>a;
	    if( a && prim(a) ) g<<a<<" ";
	} while( a!=0 );

	g<<endl<<endl;
	f.close(); g.close();
	return 0;
}

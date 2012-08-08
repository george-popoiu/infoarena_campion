#include<fstream>
#include<iostream>
using namespace std;

fstream f("numere.in", ios::in);

int n;
int v[20000];

int main()
{
    f>>n;
    for(int i=0; i<n; i++) f>>v[i];

    int minim = 1001, pozitie;
    for(int i=0; i<n; i++)
    {
        if( v[i]<minim ) minim = v[i], pozitie = i;
    }

    cout<<"Valoarea minima: "<<minim<<endl;
    cout<<"Prima pozitie pe care apare: "<<pozitie+1<<endl;

    int numar_aparitii = 0;
    for(int i=0; i<n; i++)
    {
        if( v[i]==minim ) numar_aparitii++;
    }

    cout<<"Numarul de aparitii: "<<numar_aparitii<<endl<<endl<<endl;

    f.close();
	return 0;
}

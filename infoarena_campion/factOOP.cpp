#include<fstream>
#define infile "factOOP.in"
#define outfile "factOOP.out"
using namespace std;

fstream f(infile,ios::in),g(outfile,ios::out);

class Stiva // Stiva este alocata dinamic, functiile fiind foarte usor de folosit
// Push(valoare), Pop(), *numestiva.Value - valoarea ultimului element din stiva ( din motive de protectie Value poate fi o functie, sa nu dam acces la date )
// Se foloseste doar cata memorie este nevoie
// Cand se apeleaza Pop se elibereaza memoria care era folosita de ultimul element inainte de Pop
{
private:
struct Nod
    {
    int Numar;
    Nod * adr_inap;
    };
Nod *inceput,*sfarsit; // Adresa de inceput si de sfarsit a stivei
public:
int * Value;// Valoarea ultimului element din stiva
void Push(int val)
    {
    Nod * c=new Nod;
    c->adr_inap=sfarsit;
    c->Numar=val;
    *Value=val;
    sfarsit=c;
    }
void Pop()
    {
    if(sfarsit!=inceput)
        {
        Nod * c=new Nod;
        c=sfarsit;
        sfarsit=sfarsit->adr_inap;
        delete c;
        *Value=sfarsit->Numar;
        }
    }
int IsEmpty()
    {
    if(sfarsit!=inceput)return 0;
    return 1;
    }
Stiva()
    {
    Value=new int;
    *Value=0;
    inceput=new Nod;
    inceput->adr_inap=0;
    inceput->Numar=0;
    sfarsit=new Nod;
    sfarsit=inceput;
    }
~Stiva() // Destructor. Daca obiectul nu mai este folosit se elibereaza memoria folosita
    {
    delete Value;
    Nod * c=new Nod;
    c=sfarsit;
    while(c!=inceput)
        {
        Nod * aux=new Nod;
        aux=c;
        c=c->adr_inap;
        delete aux;
        }
    delete c;
    delete inceput;
    delete sfarsit;
    }
};

int main()
{
Stiva stiva;
int n,cobor=0;
long long rezultat=1;
f>>n;
stiva.Push(n);
while(!stiva.IsEmpty())
    {
    if( *stiva.Value > 1 && !cobor )
        {
        stiva.Push(*stiva.Value-1);
        if(*stiva.Value==1)cobor=1;
        }
    else
        {
        rezultat*=*stiva.Value;
        stiva.Pop();
        }
    }
g<<rezultat;
f.close();
g.close();
return 0;
}

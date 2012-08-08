#include<fstream>
#include<iostream>
#define MaxStackHeight 100
#define infile "factorialOOP.in"
#define outfile "factorialOOP.out"
using namespace std;

fstream f(infile,ios::in),g(outfile,ios::out);

class Stiva
{
//Private
//private:
/*struct Nod
    {
    int Numar;
    Nod * adr_inap;
    };
Nod *inceput,*sfarsit;*/
//Public
public:
int * Value;
void Push(int val)
    {
    /*Nod *c=new Nod;
    c->Numar=val;
    c->adr_inap=sfarsit;
    sfarsit=c;
    *Value=val;*/
    }
void Pop()
    {
    /*if(sfarsit!=inceput)
        {
        sfarsit=sfarsit->adr_inap;
        *Value=sfarsit->Numar;
        }*/
    }
Stiva()
    {
    /*inceput=new Nod;
    inceput->adr_inap=0;
    inceput->Numar=0;
    sfarsit=new Nod;
    sfarsit=inceput;*/
    *Value=1;
    }
~Stiva()
    {
    delete Value;
    }
};

int main()
{
Stiva stiva;
//stiva.Push(1);
//cout<<*stiva.Value<<endl;
f.close();
g.close();
return 0;
}


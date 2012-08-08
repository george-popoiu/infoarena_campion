#include<fstream>
#define max 100
using namespace std;

fstream f("world.in",ios::in),g("world.out",ios::out);

int v[max],n;

void Citire()
{
f>>n;
for(int i=1;i<=n;i++)f>>v[i];
f.close();
}

void Afisare()
{
for(int i=1;i<=n;i++)g<<v[i]<<" ";
g.close();
}

int main()
{
Citire();
Afisare();
return 0;
}

#include<fstream>
#include<string.h>
#define inf "text.in"
#define outf "text.out"
#define CMax 21000
#define LMax 250
using namespace std;

fstream f(inf,ios::in),g(outf,ios::out);

int c;
char *data[CMax];
char *cuv[CMax];
int nmin[CMax];
int uz[CMax];

void read()
{
char s;
int i=0;
while( !f.eof() )
    {
    f>>s;
    if( s!='\0' && s!='\n' )
        {
        data[++i] = new char[LMax];
        char *p;
        p=strtok( data[i], " " );
        while( p )
            {
            cuv[++c]=strdup( p );
            p=strtok( NULL, " " );
            }
        }
    }
g<<c<<"\n";
}

int main()
{
read();
f.close();
g.close();
return 0;
}

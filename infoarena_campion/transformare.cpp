#include<fstream>
#include<string.h>
#define DMax 101
#define COPY 0
#define DELETE 1
#define INSERT 2
#define REPLACE 3
#define TWIDDLE 4
#define KILL 5
using namespace std;

fstream f("transformare.in",ios::in),g("transformare.out",ios::out);

int cm[DMax][DMax],op[DMax][DMax],cost[6],n,m;
char x[DMax],y[DMax];

void citire();
void rezolvare();
void afisare();

int main()
{
citire();
rezolvare();
afisare();
return 0;
}

void citire()
{
f.getline(x,DMax);m=strlen(x);
f.getline(y,DMax);n=strlen(y);
for(int i=0;i<6;i++)f>>cost[i];
f.close();
}

void rezolvare()
{
int i,j;
for(i=0;i<n;i++)
    {
    cm[m][i]=cost[INSERT]*(n-i);
    op[m][i]=INSERT;
    }
for(i=0;i<m;i++)
    {
    cm[i][n]=cost[KILL];op[i][n]=KILL;
    if( cm[i][n] > (n-i)*cost[DELETE] ) { cm[i][n] = (n-i)*cost[DELETE]; op[i][n]=DELETE; }
    }
cm[m][n]=0;
for(i=m-1;i>=0;i--)
    {
    for(j=n-1;j>=0;j--)
        {
        cm[i][j]=cost[KILL]+cm[m][j];op[i][j]=KILL;
        if(x[i]==y[j] && cm[i][j]>cost[COPY]+cm[i+1][j+1]) {cm[i][j]=cost[COPY]+cm[i+1][j+1];op[i][j]=COPY;}
        if(cm[i][j] > cost[DELETE] + cm[i+1][j] ) { cm[i][j]=cost[DELETE]+cm[i+1][j]; op[i][j]=DELETE; }
        if(cm[i][j] > cost[REPLACE] + cm[i+1][j+1] ) { cm[i][j]=cost[REPLACE] + cm[i+1][j+1]; op[i][j]=REPLACE; }
        if( i<m-1 && j<n-1 && x[i]==y[j+1] && x[i+1]==y[j] && cm[i][j]>cost[TWIDDLE]+cm[i+2][j+1] )
            { cm[i][j]=cost[TWIDDLE]+cm[i+2][j+2]; op[i][j]=TWIDDLE; }
        }
    }
}

void afisare()
{
int i,j;
i=0;j=0;
g<<cm[i][j]<<endl;
while( i<m || j<n )
    {
    switch(op[i][j])
        {
        case COPY : g<<"COPY"<<endl; i++;j++; break;
        case DELETE : g<<"DELTE"<<endl; i++; break;
        case INSERT : g<<"INSERT"<<endl; j++; break;
        case REPLACE : g<<"REPLACE"<<endl; i++; j++; break;
        case TWIDDLE : g<<"TWIDDLE"<<endl; i+=2; j+=2; break;
        case KILL : g<<"KILL"<<endl; i=m; break;
        }
    }
g.close();
}

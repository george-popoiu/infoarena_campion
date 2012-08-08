#include<fstream>
#define MaxN 9
#define MaxM 13
using namespace std;

int N,M,H,p,V[MaxN],uz[MaxM];
float efmin[MaxN];

void Citire()
{
fstream f("scara.in",ios::in);
f>>H>>N>>M>>p;
f.close();
}

float Suma(int array[],int st,int sf)
{
float rez=0;
for(int i=st;i<=sf;i++)rez+=array[i];
return rez;
}

void GenInaltimi(int pas,float * efortminim,int sol[])
{
//Backtracking
int sumact=0;
if(pas<=N)
    {
    for(int j=1;j<M;j++)
        {
        if(!uz[j] && sumact+j<=H)
            {
            V[pas]=j;uz[j]=1;sumact+=j;
            //Programare dinamica
            if(pas==N && Suma(V,1,N)==H)
                {
                for(int i=1;i<=N;i++)efmin[i]=0.00;
                efmin[1]=(float)V[1];
                float min=9000000.00;
                for(int i=2;i<=N;i++)
                    {
                    min=(float)(efmin[i-1]+V[i]);
                    for(int k=0;k<=i-2;k++)
                        {
                        if(k==0){if(Suma(V,k,i)<=M && (float)((float)(Suma(V,k,i)/(i-k))+p)<min){min=(float)((float)(Suma(V,k,i)/(i-k))+p);}}
                        else {if(Suma(V,k,i)<=M && (float)((float)(Suma(V,k,i)/(i-k+1))+p)<min){min=(float)((float)(Suma(V,k,i)/(i-k+1))+p);}}
                        }
                    efmin[i]=min;
                    }
                if(efmin[N]<(*efortminim))
                        {
                        (*efortminim)=efmin[N];
                        for(int i=1;i<=N;i++)sol[i]=V[i];
                        }
                }
            //Programare dinamica
            GenInaltimi(pas+1,efortminim,sol);
            uz[V[pas]]=0;
            sumact-=V[pas];
            }
        }
    }
//Backtracking
}

int main()
{
float efortmin=9000000.00;
int solutie[MaxN];
Citire();
GenInaltimi(1,&efortmin,solutie);
fstream g("scara.out",ios::out);
g<<(float)efortmin<<endl;
for(int i=1;i<=N;i++)g<<solutie[i]<<" ";
g.close();
return 0;
}

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define inf "ecuatii2.in"
#define outf "ecuatii2.out"
#define MaxN 300
using namespace std;

int N;
long nr1,nrx1,nr2,nrx2;
char s1[MaxN],s2[MaxN],s[MaxN];

void Rezolva(char *,long &,long &);

int main()
{
FILE * fin=fopen(inf,"r");
FILE * fout=fopen(outf,"w");
fscanf(fin,"%d",&N);
char *p;
for(int i=1;i<=N;i++)
    {
    fscanf(fin,"%s",&s1);
    p=strchr(s1,'=');
    strcpy(s2,p+1);
    *p=NULL;
    Rezolva(s1,nr1,nrx1);
    Rezolva(s2,nr2,nrx2);
    if(nrx1==nrx2)
        {
        if(nr1==nr2)fprintf(fout,"infinit\n");
        else fprintf(fout,"imposibil\n");
        }
    else fprintf(fout,"%.4lf\n", ((double)(nr2-nr1)/(nrx1-nrx2)) );
    }
fclose(fin);
fclose(fout);
return 0;
}

void Rezolva(char *s,long &nr,long &nrx)
{
char *p,ss[MaxN];
int semn=1,l;
long v;
strcpy(ss,s);
p=strtok(ss,"+-");
nr=0; nrx=0;
while(p)
    {
    l=strlen(p);
    if(p[0]=='x')nrx+=semn;
    else
        {
        if(p[l-1]=='x')
            {
            p[l-1]=NULL;
            v=atol(p);
            nrx=nrx+semn*v;
            }
        else
            {
            v=atol(p);
            nr=nr+v*semn;
            }
        }
    if(s[p+l-ss]=='+')semn=1;
    else semn=-1;
    p=strtok(NULL,"+-");
    }
}

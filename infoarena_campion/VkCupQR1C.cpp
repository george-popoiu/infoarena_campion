#include<stdio.h>
#include<string>
#include<string.h>
#include<list>
#define inf "test.in"
#define outf "test.out"
#define lsit list<string>::iterator
using namespace std;

char dir[500][500], aux[500][500];
int top;
int n;
char c[210];

void solve()
{
    scanf("%d", &n); gets(c);
    for(int i=1; i<=n; i++) {
        gets(c);
        if( c[0]=='c' ) {
            if( c[3]=='/' ) top = 0;

            //get all directories
            char *p = strtok(c+3, "/");
            while( p!=NULL ) {
                memset( dir[top], NULL, sizeof(dir[top]) );
                strcpy( dir[top++], p);
                p = strtok(NULL, "/");
            }

            //process the path
            int pass = 0, j = 0;
            for(int i=top-1; i>=0; i--) {
                if( dir[i][0]=='.' ) pass++;
                else if( pass>0 ) pass--;
                else {
                    memset( aux[j], NULL , sizeof(aux[j]) );
                    strcpy( aux[j++], dir[i] );
                }
            }

            //create the final path
            top = 0;
            for(int i=j-1; i>=0; i--) {
                memset( dir[top], NULL, sizeof(dir[top]) );
                strcpy( dir[top++], aux[i] );
            }
        }
        else {
            printf("/");
            for(int i=0; i<top; i++) printf("%s/", dir[i]);
            printf("\n");
        }
    }
}

int main()
{
	//freopen(inf,"r",stdin); freopen(outf,"w",stdout);
	solve();
	return 0;
}

# include <cstdio>
# include <cstring>

const char *FIN = "brad.in", *FOU = "brad.out";
const int MAX = 100005;

int N, viz[MAX];

int main (void) {
    fscanf (fopen (FIN, "r"), "%d", &N);

    freopen (FOU, "w", stdout);
    viz[1] = 1;
    /*for (int j = 1; j <= N; ++j)
            printf ("%c", viz[j] ? '*' : 'x');
        printf ("\n");*/
    printf ("1\n");
    for (int i = 2; i <= N; ++i) {
        for (int j = 1; j <= i; ++j) {
            if (viz[j]) continue;
            if (viz[j - 1] == 1 && viz[j + 1] != 1 || viz[j - 1] != 1 && viz[j + 1] == 1)
                viz[j] = 2;
        }
        for (int j = 1; j <= i; ++j)
            if (viz[j] == 1) viz[j] = 0;
            else if (viz[j] == 2) viz[j] = 1;
        int sol = 0;
        for (int j = 1; j <= N; ++j)
            if (viz[j]) ++sol;
        printf ("%d\n", sol);
        /*for (int j = 1; j <= N; ++j)
            printf ("%c", viz[j] ? '*' : 'x');
        printf ("\n");*/
    }
}

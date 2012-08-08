#include <cstdio>
#include <string>
#include <cstring>
#define maxn 1010

using namespace std;


int D[9000][maxn];

int sol = 0;
int main ()
{


        freopen ("morcovi.in", "r", stdin);
        freopen ("morcovi.out", "w", stdout);
        int A[maxn], C[maxn], P, n;
        int i, j, k, m;
        scanf ("%d\n", &n);

        for (i = 1; i <= n; i++)
                scanf ("%d", &A[i]);

        scanf ("%d\n", &P);

        for (i = 0; i < P; i++)
                scanf ("%d", &C[i]);

        for (i = 1; i <= n; i++)
                D[0][i] = A[i];
        for (j = 1; j < (1 << P); j++)
                for (i = 1; i <= n; i++)
                        for (k = 0; k < P; k++)
                                if (j & (1 << k))
                                {
                                        int c = j ^ (1 << k);
                                        if (i - C[k] > 0)
                                                D[j][i] = max (D[j][i], D[c][i - C[k]] + A[i]);

                                        if (i + C[k] <= n)
                                                D[j][i] = max (D[j][i], D[c][i + C[k]] + A[i]);
                                }


        m = (1 << P) - 1;

        for (int i = 1; i <= n; i++)
                sol = max (D[m][i], sol);
        printf ("%d\n", sol);

        return 0;
}

//#include <cstdio>
#include<fstream>
#include <string>
#define maxnn 200005
#define maxn 1 << 19
#define mid ((st + dr) >> 1)
#define fs (mid << 1)
#define fd ((mid << 1) + 1)
#define ll long long
using namespace std;

fstream f("maxq.in",ios::in), g("maxq.out",ios::out);

ll S[maxn], A[maxn], B[maxn], C[maxn], sol;
int V[maxnn];
void build (int nod, int st, int dr)
{
        if (st == dr)
        {
//              printf ("%d ", st);
                S[nod] = V[st];
                A[nod] = max (V[st], 0);
                B[nod] = C[nod] = A[nod];
                return ;
        }

        build (fs, st, mid);
        build (fd, mid + 1, dr);

        S[nod] = S[fs] + S[fd];
        A[nod] = max (A[fd] + S[fs], A[fs]);
        B[nod] = max (B[fs] + S[fd], B[fd]);
        C[nod] = max (C[fs], max (C[fd], B[fs] + A[fd]));
}

void update (int nod, int st, int dr, int poz, int val)
{
        if (st == dr)
        {
                S[nod] = val;
                A[nod] = B[nod] = C[nod] = max (val, 0);
                return ;
        }

        if (poz <= mid) update (fs, st, mid, poz, val);
        if (poz > mid)  update (fd, mid + 1, dr, poz, val);

        S[nod] = S[fs] + S[fd];
        A[nod] = max (A[fs], A[fd] + S[fs]);
        B[nod] = max (B[fd], B[fs] + S[fd]);
        C[nod] = max (C[fs], max (C[fd], B[fs] + A[fd]));
}
ll sum;
void query (int nod, int st, int dr, int poz1, int poz2)
{
        if (poz1 <= st && dr <= poz2)
        {
                if (sum < 0) sum = 0;
                sol = max (sol, C[nod]);
                sol = max (sum + A[nod], sol);
                sum = max (sum + S[nod], B[nod]);
                return;
        }
        if (poz1 <= mid) query (fs, st, mid, poz1, poz2);
        if (poz2 > mid) query (fd, mid + 1, dr, poz1, poz2);
}
int main ()
{

        int m;
        //freopen ("maxq.in", "r", stdin);
        //freopen ("maxq.out", "w", stdout);

        int n, x, y, tip;
        //scanf ("%d", &n);
        f>>n;
        for (int i = 1; i <= n; i++) {
                //scanf ("%d", &V[i]);
//              printf ("%d ", V[i]);
                f>>V[i];
        }
//      printf ("\n");

        build (1, 1, n);
        //scanf ("%d\n", &m);
        f>>m;
//      for (int i = 1; i <= 9; i++) printf ("%d %d %d\n", A[i], B[i], C[i]);
        while (m--)
        {
                //scanf ("%d%d%d\n", &tip, &x, &y);
                f>>tip>>x>>y;
                if (tip == 0) {
                        update (1, 1, n, x + 1, y);
                }
                else {
                        sol = 0;
                        sum = 0;
                        query (1, 1, n, x + 1, y + 1);
                //      sol = max (sol, 0);
                        //printf ("%lld\n", sol);
                        g<<sol<<"\n";
                }
        }
        f.close(); g.close();
        return 0;
}

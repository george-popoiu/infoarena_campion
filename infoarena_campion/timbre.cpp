# include <algorithm>
# include <cstdio>
# include <queue>
using namespace std;

const char *FIN = "timbre.in", *FOU = "timbre.out";

struct comp {
    bool operator () (const int &x, const int &y) {
        return x > y;
    }
};

priority_queue <int, vector <int>, comp> Q;
pair <int, int> V[10005];
int N, M, K, sol;

int main (void) {
    freopen (FIN, "r", stdin);
    freopen(FOU, "w", stdout);

    scanf ("%d %d %d", &N, &M, &K);
    for (int i = 1; i <= M; ++i)
        scanf ("%d %d", &V[i].first, &V[i].second);

    sort (V + 1, V + M + 1, greater < pair <int, int> > ());

    for(int i=1; i<=M; i++)
        printf("%d %d\n", V[i].first, V[i].second);

    for (int i = 1, j = N; j > 0; Q.pop (), j -= K) {
        for (; V[i].first >= j && i <= M; ++i)
            Q.push (V[i].second);
        sol += Q.top ();
    }
    printf("%d", sol);
}

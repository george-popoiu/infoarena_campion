#include <stdio.h>
#include <algorithm>

using namespace std;

#define NMax 100005

int N, Res[NMax], v[NMax], lst[NMax], D[NMax], AIB[NMax], bst, up[NMax];

void update(int x, int ind)
{
	for (; x <= N; x += x^(x-1) & x)
		if (D[ind] > D[AIB[x]])
			AIB[x] = ind;
}

int query(int x)
{
	int mx = 0;

	for (; x; x -= x^(x-1) & x)
		if (D[AIB[x]] > D[mx])
			mx = AIB[x];
	return mx;
}

int main(void)
{
	int i, h = 1;

	freopen("scmax.in", "r", stdin);
	freopen("scmax.out", "w", stdout);

	scanf("%d", &N);
	for (i = 1; i <= N; ++i)
	{
		scanf("%d", &v[i]);
		Res[i] = lst[i] = v[i];
	}

	sort(lst+1, lst+N+1);
	for (i = 2; i <= N; ++i)
		if (lst[i] != lst[h])
			lst[++h] = lst[i];

	for (i = 1; i <= N; ++i)
		v[i] = lower_bound(lst+1, lst+h+1, v[i])-lst;

	for (i = 1; i <= N; ++i)
	{
		up[i] = query(v[i]-1);
		D[i] = D[up[i]] + 1;
		update(v[i], i);
	}

	for (i = 1; i <= N; ++i)
		if (D[bst] < D[i])
			bst = i;

	printf("%d\n", D[bst]);
	for (h = 0, i = bst; i; i = up[i])
		lst[++h] = Res[i];

	for (i = h; i; --i)
		printf("%d ", lst[i]);
	printf("\n");

	return 0;
}


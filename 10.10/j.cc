#include <bits/stdc++.h>

using namespace std;

namespace jspace
{

typedef long long int ll;
typedef double jfloat;
const jfloat eps = 1e-8;

const int maxn = 1 << 10;

int N, W, L;
bitset<maxn> vis;

int f[maxn], lb[maxn], rb[maxn];

inline void mkchd(int fa, int chd)
{
	lb[fa] = min(lb[fa], lb[chd]);
	rb[fa] = max(rb[fa], rb[chd]);
	f[chd] = fa;
}
int fdr(int x)
{
	if (x == f[x]) return x;
	int rt = fdr(f[x]);
	mkchd(rt, x);
	return rt;
}
void uni(int i, int j)
{
	int fi = fdr(i), fj = fdr(j);
	mkchd(fi, fj);
}

int x[maxn], y[maxn], r[maxn];

inline ll sq(ll x) { return x * x; }

bool intersect(int i, int j)
{
	ll dx = x[i] - x[j], dy = y[i] - y[j];
	ll d2 = sq(dx) + sq(dy);
	ll dr = r[i] - r[j], sr = r[i] + r[j];
	return (sq(dr) <= d2 && d2 <= sq(sr));
}

void clear(void)
{
	vis.reset();
	for (int i = 0; i < N; i++) f[i] = i;
}

void main(void)
{
	int ans = 0;
	scanf("%d%d%d", &N, &W, &L);
	clear();
	for (int i = 0; i < N; i++)
	{
		scanf("%d%d%d", x + i, y + i, r + i);
		lb[i] = x[i] - r[i];
		rb[i] = x[i] + r[i];
	}
	for (int i = 0; i < N; i++)
		for (int j = i + 1; j < N; j++)
		{
			if (intersect(i, j))
				uni(i, j);
		}
	for (int i = 0; i < N; i++)
	{
		int rt = fdr(i);
		if (!vis.test(rt))
		{
			ans += (lb[rt] <= 0 && W <= rb[rt]);
			vis.set(rt);
		}
	}
	printf("%d\n", ans);
}

}

int main(void)
{
	int T;
	scanf("%d", &T);
	while (T--) jspace::main();
	return 0;
}


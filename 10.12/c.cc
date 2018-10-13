#include <bits/stdc++.h>

using namespace std;

typedef double jf;
const jf inf = 1e9;
const jf eps = 1e-8;

namespace sap {

const int MAXEDGE = 50000;
const int MAXN = 20000;

struct edges {
	jf cap, flow;
	int to, next;
} edge[MAXEDGE + 100];
struct nodes {
	int head, label, pre, cur;
} node[MAXN + 100];

int L, N;
int gap[MAXN + 100];
void init(int n) {
	L = 0;
	N = n;
	for (int i = 0; i < N; i++)
		node[i].head = -1;
}

void add_edge(int x, int y, jf z, jf w = 0.) {
	edge[L].cap = z;
	edge[L].flow = 0.;
	edge[L].to = y;
	edge[L].next = node[x].head;
	node[x].head = L++;
	edge[L].cap = w;
	edge[L].flow = 0.;
	edge[L].to = x;
	edge[L].next = node[y].head;
	node[y].head = L++;
}

jf maxflow(int s, int t) {
	memset(gap, 0, sizeof gap);
	gap[0] = N;
	int u; jf ans = 0.;
	for (int i = 0; i < N; i++) {
		node[i].cur = node[i].head;
		node[i].label = 0;
	}
	u = s;
	node[u].pre = -1;
	while (node[s].label < N) {
		if (u == t) {
			jf min = inf;
			for (int i = node[u].pre; i != -1; i = node[edge[i^1].to].pre)
				if (min > edge[i].cap - edge[i].flow + eps)
					min = edge[i].cap - edge[i].flow;
			for (int i = node[u].pre; i != -1; i = node[edge[i^1].to].pre) {
				edge[i].flow += min;
				edge[i^1].flow -= min;
			}
			u = s;
			ans += min;
			continue;
		}
		bool flag = false;
		int v;
		for (int i = node[u].cur; i != -1; i = edge[i].next) {
			v = edge[i].to;
			if (edge[i].cap - edge[i].flow > eps && node[v].label + 1 == node[u].label) {
				flag = true;
				node[u].cur = node[v].pre = i;
				break;
			}
		}
		if (flag) {
			u = v;
			continue;
		}
		node[u].cur = node[u].head;
		int min = N;
		for (int i = node[u].head; i != -1; i = edge[i].next)
			if (edge[i].cap - edge[i].flow > eps && node[edge[i].to].label < min)
				min = node[edge[i].to].label;
		gap[node[u].label]--;
		if (!gap[node[u].label]) return ans;
		node[u].label = min + 1;
		gap[node[u].label]++;
		if (u != s) u = edge[node[u].pre ^ 1].to;
	}
	return ans;
}

}

namespace jspace {

const int maxn = 1 << 7;
int n;
int p[maxn];
int m, e[maxn * maxn][2];
int tot;

void clear(void)
{
	m = 0;
}

#define Src (tot - 1)
#define Snk (tot - 2)
#define VTX(v) (v)
#define EDGE(e) (n + e + 1)
bool check(jf mid)
{
	sap::init(tot);
	for (int i = 1; i <= m; i++)
	{
		sap::add_edge(Src, EDGE(i), 1.);
		sap::add_edge(EDGE(i), VTX(e[i][0]), inf);
		sap::add_edge(EDGE(i), VTX(e[i][1]), inf);
	}
	for (int i = 1; i <= n; i++)
	{
		sap::add_edge(VTX(i), Snk, mid);
	}
	jf f = sap::maxflow(Src, Snk);
	return (1. * m - f) < eps;
}

void proc(void)
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", p + i);
	for (int i = 1; i < n; i++)
		for (int j = i + 1; j <= n; j++)
		{
			if ( p[i] > p[j] )
			{
				m++;
				e[m][0] = i;
				e[m][1] = j;
			}
		}
	tot = n + m + 16;
	jf l = 0., r = 1. * m;
	while (r - l > 1e-6)
	{
		jf mid = (l + r) * .5;
		if (check(mid)) r = mid;
		else l = mid;
	}
	printf("%.8lf\n", l);
}

int casid;
void main(void)
{
	clear();
	printf("Case #%d: ", ++casid);
	proc();
}

}

int main(void)
{
	int T;
	scanf("%d", &T);
	while (T--) jspace::main();
	return 0;
}

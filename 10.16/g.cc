#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
#define pb push_back

namespace graph {

const int maxn = 1 << 9;
const int maxe = maxn << 4;
const int inf = 0x3f3f3f3f;

int n;
vi g[maxn];

void init(int N)
{
	n = N;
	for (int i = 0; i < n; i++) g[i].clear();
}

void add_edge(int u, int v)
{
	g[u].pb(v);
	g[v].pb(u);
}

int d[maxn];
int sp(int s, int t)
{
	queue<int> q;
	memset(d, 0xff, sizeof d);
	d[s] = 0;
	q.push(s);
	while (!q.empty())
	{
		int u = q.front(); q.pop();
		for (auto v : g[u])
		{
			if (d[v] == -1)
			{
				d[v] = d[u] + 1;
				if (v == t) return d[t];
				q.push(v);
			}
		}
	}
	return d[t];
}

}

namespace jspace {

typedef double jf;
const jf eps = 1e-8;
const int maxn = 1 << 5;

/* return -1 for a < b, 0 for a == b, 1 for a > b */
int jcmp(jf a, jf b = 0.)
{
	if (fabs(a - b) < eps) return 0;
	return (a < b) ? (-1) : 1;
}

struct point
{
	jf x, y;
	point(jf xx = jf(), jf yy = jf()) : x(xx), y(yy) {}
	void scan(void)
	{
		scanf("%lf%lf", &x, &y);
	}
	point operator*(const jf k) const { return point(k * x, k * y); }
	point operator/(const jf k) const { return point(x / k, y / k); }
	point operator+(const point &b) const { return point(x + b.x, y + b.y); }
	point operator-(const point &b) const { return point(x - b.x, y - b.y); }
	jf operator*(const point &b) const { return x * b.x + y * b.y; }
	jf operator^(const point &b) const { return x * b.y - b.x * y; }
	point operator->*(const point &b) const { return b - (*this); }
};

struct segment
{
	point a, b;
	point ab;
	segment(point s = point(), point t = point()) : a(s), b(t) { ab = s->*t; }
	bool include(const point &P) const
	{
		return (0 == jcmp((a->*P) ^ (a->*b))) && (-1 == jcmp((a->*P) * (b->*P)));
	}
	bool parallel(const segment &l) const
	{
		return !jcmp((b->*a) ^ ((l.b)->*(l.a)));
	}
	bool intersect(const segment l) const
	{
		if (parallel(l)) return false;
		// jf s1 = (a - l.a) ^ (l.ab);
		// jf s2 = (b - l.a) ^ (l.ab);
		// point x = ((b * s1) - (a * s2)) / (s1 - s2);
		// return include(x) && l.include(x);
		jf c1 = ab ^ (l.a - a), c2 = ab ^ (l.b - a);
		jf c3 = (l.ab) ^ (a - l.a), c4 = (l.ab) ^ (b - l.a);
		return jcmp(c1) * jcmp(c2) < 0 && jcmp(c3) * jcmp(c4) < 0;
	}
};


const int d[][2] = {
	{-1, 0},
	{-1, -1},
	{0, -1},
	{-1, 1},
};

int n;
point tri[5];
char gird[maxn][maxn];
int id[maxn][maxn], node_cnt;

bool in_triangle(point P)
{
	int sign[3];
	for (int i = 0; i < 3; i++)
	{
		sign[i] = jcmp((P->*(tri[i])) ^ (P->*(tri[i + 1])));
		if (0 == sign[i]) return false;
	}
	return (sign[0] == sign[1] && sign[0] == sign[2]);
}

void debug(void)
{
	return;
	point A(0,0), B(3,0), C(3,3);
	tri[0] = A; tri[1] = B; tri[2] = C;
	tri[3] = A;
	point D(0,0), E(3,1.5);
	printf("%d,%d,%d\n", in_triangle(D), in_triangle(E), in_triangle((D+E)*0.5));
	segment DE(D, E);
	printf("%d,%d,%d\n",
		DE.intersect(segment(A,B)),
		DE.intersect(segment(B,C)),
		DE.intersect(segment(C,A))
	);
	exit(0);
}

bool check(int ai, int aj, int bi, int bj)
{
	// point A(n - 1 - ai, aj), B(n - 1 - bi, bj);
	point A(aj, n - 1 - ai), B(bj, n - 1 - bi);
	if (in_triangle(A) || in_triangle(B)) return false;
	point M = (A + B) * 0.5;
	if (in_triangle(M)) return false;
	point unit = (B - A) / 100., delta = unit;
	for (int i = 0; i < 100; i++)
	{
		if (in_triangle(A + delta)) return false;
		delta = delta + unit;
	}
	segment AB(A, B);
	for (int i = 0; i < 3; i++)
		if (AB.intersect(segment(tri[i], tri[i + 1])))
			return false;
	return true;
}

void clear(void)
{
	node_cnt = 0;
	graph::init(n * n + 10);
}

int main(void)
{
	if (EOF == scanf("%d", &n)) return 0;
	clear();
	for (int i = 0; i < 3; i++) tri[i].scan(); tri[3] = tri[0]; tri[4] = tri[1];
	for (int i = 0; i < n; i++)
		scanf("%s", gird[i]);
	if ('#' == gird[n - 1][0] || '#' == gird[0][n - 1])
	{
		puts("-1");
		return 1;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if ('#' == gird[i][j]) continue;
			id[i][j] = node_cnt++;
			for (int k = 0; k < 4; k++)
			{
				int ti = i + d[k][0], tj = j + d[k][1];
				if (ti < 0 || ti >= n) continue;
				if (tj < 0 || tj >= n) continue;
				if ('#' == gird[ti][tj]) continue;
				if (check(i, j, ti, tj)) graph::add_edge(id[i][j], id[ti][tj]);
			}
		}
	}
	printf("%d\n", graph::sp(id[n - 1][0], id[0][n - 1]));
	return 1;
}

}

int main(void)
{
	jspace::debug();
	while (jspace::main());
	return 0;
}

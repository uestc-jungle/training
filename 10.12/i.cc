#include <bits/stdc++.h>

using namespace std;

namespace jspace {

typedef pair<int,int> pii;
typedef vector<int> vi;
#define mp make_pair
#define fi first
#define se second
#define pb push_back

const int maxn = 30303;
const int maxm = maxn << 6;

/* pos indexed from 0 */
inline int get(int s, int pos) { return (1 & (s >> (31 - pos))); }

int casid;

int n;

struct vtx
{
	bool t;	/* termination */
	vtx *ch[2];
}vtxs[maxm + 128];
int used_vtx;
vtx *new_vtx(void)
{
	vtx *ret = vtxs + (used_vtx++);
	ret->t = false;
	ret->ch[0] = ret->ch[1] = NULL;
	return ret;
}

void add(vtx *rt, int s, int len)
{
	for (int i = 0; i < len; i++)
	{
		int d = get(s, i);
		if (NULL == rt->ch[d])
		{
			rt->ch[d] = new_vtx();
		}
		rt = rt->ch[d];
	}
	rt->t = true;
}

vector<pii> ans;

void go(vtx *rt, int prefix = 0, int len = 0)
{
	if (rt->t) return;
	++len;
	for (int d = 0; d < 2; d++)
	{
		int current = (prefix << 1) | d;
		if (rt->ch[d])
		{
			go(rt->ch[d], current, len);
		} else {
			ans.pb(mp(current, len));
		}
	}
}

void clear(void)
{
	used_vtx = 0;
	ans.clear();
}

void proc(void)
{
	scanf("%d", &n);
	if (0 == n)
	{
		puts("1\n0.0.0.0/0");
		return;
	}
	vtx *root = new_vtx();
	while (n--)
	{
		int a, b, c, d, l;
		scanf("%d.%d.%d.%d/%d", &a, &b, &c, &d, &l);
		int subnet = (a << 24) | (b << 16) | (c << 8) | d;
		add(root, subnet, l);
	}
	go(root);
	unsigned sz = ans.size();
	printf("%u\n", sz);
	for (auto sn : ans)
	{
		int l = sn.se;
		int subnet = (sn.fi) << (32 - l);
		printf("%d.%d.%d.%d/%d\n",
			(subnet >> 24) & 0xff,
			(subnet >> 16) & 0xff,
			(subnet >> 8) & 0xff,
			subnet & 0xff,
			l
		);
	}
}

void main(void)
{
	printf("Case #%d:\n", ++casid);
	clear();
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

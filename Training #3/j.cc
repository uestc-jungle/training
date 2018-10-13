/* jungle training #3 */
#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

namespace wkspace
{

const int thre = 31623;

ll gcd(ll m, ll n) { return (0 == n) ? m : gcd(n, m % n); }

ll a, b, c, d, p, m;

/* numbers upto bound which remainder is r upon division by p */
inline ll f(ll bound, ll r)
{
	return (bound < r) ? 0 : ((bound - r) / p + 1);
}

inline ll jadd(ll const a, ll const b)
{
	ll z = a + b;
	if (z >= p) z -= p;
	return z;
}

ll f1[thre + 128], f2[thre + 128];

void proc(void)
{
	static int cid;
	static ll cnt, tot, g;
	scanf("%lld%lld%lld%lld%lld%lld", &a, &b, &c, &d, &p, &m);
	cnt = 0;
	tot = (b - a + 1ll) * (d - c + 1ll);
	if (p < thre)
	{
		for (int i = 0; i < p; i++)
		{
			f1[i] = f(b, i) - f(a - 1, i);
			f2[i] = f(d, i) - f(c - 1, i);
		}
		for (int i = 0; i < p; i++)
			cnt += f1[i] * f2[jadd(m, p - i)];
	}
	else
	{
		for (; m <= b+d; m += p)
		{
			ll l = max(m - b, c), r = min(m - a, d);
			cnt += max(r - l + 1ll, 0ll);
		}
	}
	g = gcd(cnt, tot);
	cnt /= g; tot /= g;
	if (0 == cnt) tot = 1;
	printf("Case #%d: %lld/%lld\n", ++cid, cnt, tot);
}

}

int main(void)
{
	int T;
	scanf("%d", &T);
	while(T--) wkspace::proc();
    return 0;
}


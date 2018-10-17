#include <bits/stdc++.h>

using namespace std;

namespace jspace {

typedef long long int ll;
typedef double jf;

const int maxr = 70;

ll r, k; jf p, np;

unordered_map<ll, jf> dp[maxr];
/* f for p >= 0.5 */
jf f(int r, ll k)
{
	if (1 == r) return (1 == k) ? p : np;
	auto it = dp[r].find(k);
	if (it != dp[r].end()) return it->second;
	jf ans = 0.;
	if (1 == k)
	{
		ans = p * f(r - 1, 1);
	} else if (k == (1ll<<r)) {
		ans = np * f(r - 1, 1ll<<(r - 1));
	} else {
		ans = p;
		if (1 & k)
		{
			ans *= f(r - 1, ((k ^ 1) >> 1) + 1);
		} else {
			ll base = ((k - 2ll) >> 1) + 1;
			jf case1 = p * f(r - 1, base + 1);
			jf case2 = np * f(r - 1, base);
			ans *= (case1 + case2);
		}
	}
	dp[r][k] = ans;
	return ans;
}
/* g for p < 0.5 */
jf g(int r, ll k)
{
	if (1 == r) return (1 == k) ? p : np;
	auto it = dp[r].find(k);
	if (it != dp[r].end()) return it->second;
	jf ans = 0.;
	if (1 == k)
	{
		ans = p * f(r - 1, 1);
	} else if ((1ll<<r) == k) {
		ans = np * f(r - 1, (1ll<<(r - 1)));
	} else {
		/* select whose order is higher */
		ans = np;
		if (1 & k)
		{
			ll base = ((k - 3ll) >> 1) + 1;
			jf case1 = p * f(r - 1, base + 1);
			jf case2 = np * f(r - 1, base);
			ans *= (case1 + case2);
		} else {
			ans *= f(r - 1, ((k - 2) >> 1) + 1);
		}
	}
	dp[r][k] = ans;
	return ans;
}

void main(void)
{
	scanf("%lld%lld%lf", &r, &k, &p);
	np = 1. - p;
	for (int i = 2; i <= r; i++) dp[i].clear();
	jf ans;
	if (p >= 0.5) ans = f(r, k);
	else ans = g(r, k);
	printf("%.6lf\n", ans);
}

}

int main(void)
{
	int T;
	scanf("%d", &T);
	while (T--) jspace::main();
	return 0;
}


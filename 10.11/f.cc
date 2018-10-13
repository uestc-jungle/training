#include <bits/stdc++.h>

using namespace std;

namespace jspace
{

const int maxn = 1 << 5;

typedef long long int ll;

int casid;

int n;
char str[maxn];

ll dp[maxn][maxn];

ll lct(void)
{
	ll ans = 1ll << 63;
	for (int i = 0; i < n; i++)
	{
		dp[i][i] = str[i] - '0';
		for (int j = i + 1; j < n; j++)
			dp[i][j] = dp[i][j - 1] * 10ll + (str[j] - '0');
	}
	/* pos of minus */
	for (int i = 1; i < n - 3; i++)
	{
		ll left, right;
		left = max(dp[0][0] + dp[1][i], dp[0][i - 1] + dp[i][i]);
		right = dp[i + 1][i + 1] * dp[i + 2][i + 2] / dp[i + 3][n - 1];
		ans = max(ans, left - right);
	}
	return ans;
}

void main(void)
{
	scanf("%s", str);
	n = strlen(str);
	printf("Case #%d: %lld\n", ++casid, lct());
}

}

int main(void)
{
	int T;
	scanf("%d", &T);
	while (T--) jspace::main();
	return 0;
}


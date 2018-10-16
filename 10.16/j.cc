#include <bits/stdc++.h>

using namespace std;

namespace jspace {

typedef long long int ll;

const int maxn = 1 << 7;
const ll inf = 0x3f3f3f3f3f3f3f3f;

int N, L, R;
int s[maxn][maxn];
ll f[maxn][maxn][maxn];

int main(void)
{
	if (EOF == scanf("%d%d%d", &N, &L, &R))
		return 0;
	memset(f, 0x3f, sizeof f);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &(s[i][i]));
		for (int j = i - 1; j > 0; j--)
			s[j][i] = s[j][j] + s[j + 1][i];
		f[i][i][1] = 0;
	}
	for (int w = 2; w <= N; w++)
	{
		for (int l = 1, r; (r = l + w - 1) <= N; l++)
		{
			/* k = 1 */
			for (int m = l; m < r; m++)
			{
				int upx = min(m - l + 2, R);
				for(int x = L; x <= upx; x++)
					f[l][r][1] = min(f[l][r][1], f[l][m][x - 1] + f[m + 1][r][1] + s[l][r]);
			}
			int upk = r - l + 1;
			for (int k = 2; k <= upk; k++)
			{
				for (int m = k + l - 2; m < r; m++)
					f[l][r][k] = min(f[l][r][k], f[l][m][k - 1] + f[m + 1][r][1]);
			}
		}
	}
	if (f[1][N][1] >= inf) puts("0");
	else printf("%lld\n", f[1][N][1]);
	return 1;
}

}

int main(void)
{
	while (jspace::main());
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

namespace jspace
{

typedef vector<int> vi;
#define pb push_back
typedef long long int ll;
typedef double jfloat;
const int maxn = 1 << 8;

int N, M;
int x[maxn], y[maxn], R[maxn], S[maxn];

vi available;
int check(jfloat x, jfloat y)
{
	int ret = 0;
	available.clear();
	for (int i = 0; i < N; i++)
		if (in_circle(x, y, i))
			available.pb(S[i]);
	sort(available.begin(), available.end();
	for (int i = 0; i < N && i < M; i++)
		ret += available[i];
	return ret;
}

void main(void)
{
	int ans = 0;
	scanf("%d%d", &N, &M);
	for (int i = 0; i < N; i++)
		scanf("%d%d%d%d", x + i, y + i, R + i, S + i);
	for (int i = 0; i < N; i++)
		ans = max(ans, check(x[i], y[i]));
	for (int i = 0; i < N; i++)
		for (int j = i + 1; j < N; j++)
		{
			;
		}
}

};

int main(void)
{
	int T;
	scanf("%d", &T);
	while (T--) jspace::main();
	return 0;
}


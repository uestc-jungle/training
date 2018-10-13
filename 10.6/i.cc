#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
const int maxn = 50050, maxk = (1 << 7);
const int p = (1e9 + 7);

inline int jadd(const int a, const int b)
{
    ll z = 0ll + a + b;
    if (z < 0ll) z += p;
    if (z >= p) z -= p;
    return z;
}
inline int jmul(const int a, const int b)
{
    ll z = 1ll * a * b;
    z -= z / p * p;
    return z;
}

struct jinit1
{
    int d[maxk][maxk];
    jinit1(void)
    {
        d[0][0] = 1;
        for (int i = 1; i < maxk; i++)
        {
            d[i][0] = d[i][i] = 1;
            for (int j = 1; j < i; j++)
                d[i][j] = jadd(d[i - 1][j - 1], d[i - 1][j]);
        }
    }
    int *operator[](unsigned pos) { return d[pos]; }
}bi;

int N, k;
char S[maxn];
int T[maxn];
int Tp[maxn][maxk];
int Ts[maxk];
int g[maxn];

void proc()
{
    scanf("%d%d", &N, &k);
    scanf("%s", S + 1);
    T[0] = 0; Tp[0][0] = 1;
    for (int i = 1; i <= N; i++)
    {
        T[i] = jadd(T[i - 1], S[i] - '0');
        Tp[i][0] = 1;
        for (int r = 1; r <= k; r++)
            Tp[i][r] = jmul(Tp[i][r - 1], T[i]);
    }
    for (int r = 0; r <= k; r++) Ts[r] = 0;
    for (int i = 1; i <= N; i++)
    {
        g[i] = 0;
        for (int r = 0; r <= k; r++)
        {
            Ts[r] = jadd(Ts[r], Tp[i - 1][r] * ((1 & r) ? (-1) : (1)));
            g[i] = jadd(g[i], jmul(bi[k][r], jmul(Tp[i][k - r], Ts[r])));
        }
    }
    for (int i = 1; i <= N; i++)
        printf("%d%c", g[i], " \n"[i == N]);
}

int main(void)
{
    int T;
    scanf("%d", &T);
    while (T--) proc();
    return 0;
}

#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
#define pb push_back

const int maxn = 100100;
const int maxlg = 20;

int N, Q;
vi g[maxn];

int counter;
int lu[maxn], ru[maxn];
int d[maxn];
int f[maxn][maxlg];

void dfs(int u, int fa = 0)
{
    lu[u] = ++counter;
    u[d] = fa[d] + 1;
    f[u][0] = fa;
    for (auto v : g[u])
        if (v != fa)
            dfs(v, u);
    ru[u] = counter;
}

void buildlca(void)
{
    for (int i = 1; i < maxlg; i++)
    {
        for (int u = 1; u <= N; u++)
        {
            if (d[u] > (1 << i))
            {
                f[u][i] = f[ f[u][i - 1] ][i - 1];
            }
        }
    }
}

int lca(int u, int v)
{
    if (d[u] < d[v]) swap(u, v);
    for (int i = maxlg - 1; (d[u] > d[v]) && i >= 0; i--)
    {
        if ( d[u] - (1 << i) >= d[v] )
            u = f[u][i];
    }
    assert(d[u] == d[v]);
    if (u == v) return u;
    for (int i = maxlg - 1; i >= 0; i--)
    {
        if (d[u] - (1 << i) > 0 && (f[u][i] != f[v][i]))
        {
            u = f[u][i];
            v = f[v][i];
        }
    }
    assert(f[u][0] == f[v][0]);
    return f[u][0];
}

int is_ans(int u, int v)
{
    /* return if u is ancestor of v */
    return ((lu[u] <= lu[v]) && (ru[v] <= ru[u]));
}

int dis(int u, int v)
{
    return d[u] + d[v] - (d[ lca(u,v) ] << 1);
}

void jinit(void)
{
    dfs(1);
    buildlca();
}

int main(void)
{
    scanf("%d%d", &N, &Q);
    for (int i = 1; i < N; i++)
    {
        int U, V;
        scanf("%d%d", &U, &V);
        g[U].pb(V); g[V].pb(U);
    }
    jinit();
    while (Q--)
    {
        static int A, B, C, D;
        static int lAB, lCD;
        int ans = 0;
        scanf("%d%d%d%d", &A, &B, &C, &D);
        lAB = lca(A, B); lCD = lca(C, D);
        if (lAB == lCD)
        {
            ans = 1 + max( dis(lca(A,C), lca(B,D)) , dis(lca(A,D), lca(B,C)) );
        } else {
            if ((!is_ans(lAB, lCD)) && (!is_ans(lCD, lAB)))
            {
                ans = 0;
            } else {
                if (is_ans(lCD, lAB))
                {
                    swap(lAB, lCD);
                    swap(A, C); swap(B, D);
                }
                for (int i = 0; i < 2; i++)
                {
                    int lAC = lca(A, C), lAD = lca(A, D);
                    if (is_ans(lCD, lAC))
                        ans = max(ans, dis(lCD, lAC) + 1);
                    if (is_ans(lCD, lAD))
                        ans = max(ans, dis(lCD, lAD) + 1);
                    swap(A, B);
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
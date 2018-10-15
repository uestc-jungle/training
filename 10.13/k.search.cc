#include <bits/stdc++.h>

using namespace std;

namespace jspace {

#define pb push_back
typedef vector<int> vi;
const int maxn = 1 << 5;

int n, p;
int color[maxn];
int adj[maxn][maxn];
vi g[maxn];
int ans;

#define jor(i,s,t) for (int i = s; i < t; i++)

void dfs(int u)
{
    if (ans) return;
    for (auto v : g[u])
        if (v < u && color[v] == color[u])
            return;
    if (n - 1 == u)
    {
        ans = 1;
        return;
    }
    for (int c = 0; c < 3; c++)
    {
        if (adj[u][u + 1] && c == color[u]) continue;
        color[u + 1] = c;
        dfs(u + 1);
        if (ans) return;
    }
}

void clear(void)
{
    ans = 0;
    memset(adj, 0, sizeof adj);
    jor(i, 0, n) g[i].clear();
}
void proc(void)
{
    scanf("%d%d", &n, &p);
    clear();
    while (p--)
    {
        int i, j;
        scanf("%d%d", &i, &j);
        adj[i][j] = adj[j][i] = 1;
        g[i].pb(j); g[j].pb(i);
    }
    color[0] = 0;
    dfs(0);
    putchar("NY"[ans]); puts("");
}

void main(void)
{
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

#include <bits/stdc++.h>

using namespace std;

int J_T_LIMIT;

namespace sap
{

const int MAXEDGE = 40400;
const int MAXN = (1 << 11);
const int inf = 0x3fffffff;
struct edges {
    int cap, to, next, flow;
    int t;
} edge[MAXEDGE + 100];
struct nodes {
    int head, label, pre, cur;
} node[MAXN + 100];
int L, N;
int gap[MAXN + 100];

void init(int n) {
    L = 0;
    N = n;
    for (int i = 0; i < N; i++)
        node[i].head = -1;
}
void add_edge(int x, int y, int t, int z, int w = 0) {
    edge[L].cap = z;
    edge[L].flow = 0;
    edge[L].to = y;
    edge[L].next = node[x].head;
    edge[L].t = t;
    node[x].head = L++;
    edge[L].cap = w;
    edge[L].flow = 0;
    edge[L].to = x;
    edge[L].next = node[y].head;
    edge[L].t = t;
    node[y].head = L++;
}

int maxflow(int s, int t) {
    memset(gap, 0, sizeof gap);
    gap[0] = N;
    int u, ans = 0;
    for (int i = 0; i < N; i++) {
        node[i].cur = node[i].head;
        node[i].label = 0;
    }
    u = s;
    node[u].pre = -1;
    while (node[s].label < N) {
        if (u == t) {
            int min = inf;
            for (int i = node[u].pre; i != -1; i = node[edge[i^1].to].pre) if (edge[i].t <= J_T_LIMIT) {
                if (min > edge[i].cap - edge[i].flow)
                    min = edge[i].cap - edge[i].flow;
            }
            for (int i = node[u].pre; i != -1; i = node[edge[i^1].to].pre) if (edge[i].t <= J_T_LIMIT) {
                edge[i].flow += min;
                edge[i^1].flow -= min;
            }
            u = s;
            ans += min;
            continue;
        }
        bool flag = false;
        int v;
        for (int i = node[u].cur; i != -1; i = edge[i].next) if (edge[i].t <= J_T_LIMIT) {
            v = edge[i].to;
            if (edge[i].cap - edge[i].flow && node[v].label + 1 == node[u].label) {
                flag = true;
                node[u].cur = node[v].pre = i;
                break;
            }
        }
        if (flag) {
            u = v;
            continue;
        }
        node[u].cur = node[u].head;
        int min = N;
        for (int i = node[u].head; i != -1; i = edge[i].next) if (edge[i].t <= J_T_LIMIT) {
            if (edge[i].cap - edge[i].flow && node[edge[i].to].label < min)
                min = node[edge[i].to].label;
        }
        gap[node[u].label]--;
        if (!gap[node[u].label]) return ans;
        node[u].label = min + 1;
        gap[node[u].label]++;
        if (u != s) u = edge[node[u].pre^1].to;
    }
    return ans;
}

}

int P, R, C;
int sum;

int tot;
#define Pu(p)   (p)
#define Ru(r)   (P + (r))
#define Src (tot - 1)
#define Sink (tot - 2)

int main(void)
{
    scanf("%d%d%d", &P, &R, &C);
    sap::init(tot = P + R + 10);
    for (int i = 1; i <= P; i++)
    {
        static int Di;
        scanf("%d", &Di);
        sum += Di;
        sap::add_edge(Pu(i), Sink, 0, Di);
    }
    for (int i = 1; i <= R; i++)
    {
        static int Ei;
        scanf("%d", &Ei);
        sap::add_edge(Src, Ru(i), 0, Ei);
    }
    while (C--)
    {
        static int I, J, T;
        scanf("%d%d%d", &I, &J, &T);
        sap::add_edge(Ru(J), Pu(I), T, sap::inf);
    }
    int ans = -1;
    int l = 1, r = 1e6;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        J_T_LIMIT = mid;
        int f = sap::maxflow(Src, Sink);
        if (f == sum)
        {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    printf("%d\n", ans);
    return 0;
}

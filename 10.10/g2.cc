#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int maxn = 301010;
const int maxe = (maxn << 1);
struct Edge{
    int tx; Edge *n;
    int val;
    Edge(int ttx=0, int ttv=0):tx(ttx), val(ttv), n(NULL){}
}E[maxe + 128];
int ecnt;
Edge *front[maxn];
struct Node{
    int num, val;
    bool operator < (const Node &tx)const{
        return val < tx.val;
    }
}a[maxn];
int n, q, rem[maxn], vis[maxn], cnt, T;
void glear(void)
{
    ecnt = 0;
    // memset(front, 0, (min(n + 10, maxn)) * (sizeof(Edge *)));
    for (int i = 0; i <= n; i++) i[front] = NULL;
}
void addedge(int u, int v, int val)
{
    E[ecnt] = Edge(v, val);
    E[ecnt].n = u[front];
    u[front] = E + ecnt;
    ecnt++;
}
// vector<Edge> v[maxn];

void dfs(int x, int fval){
    vis[x] = T+1; 
    int minv = 0 /*, siz = v[x].size()*/, tp = 0;
    for (Edge *e = x[front]; e; e = e->n)
    {
        int w = e->val;
        if (minv < w && fval > w && vis[e->tx] != T+1) {
            minv = w; tp = e->tx;
        }
    }
    // for(int i = 0; i < siz; i ++){ // 减去子树
    //     if(minv < v[x][i].val && fval > v[x][i].val){
    //         minv = v[x][i].val; tp = v[x][i].tx;
    //     }
    // }
    
    for (Edge *e = x[front]; e; e = e->n) {
        int v = e->tx, w = e->val;
        if (vis[v] == T+1) continue;
        if (fval > w) continue;
        dfs(v, w);
    }
    // for(int i = 0; i < siz; i ++){
    //     if(vis[v[x][i].tx] == T+1) continue;
    //     if(fval > v[x][i].val) continue;
    //     dfs(v[x][i].tx, v[x][i].val);
    // }
    
    if(tp){
        dfs(tp, fval);
    }
    else{
        ++ cnt; 
        a[cnt].num = x;
        a[cnt].val = fval;
    }
}

struct inputplugin
{
    inline inputplugin &operator()(int &x)
    {
        x = 0; int ch = getchar();
        for (; ch < '0' || ch > '9'; ch = getchar());
        for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + (ch - '0');
        return (*this);
    }
}scan;

int main(){
    int x, y, tv;
    // scanf("%d", &T);
    scan(T);
    while(T --){
        scan(n)(q);
        // scanf("%d%d", &n, &q);
        // for(int i = 1; i <= n; i ++){
        //     v[i].clear();
        // }
        cnt = 0;
        for(int i = 1; i < n; i ++){
            scan(x)(y)(tv);
            // scanf("%d%d%d", &x, &y, &tv);
            addedge(x, y, tv);
            addedge(y, x, tv);
            // v[x].push_back(Edge(y, tv));
            // v[y].push_back(Edge(x, tv));
        }
        dfs(1, 0);
        // return 0;
        ll ans = 0;
        sort(a+1, a+1+cnt);
        for(int i = 0; i < q; i ++){
            scan(tv);
            // scanf("%d", &tv);
            Node ttm; ttm.val = tv;
            int ttp = lower_bound(a+1, a+1+cnt, ttm) - a - 1;
            ans += a[ttp].num;
        }
        printf("%lld\n", ans);
    }
}


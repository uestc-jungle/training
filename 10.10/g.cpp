#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int maxn = 101010;
const int inf = 1e9 + 7;
struct Edge{
    int tx, val;
    bool operator < (const Edge& tem){
        return val < tem.val;
    }
    Edge(int ttx=0, int ttv=0):tx(ttx), val(ttv){}
};
struct Node{
    int num, val;
    bool operator < (const Node &tx)const{
        return val < tx.val;
    }
}a[maxn];
int n, q, vis[maxn], cnt;
vector<Edge> v[maxn];

void dfs(int x, int fval, int maxv){
    vis[x] = 1; 
    int minv = 0, tp = 0; 
    int siz = v[x].size();
    sort(v[x].begin(), v[x].end());
    for(int i = 0; i < siz; i ++){ // 减去子树
        if(vis[v[x][i].tx]) continue;
        if(minv < v[x][i].val && fval > v[x][i].val){
            minv = v[x][i].val; tp = v[x][i].tx;
        }
    }
    int tem_maxv, maxt = maxv;
    for(int i = 0; i < siz; i ++){
        if(vis[v[x][i].tx]) continue;
        if(fval > v[x][i].val) continue;
        if(v[x][i].val > maxv) continue;
        if(i != siz - 1) tem_maxv = v[x][i+1].val;
        else tem_maxv = maxv;
        maxt = min(maxt, v[x][i].val);
        dfs(v[x][i].tx, v[x][i].val, tem_maxv);
    }
    
    if(tp){
        // assert(vis[tp]);
        dfs(tp, fval, maxt);
    }
    else{
        ++ cnt; 
        a[cnt].num = x; 
        a[cnt].val = fval; 
    }
}

struct inputplugin
{
    inputplugin &operator()(int &x)
    {
        x = 0; int ch = getchar();
        for (; ch < '0' || ch > '9'; ch = getchar());
        for (; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + (ch - '0');
        return (*this);
    }
}scan;

int main(){
    int x, y, tv, T;
    scanf("%d", &T);
    // scan(T);
    while(T --){
        // scan(n)(q);
        scanf("%d%d", &n, &q);
        for(int i = 0; i <= n; i ++){
            v[i].clear();
        }
        cnt = 0;
        for(int i = 1; i < n; i ++){
            // scan(x)(y)(tv);
            scanf("%d%d%d", &x, &y, &tv);
            v[x].push_back(Edge(y, tv));
            v[y].push_back(Edge(x, tv));
            // assert(x <= n && y <= n);
        }

        memset(vis, 0, (10+n)*sizeof(int));
        dfs(1, 0, inf);
        ll ans = 0;
        sort(a+1, a+1+cnt);
        for(int i = 1; i <= cnt; i ++){
            printf("%d - %d\n", a[i].val, a[i].num);
        }
        return 0;
        for(int i = 0; i < q; i ++){
            // scan(tv);
            scanf("%d", &tv);
            Node ttm; ttm.val = tv;
            int ttp = lower_bound(a+1, a+1+cnt, ttm) - a - 1;
            ans = (ans + a[ttp].num);
        }
        printf("%lld\n", ans);
    }
}
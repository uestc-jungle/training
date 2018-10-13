#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int maxn = 101010;
struct Edge{
    int tx, val;
    Edge(int ttx=0, int ttv=0):tx(ttx), val(ttv){}
};
struct Node{
    int num, val, flag;
    bool operator < (const Node &tx)const{
        if(flag != tx.flag) return tx.flag < flag;
        return val < tx.val;
    }

}a[maxn];
int n, q, rem[maxn], vis[maxn], cnt;
vector<Edge> v[maxn];

void dfs1(int x, int fval){ // 给点与边权值标号
    vis[x] = 1;
    a[x].val = fval, a[x].num = x, a[x].flag = false;
    int siz = v[x].size();
    for(int i = 0; i < siz; i ++){
        if(vis[v[x][i].tx]) continue;
        dfs1(v[x][i].tx, v[x][i].val);
    }
}

void dfs2(int x, int fval){
    vis[x] = 1; 
    int minv = 0, siz = v[x].size(), tp = 0;
    for(int i = 0; i < siz; i ++){ // 减去子树
        if(minv < v[x][i].val && fval > v[x][i].val){
            minv = v[x][i].val; tp = v[x][i].tx;
        }
    }
    
    for(int i = 0; i < siz; i ++){
        if(vis[v[x][i].tx]) continue;
        if(fval > v[x][i].val) continue;
        dfs2(v[x][i].tx, v[x][i].val);
    }
    
    if(tp){
        dfs2(tp, fval);
    }
    else{
        int ttp = lower_bound(rem+1, rem+1+n, fval) - rem;
        a[ttp].flag = 1; 
        a[ttp].num = x; 
        cnt ++;
    }
}

struct inputplugin
{
    inputplugin &operator()(int &x)
    {
        x = 0; int ch = getchar();
        return (*this);
    }
}scan;

int main(){
    int T, x, y, tv;
    scanf("%d", &T);
    while(T --){
        scanf("%d%d", &n, &q);
        memset(vis, 0, sizeof(vis));
        memset(rem, 0, sizeof(rem));
        for(int i = 1; i <= n; i ++){
            v[i].clear();
        }
        cnt = 0;
        for(int i = 1; i < n; i ++){
            scanf("%d%d%d", &x, &y, &tv);
            v[x].push_back(Edge(y, tv));
            v[y].push_back(Edge(x, tv));
        }
        dfs1(1, 0);
        memset(vis, 0, sizeof(vis));
        sort(a+1, a+1+n);
        for(int i = 1; i <= n; i ++){
            rem[i] = a[i].val;
        }
        ll ans = 0;
        dfs2(1, 0);
        // return 0;
        sort(a+1, a+1+n);
        for(int i = 0; i < q; i ++){
            scanf("%d", &tv);
            Node ttm; ttm.flag = 1, ttm.val = tv;
            int ttp = lower_bound(a+1, a+1+cnt, ttm) - a - 1;
            ans += a[ttp].num;
        }
        printf("%lld\n", ans);
    }
}
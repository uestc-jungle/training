#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const int maxn = 256, maxm  = 1 << 15;

struct Edge{
    int v, f, nxt;
};

int n, src, sink;
int g[maxn + 10];
int nume;
Edge e[maxm * 2 + 10];

void addedge(int u, int v, int c){
    e[++nume].v = v;
    e[nume].f = c;
    e[nume].nxt = g[u];
    g[u] = nume;

    e[++nume].v = u;
    e[nume].f = 0;
    e[nume].nxt = g[v];
    g[v] = nume;
}

void init(){
    memset(g, 0, sizeof g);
    nume = 1;
}

queue<int> que;
bool vis[maxn + 10];
int dist[maxn + 10];

void bfs(){
    memset(dist, 0, sizeof dist);
    while(!que.empty()) que.pop();
    vis[src] = true;
    que.push(src);
    while(!que.empty()){
        int u = que.front(); que.pop();
        for(int i = g[u]; i; i = e[i].nxt){
            if(e[i].f && !vis[e[i].v]){
                que.push(e[i].v);
                dist[e[i].v] = dist[u] + 1;    
                vis[e[i].v] = true;
            }
        }
    }
}

int dfs(int u, int delta){
    if(u == sink) return delta;
    int ret = 0;
    for(int i = g[u]; delta && i; i = e[i].nxt){
        if(e[i].f && dist[e[i].v] == dist[u] + 1){
            int dd = dfs(e[i].v, min(e[i].f, delta));
            e[i].f -= dd;
            e[i ^ 1].f += dd;
            delta -= dd;
            ret += dd;
        }
    }
    return ret;
}

int maxflow(){
    int ret = 0;
    while(true){
        memset(vis, 0, sizeof vis);
        bfs();
        if(!vis[sink]) return ret;
        ret += dfs(src, inf);
    }
}

vector<int> v[128];
void dfs2(int fat, int x){
    if(fat != x) addedge(fat*2, x*2-1, 1);
    int siz = v[x].size();

    for(int i = 0; i < siz; i ++)
        dfs2(fat, v[x][i]);
}

int main(){
    int T;
    scanf("%d", &T);
    while(T --){
        int n, m, tx, ty;
        init(); src = 210, sink = 211;
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i ++){
            v[i].clear();
            addedge(src, i*2, 1);
            addedge(i*2-1, sink, 1);
        }
        for(int i = 1; i <= m; i ++){
            scanf("%d%d", &tx, &ty);
            v[tx].push_back(ty);
        }
        for(int i = 1; i <= n; i ++){
            dfs2(i, i);
        }
        int tem = maxflow();
        // printf("Debug : %d\n", tem);
        printf("%d\n", n - tem);
    }
}
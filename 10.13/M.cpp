#include<bits/stdc++.h>
using namespace std;
const int inf = 101010;
const int maxn = 512, maxm = 10100;

struct Edge{
    int from,v, f, nxt;
};

int n, src, sink;
int g[maxn + 10];
int nume, m;
Edge e[maxm * 2 + 10];

void addedge(int u, int v, int c){
    e[++ nume].v = v;
    e[nume].from = u;
    e[nume].f = c;
    e[nume].nxt = g[u];
    g[u] = nume;
    e[++ nume].v = u;
    e[nume].from = v;
    e[nume].f = 0;
    e[nume].nxt = g[v];
    g[v] = nume;
}

int jtime;
void init() {
    jtime = 0;
    memset(g, 0, sizeof(g));
    nume = 1;
}

queue<int> que;
int vis[maxn + 10];
int dist[maxn + 10];

int path[maxn+15];
void bfs(){
    // memset(dist, 0, sizeof dist);
    while(!que.empty()) que.pop();
    vis[src] = ++jtime;
    que.push(src); // d + i
    path[src]=-1;
    while(!que.empty()){
        int u = que.front();
        que.pop();
        for(int i = g[u]; i; i = e[i].nxt){
            if(e[i].f && vis[e[i].v] != jtime) {
                que.push(e[i].v);
                path[e[i].v]=i;
                vis[e[i].v] = jtime;
            }
        }
    }
}

int maxflow(){
    int ret = 0;
    while(true){
        // memset(vis, 0, sizeof vis);
        bfs();
        if(vis[sink] != jtime) return ret;
        //src---->sink
        int dd=inf;
        for(int i = path[sink]; i!=-1; i = path[e[i].from]) dd=min(dd,e[i].f);
        for(int i = path[sink]; i!=-1; i = path[e[i].from]){
                e[i].f -= dd;
                e[i ^ 1].f += dd;
                cout << e[i].from << ' ' << e[i].to << ' ' << e[i].f << 
        }
        ret += dd;
    }
}

int T, tx, ty, d;
int ql, qr, cnt;

int cal(int l, int r){
    return d + l * d + r;
}

int ans[1 << 15], rem[32][32];
int main(){
    while(scanf("%d", &n) && n){
        init();
        scanf("%d", &d);
        src = 501, sink = 502;
        for(int j = 1; j <= d; j ++){
            addedge(j, sink, 0);
        }

        for(int i = 1; i <= d; i ++){
            for(int j = i; j <= d; j ++){
                addedge(src, cal(i, j), 0);
                rem[i][j] = nume - 1;
            }
        }

        for(int i = 1; i <= d; i ++){
            for(int j = i; j <= d; j ++){
                for(int k = i; k <= j; k ++)
                    addedge(cal(i, j), k, inf);
            }
        }

        cnt = 0;
        int flow = 0;
        // puts("Debug : ");
        for(int i = 1; i <= n; i ++){
            scanf("%d%d", &ql, &qr);
            // addedge(src, cal(ql, qr), 1);
            e[rem[ql][qr]].f ++;

            flow += maxflow();
            // printf("%d ", flow);
            if(flow < i){
                for(int j = 1; j <= d; j ++){
                    e[2*j].f ++;
                }
                ans[++ cnt] = i;
            }
        }

        for(int i = 1; i <= cnt; i ++){
            printf("%d", ans[i]);
            if(i != cnt)
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}
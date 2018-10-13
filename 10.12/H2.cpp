#include<bits/stdc++.h>
using namespace std;
const int maxn = 128;
int dp[maxn][maxn][2];
bool rem[maxn][maxn][2][2];
bool vis[maxn][maxn][2];
int m, n, deg[maxn];
vector<int> v[maxn];
struct Node{
    int x, y, tim;
    Node(int tx=0, int ty=0, int tt=0):x(tx), y(ty), tim(tt){}
};

queue<Node> q;

int main(){
    int T;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++){
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= n; j ++){
                dp[i][j][0] = dp[i][j][1] = 1;
            }
        }
        int tx, ty, t_tim;
        for(int i = 1; i <= m; i ++){
            scanf("%d%d", &tx, &ty);
            v[ty].push_back(tx);
            deg[tx] ++;
        }
        
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= n; j ++){
                if(i == j) {
                    q.push(Node(i, j, 0)); 
                    q.push(Node(i, j, 1));
                    vis[i][j][0] = vis[i][j][1] = 1;
                }
                else if(!deg[i]){
                    
                }
            }
        }

        while(!q.empty()){
            Node tem_front = q.front(); q.pop();
            tx = tem_front.x;
            ty = tem_front.y;
            t_tim = tem_front.tim;
            int siz, tp_x, tp_y;
            if(t_tim){
                siz = v[ty].size();
                if(tx == ty || !deg[tx])
                    dp[tx][ty][1] = 0;
                else{
                    if(rem[tx][ty][1][1]) 
                        dp[tx][ty][1] = 1;
                    else
                        dp[tx][ty][1] = 0;
                }
            }
            else{
                siz = v[tx].size();
                if(tx == ty)
                    dp[tx][ty][0] = 0;
                else if(!deg[ty])
                    dp[tx][ty][0] = 1;
                else{
                    if(rem[tx][ty][0][0]) dp[tx][ty][0] = 0;
                    else dp[tx][ty][0] = 1;
                }
            }

            for(int i = 0; i < siz; i ++){
                if(t_tim){
                    tp_x = tx, tp_y = v[ty][i];
                    rem[tp_x][tp_y][!t_tim][dp[tx][ty][t_tim]] = true;
                    vis[tp_x][tp_y][!t_tim] = 1;
                    if(!vis[tp_x][tp_y][!t_tim]){
                        q.push(Node(tp_x, tp_y, !t_tim));
                        vis[tp_x][tp_y][!t_tim] = 1;
                    }
                }
                else{
                    tp_x = v[tx][i], tp_y = ty;
                    rem[tp_x][tp_y][!t_tim][dp[tx][ty][t_tim]] = true;
                    vis[tp_x][tp_y][!t_tim] = 1;
                    if(!vis[tp_x][tp_y][!t_tim]){
                        q.push(Node(tp_x, tp_y, !t_tim));
                        vis[tp_x][tp_y][!t_tim] = 1;
                    }
                }
            }
        }
        int x, y;
        scanf("%d%d", &x, &y);
        
        printf("Debug:\n");
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= n; j ++){
                printf("%d - %d\t\t", dp[i][j][0], dp[i][j][1]);
            }
            puts("");
        }

        printf("Case #%d: %s\n", cas, dp[x][y][1] ? "Yes" : "No");
        memset(vis, 0, sizeof vis);
        memset(deg, 0, sizeof deg);
        memset(rem, 0, sizeof rem);
        for(int i = 0; i <= n; i ++)
            v[i].clear();
    }
}
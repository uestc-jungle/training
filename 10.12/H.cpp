#include<bits/stdc++.h>
using namespace std;
const int maxn = 128;
bool rem[maxn][maxn][2][maxn], vis[maxn][maxn][2];
int m, n, SG[maxn][maxn][2], deg[maxn];
vector<int> v[maxn];
struct Node{
    int x, y, tim;
    Node(int tx=0, int ty=0, int tt=0):x(tx), y(ty), tim(tt){}
};

queue<Node> q;

int main(){
    int T, tx, ty, t_tim;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++){
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= m; i ++){
            scanf("%d%d", &tx, &ty);
            v[ty].push_back(tx);
            deg[tx] ++;
        }
        

        for(int i = 1; i <= n; i ++){
            q.push(Node(i, i, 0));
            vis[i][i][0] = 1;
        }

        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= n; j ++){
                if(!deg[i]){
                    SG[i][j][1] = 0;
                    q.push(Node(i, j, 1));
                    vis[i][j][1] = 1;
                }
                else if(!deg[j] && i != j){
                    SG[i][j][0] = 1;
                    q.push(Node(i, j, 0));
                    vis[i][j][0] = 1;
                }
                // else 

            }
        }

        while(!q.empty()){
            Node tem_front = q.front(); q.pop();
            int siz = v[tem_front.x].size();
            tx = tem_front.x, ty = tem_front.y, t_tim = tem_front.tim;
            for(int k = 0; k < maxn; k ++){
                if(!rem[tx][ty][t_tim][k]) 
                    SG[tx][ty][t_tim] = k;
            }

            int tp_x, tp_y;
            for(int i = 0; i < siz; i ++){
                if(tem_front.tim)
                    tp_x = tx, tp_y = v[ty][i];
                else
                    tp_x = v[tx][i], tp_y = ty;
                rem[tp_x] [tp_y] [!t_tim] [SG[tx][ty][t_tim]] = true;
                if(!vis[tp_x][tp_y][!t_tim]){
                    q.push(Node(tp_x, tp_y, !t_tim));
                    vis[tp_x][tp_y][!t_tim] = 1;
                }
            }
        }
        int x, y;
        scanf("%d%d", &x, &y);
        printf("Case #%d: %s\n", cas, SG[x][y][1] ? "Yes" : "No");

        memset(rem, 0, sizeof rem);
        memset(vis, 0, sizeof vis);
        memset(SG, 0, sizeof SG);
        memset(deg, 0, sizeof deg);
        for(int i = 0; i <= n; i ++)
            v[i].clear();
    }
}
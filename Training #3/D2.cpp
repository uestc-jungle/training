#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int n, m, b, k, r, t;
ll dp[220][110][8][2][6];
ll rem[10][110];
struct Edge{
    int x, t, c;
    Edge(int tx=0, int tt=0, int tc=0):x(tx), t(tt), c(tc) {}
};
vector<Edge> v[110];
int main(){
    int cas; int cctv = 0;
    scanf("%d", &cas);
    while(cas --){
        scanf("%d%d%d%d%d%d", &n, &m, &b, &k, &r, &t);
        for(int i = 1; i <= n; i ++){
            v[i].clear();
        }
        for(int i = 0; i < k; i ++){
            for(int j = 1; j <= n; j ++){
                scanf("%lld", &rem[i][j]);
            }
        }

        for(int i = 1; i <= m; i ++){
            int tx, ty, tt, tc;
            scanf("%d%d%d%d", &tx, &ty, &tt, &tc);
            v[tx].push_back(Edge(ty, tt, tc));
            //v[ty].push_back(Edge(tx, tt, tc));
        }

        memset(dp, -1, sizeof(dp));

        dp[0][1][0][1][0] = dp[0][1][0][0][0] = r;

        for(int i = 0; i <= t; i ++){
            for(int j = 1; j < n; j ++){
                for(int u = 0; u < k; u ++){
                    for(int flag = 0; flag <= 1; flag ++){
                        for(int s = 0; s <= b; s ++){
                            if(dp[i][j][u][flag][s] < 0) continue;
                            if(flag){
                                // 切换宇宙
                                if(j != 1){ 
                                /*
                                    for(int tem_u = 0; tem_u < k; tem_u ++) // tem_u = (u+1) % k;
                                        dp[i+1][j][tem_u][0][s] = max(dp[i][j][u][1][s], dp[i+1][j][tem_u][0][s]);
                                */
                                    int tem_u = (u+1) % k;
                                    dp[i+1][j][tem_u][0][s] = max(dp[i][j][u][1][s], dp[i+1][j][tem_u][0][s]);
                                }
                                
                                // 切换地点
                                int siz_ = v[j].size();
                                for(int cnt = 0; cnt < siz_; cnt ++){
                                    if(i + v[j][cnt].t > t) continue;
                                    if((v[j][cnt].t == n || v[j][cnt].t == 1) && u != 0) continue;
                                        dp[i + v[j][cnt].t] [v[j][cnt].x] [u] [0] [s] = max(dp[i + v[j][cnt].t] [v[j][cnt].x] [u] [0] [s], dp[i][j][u][1][s] - v[j][cnt].c);
                                }
                            }
                            else{ // 买卖盐
                                if(j == 1 || j == n) continue;
                                dp[i][j][u][1][s] = max(dp[i][j][u][1][s], dp[i][j][u][0][s]);
                                if(dp[i][j][u][0][s] >= rem[u][j] && s < b){
                                    dp[i][j][u][1][s+1] = max(dp[i][j][u][1][s+1], dp[i][j][u][0][s] - rem[u][j]);
                                }
                                if(s > 0){
                                    dp[i][j][u][1][s-1] = max(dp[i][j][u][1][s-1], dp[i][j][u][0][s] + rem[u][j]);
                                }
                            }
                        }
                    }
                }
            }
        }
        ll ans = -1;
        for(int i = 0; i <= t; i ++){
            for(int s = 0; s <= b; s ++)
                ans = max(ans, dp[i][n][0][0][s]);
        }
        printf("Case #%d: ", ++ cctv);
        if(ans < 0) printf("Forever Alone\n");
        else printf("%lld\n", ans);
    }
    return 0;

}
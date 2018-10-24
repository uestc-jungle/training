#include<bits/stdc++.h>
using namespace std;
int rem[256], a[256][256];
int n, m, x, dp[4][256];
int maxv;

int main(){
    while(scanf("%d%d%d", &n, &m, &x) != EOF){
        memset(dp, 128, sizeof(dp));
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= m; j ++)
                scanf("%d", &a[i][j]);
        }
        maxv = -1e9;
        
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= m; j ++)
                rem[j] = 0;
            
            for(int j = i; j <= n; j ++){
                for(int k = 1; k <= m; k ++)
                    rem[k] += a[j][k];
                
                int sum = 0, minv = 0;
                for(int k = 1; k <= m; k ++){
                    sum = sum + rem[k];
                    dp[0][k] = max(dp[0][k], sum - minv);
                    maxv = max(maxv, dp[0][k]);
                    minv = min(minv, sum);
                }
            }
        }
        
        for(int i = 1; i <= m; i ++){
            for(int j = 1; j <= n; j ++)
                rem[j] = 0;
            
            for(int j = i; j <= m; j ++){
                int sum = 0, minv = 0;
                for(int k = 1; k <= n; k ++)
                    rem[k] += a[k][j];
                
                for(int k = 1; k <= n; k ++){
                    sum = sum + rem[k];
                    dp[1][k] = max(dp[1][k], sum - minv);
                    minv = min(minv, sum);
                }
            }
        }
        
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= m; j ++)
                rem[j] = 0;
            
            for(int j = i; j <= n; j ++){
                int sum = 0, minv = 0;
                for(int k = 1; k <= m; k ++)
                    rem[k] += a[j][k];
                
                for(int k = m; k > 0; k --){
                    sum = sum + rem[k];
                    dp[2][k] = max(dp[2][k], sum - minv);
                    minv = min(minv, sum);
                }
            }
        }
        
        
        for(int i = 1; i <= m; i ++){
            for(int j = 1; j <= n; j ++)
                rem[j] = 0;
            
            for(int j = i; j <= m; j ++){
                int sum = 0, minv = 0;
                for(int k = 1; k <= n; k ++)
                    rem[k] += a[k][j];
                
                for(int k = n; k > 0; k --){
                    sum = sum + rem[k];
                    dp[3][k] = max(dp[3][k], sum - minv);
                    minv = min(minv, sum);
                }
            }
        }
        
        for(int i = 1; i <= m; i ++){
            dp[0][i] = max(dp[0][i-1], dp[0][i]);
        }
        for(int i = 1; i <= n; i ++){
            dp[1][i] = max(dp[1][i-1], dp[1][i]);
        }
        for(int i = m; i > 0; i --){
            dp[2][i] = max(dp[2][i+1], dp[2][i]);
        }
        for(int i = n; i > 0; i --){
            dp[3][i] = max(dp[3][i+1], dp[3][i]);
        }
        
        
        
        int ans = 1e9;
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= m; j ++){
                if(a[i][j] <= x){
                    ans = min(ans, maxv);
                    continue;
                }
                int tem_maxv = max(dp[0][j-1], dp[1][i-1]);
                tem_maxv = max(tem_maxv, dp[2][j+1]);
                tem_maxv = max(tem_maxv, dp[3][i+1]);
                if(tem_maxv == maxv){
                    ans = min(ans, maxv);
                }
                else
                    ans = min(ans, max(maxv - (a[i][j] - x), tem_maxv));
            }
        }
//        printf("Debug : \n");
//        for(int i = 1; i <= m; i ++)
//            printf("%d ", dp[0][i]);
//        puts("");
//        for(int i = 1; i <= n; i ++)
//            printf("%d ", dp[1][i]);
//        puts("");
//        for(int i = 1; i <= m; i ++)
//            printf("%d ", dp[2][i]);
//        puts("");
//        for(int i = 1; i <= n; i ++)
//            printf("%d ", dp[3][i]);
//        puts("");
        printf("%d\n", ans);
    }
}

#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
ld dp[52][52][3000];
int main(){
    int T;
    scanf("%d", &T);
    while(T --){
        int n, m;
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= m; j ++){
                for(int k = 1; k <= n * m; k ++)
                    dp[i][j][k] = 0;
            }
        }
        dp[0][0][0] = 1;
        for(int i = 0; i <= n; i ++){
            for(int j = 0; j <= m; j ++){
                for(int k = 0; k <= i * j; k ++){
                    if(k > i * j) break;
                    if(i == n && j == m) break;
                    dp[i+1][j][k+1] += dp[i][j][k] * (((ld)(n-i) * j) / (n*m - k));
                    dp[i][j+1][k+1] += dp[i][j][k] * (((ld)i * (m-j)) / (n*m - k));
                    dp[i+1][j+1][k+1] += dp[i][j][k] * (((ld)(n-i) * (m-j)) / (n*m - k));
                    dp[i][j][k+1] += dp[i][j][k] * (((ld)(i * j - k)) / (n*m - k));
                }
            }
        }
        ld ans = 0;
        for(int i = 1; i <= n * m; i ++){
            ans += dp[n][m][i] * i;
            // cout << dp[n][m][i] << endl;

        }
        printf("%.9Lf\n", ans);
    }
}
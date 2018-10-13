#include<bits/stdc++.h>
using namespace std;
const int maxn = 1024;
char ch[maxn];
int dp[maxn], rem[maxn][maxn];
int minv, sum;
int main(){
    int T;
    scanf("%d", &T);
    while(T --){
        scanf("%s", ch+1);
        long int len = strlen(ch+1);
        for(int i = 1; i <= len; i ++){
            sum = minv = 0;
            for(int j = i; j <= len; j ++){
                if('1' <= ch[j] && ch[j] <= '9')
                    sum ++;
                else 
                    sum --;
                minv = min(minv, sum - 1);
                if(sum - (1 + minv) >= (-minv + 1) / 2){
                    rem[i][j] = (1 - minv) / 2 + abs(1 - sum);
                    
                }
                else
                    rem[i][j] = (sum - (1 + minv)) + abs(1 - sum);
            }
        }
        memset(dp, 127, sizeof(dp));
        dp[0] = 0;
        // cout << rem[1][4] << endl;
        // return 0;
        for(int i = 1; i <= len; i ++){
            for(int j = i; j <= len; j ++){
                dp[j] = min(dp[j], dp[i-1] + rem[i][j]);
            }
        }
        printf("%d\n", dp[len]);
    }
}
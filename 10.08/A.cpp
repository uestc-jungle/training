#include<bits/stdc++.h>
using namespace std;
char ch[1024];
char oth[1024];
int dp[110][110];
int nex1[110][26], nex2[110][26];
int main(){
    int T;
    scanf("%d", &T);
    while(T --){
        scanf("%s", ch+1);
        int len = strlen(ch+1);
        for(int i = 1; i <= len; i ++){
            oth[i] = ch[len + 1 - i];
        }
        memset(dp, 0, sizeof(dp));
        memset(nex1, 0, sizeof(nex1));
        memset(nex2, 0, sizeof(nex2));
        for(int i = len; i >= 0; i --){
            for(int j = 'a'; j <= 'z'; j ++){
                nex1[i-1][j-'a'] = nex1[i][j-'a'];
                nex2[i-1][j-'a'] = nex2[i][j-'a'];
            }
            if(i <= len){
                nex1[i-1][ch[i]-'a'] = i;
                nex2[i-1][oth[i]-'a'] = i;
            }
        }

        for(int i = 0; i < len; i ++){
            for(int j = 0; j + i < len; j ++){
                dp[i][j+1] = max(dp[i][j], dp[i][j+1]);
                dp[i+1][j] = max(dp[i][j], dp[i+1][j]);
                for(int k = 0; k < 26; k ++){
                    dp[nex1[i][k]][nex2[j][k]] = max(dp[nex1[i][k]][nex2[j][k]], dp[i][j] + 1);
                }
            }
        }
        int ans = 0;
        for(int i = 0; i <= (len >> 1) * 2; i ++){
            for(int j = 0; j + i < len; j ++){
                ans = max(dp[i][j], ans);
            }
        }
        printf("Debug : %d ", ans);
        // cout << ans << endl;
        // continue;
        // if(len & 1) ans --;
        len -= ans * 2;
        printf("%d\n", len);
    }    
}
#include<bits/stdc++.h>
using namespace std;
int dp[(1<<21)], poin[1<<21];
int cnt[1<<21];
int main(){
    int T;
    scanf("%d", &T);
    for(int i = 1; i < (1<<20); i ++){
        for(int j = 0; j < 20; j ++){
            if((1<<j) & i){
                poin[i] = j;
                break;
            }
        }
        int tem = 0;
        for(int j = 0; j < 20; j ++){
            if((1<<j) & i) tem ++;
        }
        cnt[i] = tem;
    }

    while(T --){
        int n, m, tx, ty;
        memset(dp, 0, sizeof(dp));
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= m; i ++){
            scanf("%d%d", &tx, &ty);
            tx --, ty --;
            dp[1<<tx] |= (1<<ty);
        }
        for(int sta = 1; sta < (1<<n); sta ++){
            if(sta == (1<<poin[sta])) continue;
            dp[sta] = dp[sta ^ (1<<poin[sta])] & dp[1<<poin[sta]];
        }

        
        // for(int sta = 0; sta < (1<<n); sta ++){
        //     printf("%d ", dp[sta]);
        // }
        // return 0;
        
        int ans = 0;
        for(int sta = 1; sta < (1<<n); sta ++){
            if(dp[sta] == 0) continue;
            ans = max(ans, cnt[sta] + cnt[dp[sta]]);
        }
        printf("%d\n", ans);
    }
}

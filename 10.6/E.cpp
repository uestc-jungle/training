#include<bits/stdc++.h>
using namespace std;
struct node{
    int x, b, c;
    node(int tx=0, int tb=0, int tc=0):x(tx), b(tb), c(tc){}
};
queue<node> q;
int ch[101000][8], tem[8];
int dp[101000][5][4];
const int maxm = 100000;

void init(int x){
    for(int i = 0; i < 7; i ++){
        tem[i] = ch[x][i];
    }
}

int cal(){
    int ans = 0;
    for(int i = 6; i >= 0; i --){
        ans = (ans * 10 + tem[i]);
    }
    return ans;
}

int main(){
    for(int i = 0; i < maxm; i ++){
        int x = i, posi = 0;
        while(x){
            ch[i][posi ++] = x % 10;
            x /= 10;
        }
        // init(i);
        // if(i != cal()){
        //     printf("NO");
        //     return 0;
        // }    
    }

    q.push(node(12345, 0, 0));
    memset(dp, 127, sizeof(dp));
    dp[12345][0][0] = 0;
    // return 0;
    while(!q.empty()){
        node tem_u = q.front(); q.pop();
        for(int i = 1; i < 5; i ++){
            init(tem_u.x);
            swap(tem[i-1], tem[i]);
            int tem_v = cal();

            if(dp[tem_v][tem_u.b][tem_u.c] <= dp[tem_u.x][tem_u.b][tem_u.c] + 1 || tem_v >= maxm) continue;
            dp[tem_v][tem_u.b][tem_u.c] = dp[tem_u.x][tem_u.b][tem_u.c] + 1;
            
            q.push(node(tem_v, tem_u.b, tem_u.c));
        }

        for(int i = 0; i < 5; i ++){
            init(tem_u.x);
            tem[i] = (1 + tem[i]) % 10;
            int tem_v = cal();
            if(dp[tem_v][tem_u.b+1][tem_u.c] <= dp[tem_u.x][tem_u.b][tem_u.c] + 1 || tem_v >= maxm || tem_u.b >= 3) continue;
            dp[tem_v][tem_u.b+1][tem_u.c] = dp[tem_u.x][tem_u.b][tem_u.c] + 1;
            q.push(node(tem_v, tem_u.b+1, tem_u.c));
        }

        for(int i = 0; i < 5; i ++){
            init(tem_u.x);
            tem[i] = 2 * tem[i] % 10;
            int tem_v = cal();
            if(dp[tem_v][tem_u.b][tem_u.c+1] <= dp[tem_u.x][tem_u.b][tem_u.c] + 1 || tem_v >= maxm || tem_u.c >= 2) continue;
            dp[tem_v][tem_u.b][tem_u.c+1] = dp[tem_u.x][tem_u.b][tem_u.c] + 1;
            q.push(node(tem_v, tem_u.b, tem_u.c+1));
        }
    }
    // printf("YES");
    // return 0;

    int n;
    while(scanf("%d", &n) != EOF){
        int ans = maxm * 100;
        for(int i = 0; i < 4; i ++){
            for(int j = 0; j < 3; j ++){
                ans = min(dp[n][i][j], ans);
            }
        }
        if(ans == 100 * maxm) ans = -1;
        printf("%d\n", ans);
    }
}
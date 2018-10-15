#include<bits/stdc++.h>
using namespace std;
int val[512][512];
int main(){
    int T;
    scanf("%d", &T);
    while(T --){
        int n, tx, ty, tv;
        scanf("%d", &n);
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j < i; j ++){
                scanf("%d%d%d", &tx, &ty, &tv);
                val[tx][ty] = val[ty][tx] = tv;
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i ++){
            for(int j = i+1; j <= n; j ++){
                for(int k = j+1; k <= n; k ++){
                    ans = max(ans, val[i][j] + val[j][k] + val[i][k]);
                }
            }
        }
        printf("%d\n", ans);
    }
}
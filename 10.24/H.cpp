#include<bits/stdc++.h>
using namespace std;
int B[101010], n, m, ans[128];
int main(){
    int T;
    scanf("%d", &T);
    while(T --){
        scanf("%d%d", &n, &m);
        for(int i = 0; i <= m; i ++){
            scanf("%d", &B[i]);
        }
        B[0] --;
        for(int i = 1; i <= n; i ++){
            int x;
            for(int j = 0; j <= m; j ++){
                if(!B[j]) continue;
                x = j;
                B[j] --;
                ans[i] = j;
                break;
            }
            for(int j = x; j <= m; j ++){
                if(B[j]){
                    B[j+x] -= B[j];
                }
            }
        }
        for(int i = 1; i <= n; i ++){
            printf("%d", ans[i]);
            if(i != n) printf(" ");
        }
        puts("");
    }
}
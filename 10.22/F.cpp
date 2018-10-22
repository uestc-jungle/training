#include<bits/stdc++.h>
using namespace std;
int T, n;
int ans[101010];
int main(){
    scanf("%d", &T);
    while(T --){
        scanf("%d", &n);
        int cnt = 0;
        for(int i = 1; i <= n; i += 2){
            ans[i] = ++ cnt;
        }
        for(int i = 2; i <= n; i += 2)
            ans[i] = ++ cnt;
        for(int i = 1; i <= n; i ++)
            printf("%d ", ans[i]);
        puts("");
    }
}
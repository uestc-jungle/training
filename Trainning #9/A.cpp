#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll a[101010];
int main(){
    int T;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++){
        int n, k; ll sum = 0, ans = 0;
        scanf("%d%d", &n, &k);
        ll all = 0;
        for(int i = 1; i <= n; i ++){
            scanf("%lld", &a[i]);
            all += a[i];
        }
        if(all % k){
            ans = -1;
            printf("Case #%d: %lld\n", cas, ans);
            continue;
        }
        // puts("Debug");
        // for(int i = 1; i <= n; i ++){
        //     printf("%d ", a[i]);
        // }
        // puts("");
        ll ave = all / k;
        // printf("Debug : %lld\n", ave);
        for(int i = 1; i <= n; i ++){
            if(sum != 0) ans ++;
            sum += a[i];
            // if(sum > ave){
            ans += (sum-1) / ave;
            // printf("%lld %lld\n", sum, (sum-1) / ave);
            // }
            sum %= ave;
        }
        printf("Case #%d: %lld\n", cas, ans);
    }
}
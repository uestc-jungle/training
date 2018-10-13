#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef double jf;
ll a[101010];
const ll inf = 1e10;
int main(){
    int T;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++){
        int n; ll ans = 0, maxv = inf;
        scanf("%d", &n);
        for(int i = 1; i <= n; i ++){
            scanf("%lld", &a[i]);
        }
        for(int i = n; i > 0; i --){
            maxv = min(maxv, a[i] - a[i-1]);
            ans += (a[i] - a[i-1] + maxv - 1) / maxv;
            printf("dt: %lld\n", (a[i] - a[i-1] + maxv - 1) / maxv);
            if((a[i] - a[i-1]) % maxv)
                maxv --;
            printf("maxv2: %lld\n", maxv);
        }
        printf("Case #%d: %lld\n", cas, ans);
    }
}
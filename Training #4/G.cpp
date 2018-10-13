#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll a[1024], p[1024], c[1024], d[1024];
int m, k; 
const ll inf = 1e18;
int main(){
    int T;
    scanf("%d", &T);
    while(T --){
        scanf("%d%d", &m, &k);
        for(int i = 1; i <= m; i ++){
            scanf("%lld%lld", &a[i], &p[i]);
        }
        for(int i = 1; i <= k; i ++){
            scanf("%lld%lld", &c[i], &d[i]);
        }
        ll ans = inf;
        for(int i = 1; i <= m; i ++){
            ll tem_ans = 0;
            for(int j = 1; j <= k; j ++){
                tem_ans += c[j] * ((d[j] * (100 - p[i]) + 99) / 100);
            }
            tem_ans = max(tem_ans, a[i]);
            ans = min(ans, tem_ans);
        }
        printf("%lld\n", (ans + 9) / 10);
    }
}
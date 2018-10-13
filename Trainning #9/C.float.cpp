#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef double jf;
const jf eps = 1e-8;
ll a[101010];
const ll inf = 1e10;
int main(){
    int T;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++){
        int n; ll ans = 0; jf maxv = inf;
        scanf("%d", &n);
        for(int i = 1; i <= n; i ++){
            scanf("%lld", &a[i]);
        }
        for(int i = n; i > 0; i --){
            jf dt; ll deltaT;
            jf dis = 1. * (a[i] - a[i - 1]);
            maxv = min(maxv, dis);
            deltaT = dis / maxv; dt = deltaT;
            // dt = ceil(dt);
            ans += deltaT;
            if (fabs(maxv - dis / dt) > eps)
            {
                ans++;
                maxv = dis / dt;
            }
        }
        printf("Case #%d: %lld\n", cas, ans);
    }
}
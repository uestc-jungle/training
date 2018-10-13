#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef double jf;
const jf eps = 1e-9;
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
            jf dt; int deltaT;
            maxv = min(maxv, 1. * (a[i] - a[i-1]));
            dt = (a[i] - a[i - 1]) / maxv;
            dt = ceil(dt - eps);
            // dt = ceil(dt);
            ans += (ll)(dt + eps);
            maxv = (1. * (a[i] - a[i - 1]) / dt);
        }
        printf("Case #%d: %lld\n", cas, ans);
    }
}
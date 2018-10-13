#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod =  998244353;
ll qpow(ll x, ll y, ll mod){
    ll ans = 1;
    while(y){
        if(y & 1) ans = ans * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return ans;
}
const int maxn = 101010;
ll sum[maxn], dp[maxn];
ll a[maxn], ans;
int T, n;

int main(){
    scanf("%d", &T);
    while(T --){
        scanf("%d", &n);
        for(int i = 1; i <= n; i ++){
            scanf("%lld", &a[i]);
        }

        ans = 0;
        for(int i = 1; i <= n; i ++){
            dp[i] = (qpow(n, mod-2, mod) + qpow(i-1, mod-2, mod) * sum[i-1]) % mod;
            ans = (ans + dp[i] * a[i]) % mod;
            sum[i] = (sum[i-1] + dp[i]) % mod;
        }
        printf("%lld\n", ans);
    }    
}
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1e9+7;
const int maxn = 1001010;
ll Comb[maxn], rem[maxn], inv[maxn];
ll qpow(ll x, ll y, ll mod){
    ll ans = 1;
    while(y){
        if(y & 1) ans = ans * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return ans;
}

int main(){
    rem[0] = inv[0] = 1;
    for(int i = 1; i < maxn; i ++){
        rem[i] = rem[i-1] * i % mod;
        inv[i] = qpow(rem[i], mod-2, mod);
    }
    int T;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++){
        ll n, m, k, ans = 0;
        scanf("%lld%lld%lld", &n, &m, &k);
        if(m >= k){
            ll flag = 1, Comb_m = 1;
            for(int i = 1; i <= k; i ++)
                Comb_m = Comb_m * (m-i+1) % mod * qpow(i, mod-2, mod) % mod;
            for(int c = k; c > 0; c --){
                ans += rem[k] * inv[c] % mod * inv[k-c] % mod * c % mod *
                 qpow(c-1, n-1, mod) % mod * flag;
                ans = (ans + mod) % mod;
                flag = -flag;
            }
            ans = ans * Comb_m % mod;
            // printf("")
        }
        printf("Case #%d: %lld\n", cas, ans);
    }
}
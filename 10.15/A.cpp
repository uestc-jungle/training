#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1e9 + 7;
const int maxn = 101010;
ll inv[maxn];
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
    inv[0] = 1;
    for(int i = 1; i < maxn; i ++){
        inv[i] = qpow(i, mod-2, mod);
    }
    int T;
    scanf("%d", &T);
    
    for(int cas = 1; cas <= T; cas ++){
        ll n, k;
        ll ans = 1, tem = 1, sum = 0;
        scanf("%lld%lld", &n, &k);
        ans = qpow(2, n, mod);
        for(int i = 0; i < k; i ++){
            sum = (sum + tem) % mod;
            tem = tem * inv[i+1] % mod;
            tem = tem * (n - i) % mod;
            // printf("%lld\n", tem);
        }
        ans = (ans - sum + mod) % mod;
        printf("Case #%d: %lld\n", cas, ans);
    }   
}
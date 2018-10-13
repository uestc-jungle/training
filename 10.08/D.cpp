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
ll a[maxn], ssum[maxn], sum[maxn];
int n; ll ans;
int main(){
    int T;
    scanf("%d", &T);
    while(T --){
        scanf("%d", &n);
        for(int i = 1; i <= n; i ++){
            scanf("%lld", &a[i]);
        }

        ans = 0;
        sum[n+1] = 0;
        ssum[n+1] = 0;
        
        for(int i = n; i > 1; i --){
            sum[i] = (sum[i+1] + qpow(i-1, mod-2, mod) * a[i] % mod) % mod;
        }
        
        for(int i = 1; i <= n; i ++){
            ans = (ans + a[i]) % mod;
        }
        
        for(int i = n; i > 1; i --){
            ssum[i] = (sum[i] + ssum[i+1]) % mod;
        }

        for(int i = n; i > 1; i --){
            ans = (ans + ssum[i]) % mod;
        }

        for(int i = 1; i <= n; i ++){
            printf("---> %lld\n", (a[i] + ssum[i+1]) % mod);
        }

        ans = ans * qpow(n, mod-2, mod) % mod;
        // ans = (ans - ssum[1] + mod) % mod;
        printf("%lld\n", ans);
    }
}
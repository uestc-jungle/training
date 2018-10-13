#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 998244353;

ll qpow(ll x, ll y, ll mod){
    ll ans = 1;
    while(y){
        if(y & 1) ans = ans * x % mod;
        x = x * x % mod;
        y >>= 1;
    } 
    return ans;
}

int n, m;
ll p[100], q[100];
ll dp[(1<<20)+10]; 
int poin[(1<<20)+10];
ll rem[110];

int main(){
    int T;
    scanf("%d", &T);
    for(int i = 0; i < (1 << 20)-1; i ++){
        for(int j = 19; j >= 0; j --){
            if((1 << j) & i){
                poin[i] = j;
                break;
            }
        }
    }
    while(T --){
        scanf("%d", &m);
        ll tx = 1;
        for(int i = 0; i < m; i ++){
            scanf("%lld%lld", &p[i], &q[i]);
            tx = tx * qpow(p[i], q[i], mod) % mod;
        }
        // printf("tx : %lld\n", tx);
        ll ans = 0;
        dp[0] = tx;
        for(int i = 0; i < m; i ++){
            rem[i] = qpow(p[i], mod-2, mod);
        }
        for(int i = 1; i < (1 << m); i ++){
            dp[i] = dp[i-(1<<poin[i])] * (1 - rem[poin[i]] + mod) % mod * q[poin[i]] % mod;
        }

        for(int i = 0; i < (1<<m); i ++){
            ans = (ans + dp[i]) % mod;
            // printf("%d -->  poin : %d,  dp : %lld\n", i, poin[i], dp[i]);
        }
    


        // for(int i = 0; i < (1 << m); i ++){
        //     long long int tem = tx;
        //     for(int j = 0; j < m; j ++){
        //         if((1 << j) & i){
        //             tem = tem * (1 - qpow(p[j], mod-2, mod) + mod) % mod * q[j] % mod;
        //         }
        //     }
        //     // printf("%d --> %lld \n", i, tem);
        //     ans = (ans + tem) % mod;
        // }
        printf("%lld\n", ans);
    }
}
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int maxn = 1 << 20;
bool valid[maxn];

void getPrime(int n, int &tot, ll ans[maxn]){
    tot = 0;
    memset(valid, true, sizeof valid);
    for(int i = 2; i <= n; i ++){
        if(valid[i]){
            tot ++;
            ans[tot] = i;
        }
        for(int j = 1; (j <= tot) && (i*ans[j] <= n); j ++){
            valid[i * ans[j]] = false;
            if(i % ans[j] == 0) break;
        }
    }
}
ll prime[maxn>>1];
ll rem[64], cnt;
int main(){
    int primesize;
    getPrime(maxn - 10, primesize, prime);
    int T;
    scanf("%d", &T);
    while(T --){
        ll x; cnt = 0;
        scanf("%lld", &x);
        // printf("%lld\n", x);
        // continue;
        for(int i = 1; prime[i] * prime[i] <= x; i ++){
            if(x % prime[i]) continue;
            cnt ++;
            int t_cnt = 0;
            while(x % prime[i] == 0){
                t_cnt ++;
                x /= prime[i];
            }
            rem[cnt] = t_cnt;
        }
        if(x > 1){
            rem[++cnt] = 1;
        }
        ll ans = 0, node = 1;
        // for(int i = 1; i <= 100; i ++){
        //     printf("%lld ", prime[i]);
        // }
        // continue;
        // for(int i = 1; i <= cnt; i ++)
        //     printf("%lld ", rem[i]);
        // puts("");
        for(int i = 1; i <= cnt; i ++){
            ans = ans * (rem[i] + 1) + node * rem[i];
            node = (rem[i]+1) * node; 
        }
        printf("%lld\n", ans);
    }
}
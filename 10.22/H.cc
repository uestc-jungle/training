#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int maxn=101010;
bool valid[maxn]; 
int prime[maxn], a[maxn], n;
int b[maxn]; const ll inf = 1e11;
ll rem[maxn], ans;
void getPrime(int n, int &tot, int ans[maxn]){
    memset(valid, true, sizeof valid);
    for(int i = 2; i <= n; i ++){
        if(valid[i]) tot ++, ans[tot] = i;

        for(int j = 1; (j <= tot) && (i*ans[j] <= n); j ++){
            valid[i*ans[j]] = false;
            if(i % ans[j] == 0) break;
        }
    }
}

void proc(ll x){

    for(int j = 1; j <= n; j ++)
        b[j] = a[j] % x;
    sort(b+1, b+1+n);
    
    for(int j = 1; j <= n; j ++){
        rem[j] = rem[j-1] + b[j];
    }
    
    ll tem_sum = 0;
    
    for(int j = 0; j < n; j ++){
        if(1ll*j*x - tem_sum == rem[n-j])
            ans = min(ans, rem[n-j]);
        tem_sum += b[n-j];
    }
}

int main() {
    int cas, cnt = 0;
    scanf("%d",&cas);
    getPrime(100100, cnt, prime);
    // for(int i = 1; i <= 10; i ++)
    //     printf("%d ", prime[i]);
    // return 0;
    // printf("%d\n", prime[cnt]);
    // return 0;
    while (cas--) {
        ll sum = 0;
        scanf("%d", &n);
        rem[n+1] = 0; b[n+1] = 0;
        for(int i = 1; i <= n; i ++){
            scanf("%d", &a[i]);
            sum += a[i];
        }

        ans = inf;

        for(int i = 1; 1ll * prime[i] * prime[i] <= sum; i ++){
            if(sum % prime[i]) continue;
            proc(prime[i]);
            while(sum % prime[i] == 0) sum /= prime[i];
        }
        if(sum > 1)
            proc(sum);
        printf("%lld\n", ans);
    }
}
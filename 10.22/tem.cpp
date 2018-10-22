#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int maxn=101010;
bool valid[maxn]; 
int prime[maxn], a[maxn];
int b[maxn]; const ll inf = 1e11;
ll rem[maxn];
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

int main() {
    int cas, cnt = 0;
    scanf("%d",&cas);
    getPrime(100100, cnt, prime);
    while (cas--) {
        int n; ll sum = 0;
        scanf("%d", &n);
        rem[n+1] = 0; b[n+1] = 0;
        for(int i = 1; i <= n; i ++){
            scanf("%d", &a[i]);
            sum += a[i];
        }

        ll ans = inf;

        for(int i = 1; prime[i] * prime[i] <= n; i ++){
            if(sum % prime[i]) continue;

            for(int j = 1; j <= n; j ++)
                b[j] = a[j] % prime[i];
            sort(b+1, b+1+n);
            
            for(int j = 1; j <= n; j ++){
                rem[j] = rem[j-1] + b[j];
            }
            
            ll tem_sum = 0;
            
            for(int j = 0; j < n; j ++){
                if(1ll*j*prime[i] - tem_sum == rem[n-j])
                    ans = min(ans, rem[n-j]);
                tem_sum += b[n+1-j];
            }
        }
        printf("%lld\n", ans);
    }
}

#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll k; ll rem[10][101000];
map<ll, ll> mp[10];
ll qpow(ll x, ll y){
    ll ans = 1;
    while(y){
        if(y & 1) ans = ans * x;
        x *= x;
        y >>= 1;
    }
    return ans;
}
ll cal(ll x, ll k){
    ll sum = 0;
    while(x){
        sum += qpow(x%10, k);
        x /= 10;
    }
    return sum;
}

void prev(){
    for(int i = 1; i < 10; i ++){
        for(int j = 0; j < 1e5; j ++){
            mp[i][cal(j, i)-j] ++;
            rem[i][j] = cal(j, i) - j;
        }
    }
}

int main(){
    int T; ll k = 3, x;

    prev();
    // return 0;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++){
        scanf("%lld%lld", &x, &k);
        printf("Case #%d: ", cas);
        
        ll ans = 0;
        for(int i = 0; i < 1e5; i ++){
            auto iter = mp[k].find(x - (rem[k][i] - i * (100000ll-1)));
            if (iter != mp[k].end()) {
                ans+= iter->second;
            }
        }
        if(x == 0) ans --;
        printf("%lld\n", ans);
    }
}
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll x, y, z;
ll gcd(ll tx, ll ty){
    if(tx == 0) return 1;
    return gcd(ty%tx, tx) + ty / tx;
}
int main(){
    // scanf("")
    int T;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++){
        scanf("%lld%lld", &x, &y);
        ll ans = gcd(x, y);
        if((x == 0) || (y == 0)) ans = 2;
        if(x == 0 && y == 0) ans = 1;
        printf("Case #%d: %lld\n", cas, ans);
    }
}
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, a, b;
int cal(ll x){
    int ans = 0;
    while(x){
        ans += x % 10;
        x /= 10;
    }
    return ans;
}
ll rem[20];
int main(){
    scanf("%lld", &n);
    rem[0] = 1;
    for(int i = 1; i <= 13; i ++){
        rem[i] = rem[i-1] * 10;
    }
    ll bas = 1, oth = 0;
    int maxv = 0;
    for(int i = 0; bas <= n; i ++){
        for(int j = 1; j <= 9; j ++){
            a = j * bas + oth;
            if(a > n) break;
            maxv = max(maxv, cal(a) + cal(n - a));
        }
        bas = bas * 10;
        oth = oth * 10 + 9;
    }
    printf("%d", maxv);
}   

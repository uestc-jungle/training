#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long int rem[20];
int main(){
    int T;
    scanf("%d", &T);
    rem[0] = 1;
    for(int i = 1;  i < 18; i ++)
        rem[i] = rem[i-1] * 10;
    while(T --){
        ll n, x, tx, ans = 0;
        scanf("%lld%lld", &n, &x);
        ll tmp = 0; tx = x;
        for(; rem[tmp] <= x; tmp ++);
        while(n > tmp * (rem[tmp] - tx)){
            ans += (rem[tmp] - tx);
            n -= tmp * (rem[tmp] - tx);
            tx = rem[tmp];
            tmp ++;
        }
        if(n % tmp == 0)
            ans += n / tmp;
        else ans = -1;
        printf("%lld\n", ans);
    }
}
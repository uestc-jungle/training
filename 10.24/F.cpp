#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n, m, ans;
int main(){
    int T;
    scanf("%d", &T);
    while(T --){
        ans = 0;
        scanf("%lld%lld", &n, &m);
        m = min(m, n*(n-1)/2);
        if(m < n){
            ans += (n-(m+1)) * (n-(m+1)-1) * n;
            ans += (m+1) * (n-(m+1)) * 2 * n;
            ans += (m-1) * m * 2;
            ans += m * 2;
        }
        else{
            ans += (n-1) * (n-2) * 2;
            ans += (n-1) * 2;
            ans -= (m-(n-1)) * 2;
        }
        printf("%lld\n", ans);
    }
}
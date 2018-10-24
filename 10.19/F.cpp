#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int maxn = 4096;
struct node{
    ll s, k;
    bool operator < (const node &tx) const{
        return (s+tx.s)*(k - tx.k) > k*s - tx.k * tx.s;
    }
}a[maxn];

int main(){
    int T;
    scanf("%d", &T);
    while(T --){
        ll k1, k2, c; int n, m;
        scanf("%lld%lld%lld%d%d", &k1, &k2, &c, &n, &m);
        for(int i = 1; i <= n; i ++){
            scanf("%lld", &a[i].s);
            a[i].k = k1;
        }
        for(int i = 1; i <= m; i ++){
            scanf("%lld", &a[i + n].s);
            a[i+n].k = k2;
        }
        sort(a+1, a+1+n+m);
        ll ans = 0;
        for(int i = 1; i <= n+m; i ++)
            printf("%d -- %d\n", a[i].s, a[i].k);
        for(int i = 1; i <= n+m; i ++){
            if(a[i].s > c) break;
            c -= a[i].s;
            ans += c * a[i].k;
        }
        printf("%lld\n", ans);
    }
}

/*

4 7
1 4 6

2 3 5
3 5 8 9

2
1

*/
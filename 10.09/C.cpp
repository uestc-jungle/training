#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int maxn = 301010;
struct Edge{
    ll x, y;
    bool operator < (const Edge &tx) const{
        if(x != tx.x) return x < tx.x;
        return y < tx.y;
    }
}a[maxn], b[maxn];
int tree[maxn];
int lowbit(int x){ return x & (-x);}

void addv(int x){
    for(int i = x; i > 0; i -= lowbit(i))
        tree[i] ++;
}

ll sumv(int x){
    ll ans = 0;
    for(int i = x; i < maxn; i += lowbit(i)){
        ans += tree[i];
    }
    return ans;
}
int cnta, cntb;
int rem_a[maxn], rem_b[maxn];
int main(){
    int tx, ty;
    ll n, m;
    scanf("%d%d", &tx, &ty);
    scanf("%lld%lld", &n, &m);
    for(int i = 1; i <= n; i ++){
        scanf("%lld%lld", &a[i].x, &a[i].y);
        rem_a[++ cnta] = a[i].x;
        rem_a[++ cnta] = a[i].y;
    }
    for(int i = 1; i <= m; i ++){
        scanf("%lld%lld", &b[i].x, &b[i].y);
        rem_b[++ cntb] = b[i].x;
        rem_b[++ cntb] = b[i].y;
    }
    sort(a+1, a+1+n);
    sort(b+1, b+1+m);
    sort(rem_a+1, rem_a+1+cnta);
    sort(rem_b+1, rem_b+1+cntb);
    cnta = unique(rem_a+1, rem_a+1+cnta) - (rem_a+1);
    cntb = unique(rem_b+1, rem_b+1+cntb) - (rem_b+1);
    for(int i = 1; i <= n; i ++){
        a[i].x = lower_bound(rem_a+1, rem_a+1+cnta, a[i].x) - rem_a;
        a[i].y = lower_bound(rem_a+1, rem_a+1+cnta, a[i].y) - rem_a;
    }
    for(int i = 1; i <= m; i ++){
        b[i].x = lower_bound(rem_b+1, rem_b+1+cntb, b[i].x) - rem_b;
        b[i].y = lower_bound(rem_b+1, rem_b+1+cntb, b[i].y) - rem_b;
    }
    ll ans = (n+1) * (m+1);
    for(int i = 1; i <= n; i ++){
        ans += sumv(a[i].y);
        addv(a[i].y);
    }
    // return 0;
    memset(tree, 0, sizeof(tree));
    for(int i = 1; i <= m; i ++){
        ans += sumv(b[i].y);
        addv(b[i].y);
    }
    printf("%lld", ans);
    
}
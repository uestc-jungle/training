#include<bits/stdc++.h>
using namespace std;
const int maxn = 101010;
struct node{
    int x, y, val;
    bool operator < (const node &tx) const{
        return val < tx.val;
    }
}e[maxn];
int fat[maxn];
int n, m, T, cnt;
int find(int x) { return fat[x] == 0 ? x : (fat[x] = find(fat[x]));}
int Kruscal(int s, int t, int dir){
    memset(fat, 0, sizeof(int) * (n+1));
    int ans = 0;
    for(int i = s; i != t; i += dir){
        int tx = find(e[i].x), ty = find(e[i].y);
        if(tx == ty) continue;
        fat[tx] = ty;
        ans += e[i].val;
    }
    for(int i = 1; i <= n; i ++){
        if(find(i) != find(1)) return -1;
    }
    return ans;
}
int fib[10101];
int main(){
    scanf("%d", &T);
    fib[0] = fib[1] = 1;
    for(int i = 2; fib[i-1] <= 3e5; i ++){
        fib[i] = fib[i-1] + fib[i-2];
        cnt = i;
    }
    int cas = 0;
    while(T --){
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= m; i ++){
            scanf("%d%d%d", &e[i].x, &e[i].y, &e[i].val);
        }
        sort(e+1, e+1+m);
        int minv = Kruscal(1, m+1, 1);
        int maxv = Kruscal(m, 0, -1);
        int tp = *lower_bound(fib+1, fib+1+cnt, minv);
        bool flag = false;
        if(minv <= tp && tp <= maxv)
            flag = true;
        printf("Case #%d: %s", ++ cas, (flag ? "Yes\n" : "No\n"));
    }
}
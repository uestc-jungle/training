#include<bits/stdc++.h>
using namespace std;
struct Edge{
    int tx, ty, num;
    int val;
    bool operator < (const Edge &tem) const{
        return tx < tem.tx;
    }
}e[1024], tem;
int n, cnt, m, ce;
int vis[4048][1030], c[16];
int rem[4096], dp[4048][1030];
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i ++){
        scanf("%d", &m);
        for(int j = 1; j <= m; j ++){
            ++ cnt;
            scanf("%d%d%d", &e[cnt].tx, &e[cnt].ty, &e[cnt].val);
            e[cnt].num = i;
            rem[++ce] = e[cnt].tx;
            rem[++ce] = e[cnt].ty;
        }
        c[i] = m;
    }
    sort(e+1, e+1+cnt);
    sort(rem+1, rem+1+ce);
    ce = unique(rem+1, rem+1+ce) - (rem + 1);

    for(int i = 1; i <= cnt; i ++){
        e[i].tx = lower_bound(rem+1, rem+1+ce, e[i].tx) - rem;
        e[i].ty = lower_bound(rem+1, rem+1+ce, e[i].ty) - rem;
    }
    // for(int i = 1; i <= cnt; i ++){
    //     printf("%d %d  ", e[i].tx, e[i].ty);
    // }
    // printf("debug : %d\n", ce);
    vis[1][0] = 1;
    for(int i = 1; i <= ce; i ++){
        for(int j = 0; j <  )
    }
    // for(int i = 1; i <= ce; i ++){
    //     for(int j = 0; j < (1<<n); j ++){
    //         printf("%d ", dp[i][j]);
    //     }
    //     puts("");
    // }
    printf("%d", dp[ce][(1<<n)-1] > 0 ? dp[ce][(1<<n)-1] : -1);
}
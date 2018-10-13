#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int maxn = 201010;
int tx, ty, n, vis[maxn];
vector<int> v[maxn];
ll num[maxn], dis[maxn], fat[maxn];
int dis_0[maxn], dis_1[maxn];
void dfs1(int x, int fath){
    vis[x] = 1;
    int siz = v[x].size();
    fat[x] = fath;
    for(int i = 0; i < siz; i ++){
        if(vis[v[x][i]]) continue;
        dfs1(v[x][i], x);
        num[x] += num[v[x][i]];
        dis[x] += dis[v[x][i]] + num[v[x][i]];
        dis_0[x] += dis_1[v[x][i]];
        dis_1[x] += dis_0[v[x][i]] + 1;
    }
    num[x] ++;
}

void dfs2(int x){
    int siz = v[x].size();
    vis[x] = 1;
    if(x != 1){
        dis[x] = dis[fat[x]] + (n - num[x]) - num[x];
        dis_0[x] = dis_1[fat[x]] - (dis_0[x] + 1) + dis_0[x]; //
        dis_1[x] = dis_0[fat[x]] + 1; // 
    }
    for(int i = 0; i < siz; i ++){
        if(vis[v[x][i]]) continue;
        dfs2(v[x][i]);
    }
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i < n; i ++){
        scanf("%d%d", &tx, &ty);
        v[tx].push_back(ty);
        v[ty].push_back(tx);
    }
    dfs1(1, 0);
    memset(vis, 0, sizeof(vis));
    dfs2(1);
    ll ans = 0, cnt = 0;
    for(int i = 1; i <= n; i ++){
        ans += dis[i];
        cnt += dis_1[i];
    }
    // for(int i = 1; i <= n; i ++){
    //     printf("%d ", dis_1[i]);
    // }
    // return 0;
    cnt /= 2; ans /= 2;
    // printf("\n%lld %lld\n", ans, cnt);
    // cout << cnt << endl;
    printf("%lld", (ans / 2) - cnt/2 + cnt);
}
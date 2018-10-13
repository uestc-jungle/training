#include<bits/stdc++.h>
using namespace std;
const int maxn = 251010;
int n, tx, ty;
vector<int> v[maxn];
int dis[maxn]; bool visit[maxn];
int posi[maxn];
int fat[maxn];
int tem[maxn], rem[maxn];
int d0[maxn];
void dfs1(int x, int tem_d, int tfat){
    visit[x] = true;
    fat[x] = tfat;
    dis[x] = tem_d;
    int siz_ = v[x].size();
    for(int i = 0 ; i < siz_; i ++){
        ty = v[x][i];
        if(visit[ty]) continue;
        dfs1(ty, tem_d + 1, x);
    }
}

void dfs2(int x, int fat_d, int tem_dis){
    visit[x] = true;
    if(posi[x]){
        fat_d = x;
        tem_dis = 0;
    }
    d0[fat_d] = max(d0[fat_d], tem_dis);
    int siz_ = v[x].size();
    for(int i = 0 ; i < siz_; i ++){
        ty = v[x][i];
        if(visit[ty]) continue;
        dfs2(ty, fat_d, tem_dis);
    }
}

int main(){
    int T;
    scanf("%d", &T);
    while(T --){
        scanf("%d", &n);
        for(int i = 1; i <= n; i ++){
            v[i].clear();
        }
        memset(visit, 0, sizeof(visit));
        for(int i = 1; i < n; i ++){
            scanf("%d%d", &tx, &ty);
            v[tx].push_back(ty);
            v[ty].push_back(tx);
        }
        dfs1(1, 0, 0);
        int d1 = 0, pd1 = 0;
        for(int i = 1; i <= n; i ++){
            if(dis[i] > d1) d1 = dis[i], pd1 = i;
        }
        memset(dis, 0, sizeof(dis));
        memset(visit, 0, sizeof(visit));
        // memset(fat, 0, sizeof(fat));
        memset(d0, 0, sizeof(d0));
        int d2 = 0, pd2 = 0;
        dfs1(pd1, 0, 0);
        for(int i = 1; i <= n; i ++){
            if(dis[i] > d2) d2 = dis[i], pd2 = i;
        }// 直径求取完毕
        int tp = pd2, cnt = 0;
        fat[pd1] = 0;
        while(tp){
            tem[++ cnt] = tp;
            tp = fat[tp];
        } // 抽取主链

        memset(visit, 0, sizeof(visit));
        memset(posi, 0, sizeof(posi));
        dfs2(pd1, pd1, 0);

        for(int i = 1; i <= n; i ++){
            rem[i] = tem[cnt + 1 - i];
            posi[rem[i]] = i;
        } // pd1 为根， 且 pd1 为rem主链 左边




        int maxv1 = 0, ans_p1 = 0;
        int maxv2 = 0, ans_p2 = 0;
        int maxv = 0;
        for(int i = 1; i <= (cnt + 1) / 2; i ++){
            if((d0[rem[i]] + i) / 2 > maxv1)
                maxv1 = (d0[rem[i]] + i) / 2, ans_p1 = rem[maxv1 + 1];
        }

        for(int i = 1; i <= (cnt + 1) / 2; i ++){
            if((d0[rem[cnt + 1 - i]] + i) / 2 > maxv2)
               maxv2 = (d0[rem[cnt + 1 - i]] + i) / 2, ans_p2 = rem[cnt - maxv2];
        }
        // puts("Debug:");
        // for(int i = 1; i <= cnt; i  ++){
        //     printf("%d ", rem[i]);
        // }
        
        // cout << pd1 << "  " << pd2 << endl;s
        // for(int i = 1; i <= n; i ++){
        //     tx = find_lca(i, ans_p1);
        //     ty = find_lca(i, ans_p2);
        //     maxv = max(maxv, min(dis[i] + dis[ans_p1] - 2 * dis[tx], dis[i] + dis[ans_p2] - 2 * dis[ty]));
        // }
        maxv = max(maxv1, maxv2);
        if(ans_p1 == ans_p2)  ans_p2 = 1;
        if(ans_p1 == ans_p2)  ans_p2 = n;
        printf("%d %d %d\n", maxv, ans_p1, ans_p2);
    }
}

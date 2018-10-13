#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll inf = 512;
struct node{
    int maxv, posi;
    node(int tmax=0, int tpos=0):maxv(tmax), posi(tpos){}
    bool operator < (const node &tx) const{
        return maxv < tx.maxv;
    }
}e[512][512];
int T, n, ch[512][512];
int reml[512], remr[512];
deque<node> q;

ll work(){
    ll sum = 0;
    for(int dow = 1; dow <= n; dow ++){
        for(int j = 1; j <= n; j ++){
            e[dow][j].posi = j;
            e[dow][j].maxv = -inf;
        }
        for(int up = dow; up > 0; up --){
            for(int p = 1; p <= n; p ++){
                e[dow][p].maxv = max(e[dow][p].maxv, ch[up][p]);
            }
            while(!q.empty()) q.pop_back();
            q.push_back(node(inf, 0));
            e[dow][n+1].maxv = inf - 1;
            e[dow][n+1].posi = n+1;
            for(int r = 1; r <= n+1; r ++){
                while(!q.empty() && q.back() < e[dow][r]){
                    remr[q.back().posi] = r - q.back().posi;
                    q.pop_back();
                }
                reml[r] = r - q.back().posi;
                q.push_back(e[dow][r]);
            }

            // while(!q.empty()) q.pop_back();
            // q.push_back(node(inf, n+1));
            // for(int l = n; l > 0; l --){
            //     while(!q.empty() && q.back() < e[dow][l][up]) q.pop_back();
            //     remr[l] = q.back().posi - l;
            //     q.push_back(e[dow][l][up]);
            // }

            for(int p = 1; p <= n; p ++){
                sum += e[dow][p].maxv * (reml[p] * remr[p]);
                // printf("%d ", reml[p] * remr[p]);
            }
            // puts("");
        }
    }
    // printf("Debug : %lld\n", sum);
    return sum;
}

int main(){
    scanf("%d", &T);
    while(T --){
        scanf("%d", &n);
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= n; j ++)
                scanf("%d", &ch[i][j]);
        }
        ll ans = work();
    
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= n; j ++)
                ch[i][j] = -ch[i][j];
        }
        ans += work();
        printf("%lld\n", ans);
    }
}

/*
3
1 8 1
2 4 9
2 4 5
*/
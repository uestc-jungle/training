#include<bits/stdc++.h>
using namespace std;
const int maxn = 512;
const int maxm = 256;

vector<int> g[maxn];
int from[maxn];
bool use[maxn];

bool match(int x){
    for(int i = 0; i < g[x].size(); ++ i){
        if(!use[g[x][i]]){
            use[g[x][i]] = true;
            if(from[g[x][i]] == -1 || match(from[g[x][i]])){
                from[g[x][i]] = x;
                return true;
            }
        }
    }
    return false;
}

int hungary(){
    int tot = 0;
    memset(from, 255, sizeof(from));
    for(int i = 1; i <= maxm; i ++){
        memset(use, 0, sizeof(use));
        if(match(i)) ++ tot;
    }
    return tot;
}
const int upp = 50;
int main(){
    for(int s = 1; s <= upp; s ++){
        for(int n = 1; n <= upp; n ++){
            for(int n = 1; n <= upp; n ++){
                g[n].clear();
            }
            for(int x = 1; x <= n; x ++)
                for(int k = 1; k <= n; k ++){
                    if((s+x) % k) continue;
                    g[x].push_back(k+maxm);
                // g[k+maxm].push_back(n);
                }
            int ans = 0;
            if(hungary() == n)
                ans = 1;
            printf("%d", ans);
        }
        puts("");
    }
}
#include<bits/stdc++.h>
using namespace std;
const int maxn = 2010100;
int n, m;
int cal(int x, int y){ return x * m + y; }
void re_cal(int num, int& x, int& y){
    x = num / m;
    y = num % m;
}
int vis[maxn], rem[maxn], fat[maxn];
char ch[maxn]; int cnt0[maxn], cnt1[maxn];
vector<int> v[maxn];
queue<int> q;
void bfs(int tem_x){
    q.push(tem_x);
    while(!q.empty()){
        int temp = q.front(); q.pop();
        int siz = v[temp].size();
        for(int i = 0; i < siz; i ++){
            if(vis[v[temp][i]]) continue;
            
        }
    }
    cnt1[tem_x];
    cnt0[tem_x];
}

int main(){
    int T;
    scanf("%d", &T);
    while(T --){
        scanf("%d%d", &n, &m);
        memset(fat, -1, sizeof(int) * (n+1) * (m+1));
        memset(rem, 0, sizeof(int) * (n+1)*(m+1));
        memset(vis, 0, sizeof(int) * (n+1)*(m+1));
        memset(cnt0, 0, sizeof(int) * (n+1) * (m+1));
        for(int i = 0; i < n*m; i ++)
            v[i].clear();
        
        for(int i = 0; i < n; i ++){
            scanf("%s", ch[i]);
            int tem_flag = 0;
            for(int j = 0; j < m; j ++){
                if(ch[i] != 'X') continue;
                if(tem_flag){
                    v[tem_flag].push_back(cal(i, j));
                    v[cal(i, j)].push_back(tem_flag);
                }
                int tp = (i + j) % n;
                if(rem[tp]){
                    v[rem[tp]].push_back(cal(i, j));
                    v[cal(i, j)].push_back(rem[tp]);
                }
                else 
                    rem[tp] = cal(i, j);
            }
        }
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < m; j ++){
                if(vis[cal(i, j)]) continue;
                bfs(cal(i, j));
            }
        }
    }
}
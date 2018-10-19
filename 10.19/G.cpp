#include<bits/stdc++.h>
using namespace std;
const int maxn = 1001010;
int vis[maxn][2]; int stu[maxn];
int n, m, sx, sy, tx, ty;
int cal(int x, int y){ return x * m + (y - 1); }

void re_cal(int num, int& x, int& y){
    x = num / m;
    y = (num % m) + 1;
}

queue<pair<int, int> > q;

int main(){
    int T, ans;

    // n = 2, m = 3;
    // cal(2, 3);
    // int tx, ty;
    // re_cal(cal(2, 3), tx, ty);
    // printf("%d %d", tx, ty);
    // return 0;

    scanf("%d", &T);
    while(T --){
        ans = -1;
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= m; j ++){
                scanf("%d", &stu[cal(i, j)]);
            }
        }
        scanf("%d%d%d%d", &sx, &sy, &tx, &ty);
        q.push(make_pair(cal(sx, sy), 0));
        vis[cal(sx, sy)][0] = T + 1;

        while(!q.empty()){
            pair<int, int> pii = q.front(); q.pop();
            int num = pii.first;
            int tim = pii.second;
            
            int tem_x, tem_y;
            re_cal(num, tem_x, tem_y);
            if(tem_x == tx && tem_y == ty){
                ans = tim;
                break;
            }
            int t_tim = tim & 1;
            if((t_tim + stu[num]) % 2 == 1){
                if(tem_y + 1 <= m && vis[cal(tem_x, tem_y+1)][!t_tim] != T + 1){
                    vis[cal(tem_x, tem_y+1)][!t_tim] = T + 1;
                    q.push(make_pair(cal(tem_x, tem_y+1), tim + 1));
                }
                if(tem_y - 1 > 0 && vis[cal(tem_x, tem_y - 1)][!t_tim] != T + 1){
                    vis[cal(tem_x, tem_y-1)][!t_tim] = T + 1;
                    q.push(make_pair(cal(tem_x, tem_y-1), tim + 1));
                }
            }
            else{
                if(tem_x + 1 <= n && vis[cal(tem_x + 1, tem_y)][!t_tim] != T + 1){
                    vis[cal(tem_x+1, tem_y)][!t_tim] = T + 1;
                    q.push(make_pair(cal(tem_x+1, tem_y), tim + 1));
                }
                if(tem_x - 1 > 0 && vis[cal(tem_x - 1, tem_y)][!t_tim] != T + 1){
                    vis[cal(tem_x-1, tem_y)][!t_tim] = T + 1;
                    q.push(make_pair(cal(tem_x-1, tem_y), tim + 1));
                }
            }

        }
        printf("%d\n", ans);
        while(!q.empty()) q.pop();
    }
}
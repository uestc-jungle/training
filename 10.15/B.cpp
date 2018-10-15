#include<bits/stdc++.h>
using namespace std;
typedef double db;

int T, n, m;
double ave, tn;

db cal(db val, db num){
    return num / tn * (val / num - ave) * (val / num - ave);
}

struct Node{
    int num; 
    db val;
    bool operator < (const Node &tx) const{
        double addv1 = cal(val, num) - cal(val, num + 1);
        double addv2 = cal(tx.val, tx.num) - cal(tx.val, tx.num + 1);
        return addv1 < addv2;
    }
}a[201010];

priority_queue<Node> q;

int main(){
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++){
        scanf("%d%d", &m, &n);
        tn = n;
        while(!q.empty()) q.pop();
        db sum = 0;
        for(int i = 1; i <= m; i ++){
            scanf("%lf", &a[i].val);
            a[i].num = 1;
            sum += a[i].val;
        }
        ave = sum / n;

        for(int i = 1; i <= m; i ++)    q.push(a[i]);

        // while(!q.empty()){
        //     printf("%lf %d\n", q.top().val, q.top().num);
        //     q.pop();
        // }
        // puts("");
        // continue;

        for(int i = 1; i <= n - m; i ++){
            // printf("Debug : %lf %d\n", q.top().val, q.top().num);
            Node tem_x = q.top(); q.pop();
            tem_x.num ++;
            q.push(tem_x);
        }

        db ans = 0;
        while(!q.empty()){
            Node tem_x = q.top(); q.pop();
            ans += cal(tem_x.val, tem_x.num);
        }
        printf("Case #%d: %.9lf\n", cas, ans);
    }
}
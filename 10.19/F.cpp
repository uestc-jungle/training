#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int maxn = 4096;

ll s1[maxn], s2[maxn];
ll k1, k2, c, ans;
ll sum1[maxn], sum2[maxn];
int n, m;

void proc(int x, int y){
    ll tem_ans = 0, tem_cap = c, tem;
    int p1 = 0, p2 = 0, flag;
    while(p1 != x || p2 != y){
        if(p1 == x){
            flag = 1;
            tem = (tem_cap - s2[p2+1]) * k2;
            tem_ans += tem;
            p2 ++; tem_cap -= s2[p2];
        }
        else if(p2 == y){
            flag = 2;
            tem = (tem_cap - s1[p1+1]) * k1;
            tem_ans += tem;
            p1 ++; tem_cap -= s1[p1];
        }
        else{
            flag = 3;
            // if((s1[p1+1] + s2[p2+1]) * (k1 - k2) > (k1 * s1[p1+1] - k2 * s2[p2 + 1]))
            //     p1 ++, tem_cap -= s1[p1];
            // else 
            //     p2 ++, tem_cap -= s2[p2];
            if((tem_cap - s1[p1 + 1]) * k1 + (tem_cap - s1[p1 + 1] - s2[p2 + 1]) * k2 >  (tem_cap - s2[p2 + 1]) * k2 + (tem_cap - s1[p1 + 1] - s2[p2 + 1]) * k1)
                tem_ans += (tem_cap - s1[p1+1]) * k1, p1 ++, tem_cap -= s1[p1];
            else 
                tem_ans += (tem_cap - s2[p2+1]) * k2, p2 ++, tem_cap -= s2[p2];
        }
        // printf("Debug : %d --> %lld\n", flag, tem);
    }
    ans = max(ans, tem_ans);
}

int main(){
    int T;
    scanf("%d", &T);
    while(T --){
        scanf("%lld%lld%lld%d%d", &k1, &k2, &c, &n, &m);
        for(int i = 1; i <= n; i ++){
            scanf("%lld", &s1[i]);
        }
        for(int i = 1; i <= m; i ++){
            scanf("%lld", &s2[i]);
        }
        ans = 0;
        
        sort(s1+1, s1+1+n);
        for(int i = 1; i <= n; i ++)
            sum1[i] = sum1[i-1] + s1[i];
        
        sort(s2+1, s2+1+m);
        for(int i = 1; i <= m; i ++)
            sum2[i] = sum2[i-1] + s2[i];
        
        // for(int i = 1; i <= n; i ++)
        //     printf("%lld ", sum1[i]);
        // puts("");
        // for(int i = 1; i <= m; i ++)
        //     printf("%lld ", sum2[i]);
        // puts("\n");
        for(int i = 0; i <= n; i ++){
            if(sum1[i] > c) break;
            int p2 = upper_bound(sum2+1, sum2+1+m, c-sum1[i]) - sum2 - 1;
            // printf("Debug : %d -- %d\n", i, p2);
            proc(i, p2);
            // printf("Debug : %lld\n", ans);
            // puts("");
        }
        printf("%lld\n", ans);
    }
}

/*

4 7
1 4 6

2 3 5
3 5 8 9

2
1

*/
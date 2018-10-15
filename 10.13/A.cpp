#include<bits/stdc++.h>
using namespace std;
int n, d;
int a[1024];
int diff[1024];
int main(){
    while(scanf("%d", &n) && n){
        scanf("%d", &d);
        for(int i = 1; i <= n; i ++){
            scanf("%d", &a[i]);
        }

        bool flag = true; int cnt = 0;
        for(int i = 1; i < n; i ++){
            diff[i] = abs(a[i] - a[i+1]);
            if(diff[i] > d)
                cnt ++, flag = false;
        }
        
        if(flag){
            printf("Y\n");
            continue;
        }


        for(int i = 2; i < n; i ++){
            if(min(a[i-1] + d, a[i+1] + d) >= max(a[i-1]-d, a[i+1]-d)){
                int t_cnt = cnt;
                if(diff[i-1] > d){
                    t_cnt --;
                }
                if(diff[i] > d)
                    t_cnt --;
                if(t_cnt == 0)
                    flag = true;
            }
        }

        if(flag){
            printf("Y\n");
            continue;
        }
        printf("N\n");

    }
}
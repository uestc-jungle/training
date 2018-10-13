#include<bits/stdc++.h>
using namespace std;
int a[1024];
int main(){
    int n;
    while(scanf("%d", &n) && n){
        for(int i = 1; i <= n; i ++)
            scanf("%d", &a[i]);
        
        for(int i = 1; i <= n; i ++)
            a[i+n] = a[i];

        int ans = 0;
        for(int i = 1; i <= n; i ++){
            int ans1=0, ans2 = 0;
            bool flag1 = true, flag2 = true;
            for(int j = i+1; j <  n+i; j ++){
                if(a[j-1] < a[j] && flag1)   ans1 ++;
                else flag1 = false;

                if(a[j-1] > a[j] && flag2) ans2 ++;
                else flag2 = false;
            }
            ans = max(ans, max(ans1, ans2));
        }
        printf("%d\n", ans);
    }
}
/*

4
1 1 1 1
8
5 1 2 3 4 5 6 2
6
5 4 3 2 1 2
10
1 0 2 3 2 2 3 4 3 2
0

*/
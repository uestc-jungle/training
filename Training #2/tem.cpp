#include<bits/stdc++.h>
using namespace std;
int n, m;
int a[100], b[100];

int main(){
    int T;
    scanf("%d", &T);
    while(T --){
        scanf("%d%d", &n, &m);
        int sum1=0, sum2=0;
        for(int i = 1; i < n; i ++)
            scanf("%d", &a[i]), sum1 += a[i];
        for(int i = 1; i <= m; i ++)
            scanf("%d", &b[i]), sum2 += b[i];
        int ans1, ans2;
        ans1 = sum1 / (n-1);
        if(sum1 % (n-1) == 0){
            ans1 --;
        }
        ans2 = (sum2 + m - 1) / m;
        if(sum2 % m == 0)
            ans2 ++;
        printf("%d %d\n", ans2, ans1);
    }
    return 0;
}
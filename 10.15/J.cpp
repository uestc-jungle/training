#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int maxn = 201010;
int a[maxn], rem[maxn];
int p1, p2, T, n;
int main(){
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++){
        int tem1 = 0, tem2 = 0;
        p1 = p2 = 0;
        scanf("%d", &n);
        memset(rem, 0, sizeof(int) * (n+10));
        memset(a, 0, sizeof(int) * (n+10));
        
        a[n+1] = 2e9 + 11;
        
        for(int i = 1; i <= n; i ++)
            scanf("%d", &a[i]);

        bool flag = true;
        
        while(true){
            while(tem2 <= a[p2+1] && p2 <= n){
                tem2 = a[p2+1], p2 ++;
            } // p2 == n ?
            while(a[p1] - tem1 == 0 && p1 <= n){
                tem1 -= rem[p1];
                p1 ++;
            }
            // printf("%d %d\n", p1, p2);
            if(p1 == p2 && p1 > n) break;
            if(min(p2, n) - p1 + 1 < 3){
                flag = false;
                break;
            }
            // if((++cou) > 4) break;
            // printf("%d ", a[p1] - tem1);
            // printf("")
            rem[p2] += min(a[p1] - tem1, abs(tem2 - a[p2+1]));
            tem1 += min(a[p1] - tem1, abs(tem2 - a[p2+1]));
            tem2 = a[p2] - rem[p2];
            // printf("tem1 : %d\n", tem1);
        }
        printf("Case #%d: %s\n", cas, flag ? "Yes" : "No");
    }
}
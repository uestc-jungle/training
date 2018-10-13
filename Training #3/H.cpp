#include<bits/stdc++.h>
using namespace std;
typedef long double ld;
char ch[30][30] = {"B", "KB", "MB", "GB", "TB", "PB", "EB", "ZB", "YB" };
int main(){
    int T; int cnt = 0;
    scanf("%d", &T);
    while(T --){
        int n; char tem[10];
        scanf("%d[%s", &n, tem);
        tem[strlen(tem) - 1] = '\0';
        // printf("%s\n", tem);
        int p = 0; double ans = 1.0;
        while(strcmp(ch[p], tem) != 0){
            ans *= (1000.0) / 1024.0;
            p ++;
            // printf("%s: %.2Lf%%\n", ch[p], (1.0 - ans) * 100.0);
        }
        printf("Case #%d: %.2f%%\n", ++cnt, 100 - (ans) * 100.0);
    }
}
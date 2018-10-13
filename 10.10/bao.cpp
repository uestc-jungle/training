#include<bits/stdc++.h>
using namespace std;
int ch[128][128], n;
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++){
            scanf("%d", &ch[i][j]);
        }
    }
    int ans = 0, ans1=0, ans2=0;
    for(int l = 1; l <= n; l ++){
        for(int r = l; r <= n; r ++){
            for(int u = 1; u <= n; u ++){
                for(int d = u; d <= n; d ++){
                    int minv = 101010;
                    int maxv = -101010;
                    for(int p1 = l; p1 <= r; p1 ++){
                        for(int p2 = u; p2 <= d; p2 ++){
                            minv = min(minv, ch[p1][p2]);
                            maxv = max(maxv, ch[p1][p2]);
                        }
                    }
                    ans1 += maxv;
                    ans2 += minv;
                    ans += maxv - minv;
                }
            }
        }
    }
    printf("%d   %d   %d", ans1, ans2, ans);
}
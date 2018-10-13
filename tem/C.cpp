#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int maxn = 2048;
const int maxm = 2048 * 2048;
int rema[maxm];
int a[maxn], b[maxn];
int suma[maxn], sumb[maxn];
int n, m, x;
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i ++){
        scanf("%d", &a[i]);
    }
    for(int i = 1; i <= m; i ++){
        scanf("%d", &b[i]);
    }
    scanf("%d", &x);
    for(int i = 1; i <= n; i ++){
        ll tem = 0;
        for(int j = i; j <= n; j ++){
            tem += a[j];
            rema[tem] = max(rema[tem], j - i + 1);
        }
    }
    for(int i = 1; i < maxm; i ++){
        rema[i] = max(rema[i-1], rema[i]);
    }

    int ans = 0;
    for(int i = 1; i <= m; i ++){
        int tem = 0;
        for(int j = i; j <= m; j ++){
            tem += b[j];
            int p = min(x/tem, maxm-1);
            ans = max(ans, rema[p] * (j-i+1));
        }
    }
    printf("%d", ans);
}
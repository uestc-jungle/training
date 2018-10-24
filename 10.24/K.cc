#include <bits/stdc++.h>
using namespace std;
const int maxn=100005;
int a[maxn];

int main() {
    int cas;
    scanf("%d",&cas);
    while (cas--) {
        int n,k;
        scanf("%d%d",&n,&k);
        for (int i=1;i<=n;i++) scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        int i,ans=1;
        for (i=n-1;i>=1;i--) {
            if (a[i+1]-a[i]>k) break;
            ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
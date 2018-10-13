#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int cas,t=0;
    scanf("%d",&cas);
    while (cas--) {
        int n;
        scanf("%d",&n);
        ll x;bool flag=1;
        for (int i=1;i<=n;i++) {
            scanf("%lld",&x);
            if (x%3!=0) flag=0;
        }
        t++;
        printf("Case #%d: ",t);
        if (flag) printf("Yes\n"); else printf("No\n");
    }
}
#include<bits/stdc++.h>
#define mem0(a) memset(a,0,sizeof(a))
using namespace std;
const int maxn=10005;
int cnt[maxn];

int main() {
    int cas;
    scanf("%d",&cas);
    while (cas--) {
        int n,x;
        scanf("%d",&n);
        mem0(cnt);
        for (int i=1;i<=n*2;i++) {
            scanf("%d",&x);
            cnt[x%3]++;
        }
        int flag=1;
        if (cnt[0]>n) {
            flag=0;
        }
        if (cnt[0]<2&&cnt[1]>0&&cnt[2]>0) flag=0;
        if (flag) printf("YES\n"); else printf("NO\n");
    }
}
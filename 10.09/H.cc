#include <bits/stdc++.h>
#define mem0(a) memset(a,0,sizeof(a))
using namespace std;
const int maxn=1005;

struct wayne{
    int val,cla;
};
wayne a[maxn*3];
int cnt[maxn];

bool cmp(wayne a,wayne b) {
    return a.val<b.val;
}

int main() {
    int cas;
    scanf("%d",&cas);
    while (cas--) {
        int n,m,tot=0;
        scanf("%d%d",&n,&m);
        mem0(cnt);
        for (int i=1;i<=n*3;i++) {
            scanf("%d",&a[i].val);
            a[i].cla=(i-1)/3;
        }
        sort(a+1,a+n*3+1,cmp);
        int ans=0;
        for (int i=1;i<=n*3;i++) {
            cnt[a[i].cla]++;
            if (cnt[a[i].cla]==3) continue;
            if (tot==m) continue;
            tot++;ans+=a[i].val;
        }
        printf("%d\n",ans);
    }
}
#include<bits/stdc++.h>
#define mem0(a) memset(a,0,sizeof(a))
#define pb push_back
using namespace std;
const int maxn=1005;
int dp[maxn*2][maxn+30];

struct wayne {
    int l,r,w,f;
};
wayne a[maxn];

bool cmp(wayne a,wayne b) {
    return a.r<b.r;
}

int main() {
    int n,m,x;
    scanf("%d",&n);
    m=0;
    for (int i=1;i<=n;i++) {
        scanf("%d",&x);
        for (int j=1;j<=x;j++) {
            m++;
            scanf("%d%d%d",&a[m].l,&a[m].r,&a[m].w);
            a[m].f=i;
        }
    }
    sort(a+1,a+m+1,cmp);
    mem0(dp);
    int last=0;
    for (int i=1;i<=m;i++) {
        for ()
        for (int j=1;j<=;j++) {

        }
    }
}
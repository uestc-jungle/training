#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll cnt[10];

int main() {
    ll a,b,c,d,e;
    int cas,t=0;
    scanf("%d",&cas);
    while (cas--) {
        int n,x;
        t++;
        scanf("%lld%lld%lld%lld%lld",&a,&b,&c,&d,&e);
        memset(cnt,0,sizeof(cnt));
        scanf("%d",&n);
        for (int i=1;i<=n;i++) {
            scanf("%d",&x);
            if (x<=48) cnt[1]++; else 
            if (x<=56) cnt[2]++; else
            if (x<=60) cnt[3]++; else
            if (x<=62) cnt[4]++; else
            if (x<=63) cnt[5]++;
        }
        ll ans=cnt[1]*a+cnt[2]*b+cnt[3]*c+cnt[4]*d+cnt[5]*e;
        ans*=10000;
        printf("Case #%d: %lld\n",t,ans);
    }
}
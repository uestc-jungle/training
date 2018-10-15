#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=100005;
ll c[maxn],sum[maxn];

int main() {
    int cas,t=0;
    scanf("%d",&cas);
    while (cas--) {
        ll a,b,n;
        t++;
        scanf("%lld%lld%lld",&a,&b,&n);
        sum[0]=0;
        for (int i=1;i<=a;i++) {
            scanf("%lld",&c[i]);
            sum[i]=sum[i-1]+c[i];
        }
        for (int i=1;i<=n;i++) {
            ll na,nb;
            int pos=lower_bound(sum+1,sum+a+1,a)-sum;
            na=pos;
            if (sum[pos]<a) na++;
            nb=a-sum[na-1];
            if (a==na&&b==nb) {
                break;
            }
            a=na;b=nb;
        }
        printf("Case #%d: %lld-%lld\n",t,a,b);
    }
    return 0;
}
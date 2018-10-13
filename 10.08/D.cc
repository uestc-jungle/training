#include<bits/stdc++.h>
#define mem0(a) memset(a,0,sizeof(a))
typedef long long ll;
using namespace std;
const int maxn=100005,inf=0x3f3f3f3f;
const ll mod=998244353;
ll a[maxn];

ll fastpower(ll x, ll y){
    ll ans = 1;
    while(y){
        if(y & 1) ans = ans * x % mod;
        x = x * x % mod;
        y >>= 1;
    } 
    return ans;
}

int main() {
    int cas;
    scanf("%d",&cas);
    while (cas--) {
        int n;
        ll ans=0;
        scanf("%d",&n);
        for (int i=1;i<=n;i++) {
            scanf("%lld",&a[i]);
            ans+=a[i];
            ans%=mod;
        }
        ll sum=0;
        for (int i=n;i>1;i--) {
            sum=sum+a[i]*fastpower(i-1,mod-2);
            sum%=mod;
            ans=(ans+sum)%mod;
        }
        ans=ans*fastpower(n,mod-2)%mod;
        printf("%lld\n",ans);
    }
    return 0;
}


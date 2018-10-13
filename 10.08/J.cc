#include<bits/stdc++.h>
#define mem0(a) memset(a,0,sizeof(a))
typedef long long ll;
using namespace std;
const int maxn=100005,inf=0x3f3f3f3f;
const ll mod=998244353;
int a[maxn],b[maxn];

int main() {
    int cas;
    scanf("%d",&cas);
    while (cas--) {
        int n,m,x,y,z;
        ll ans=1;
        scanf("%d%d",&n,&m);
        mem0(a);mem0(b);
        for (int i=1;i<=m;i++) {
            scanf("%d%d%d",&x,&y,&z);
            if (z==2) {
                a[x]++;a[y+1]--;
            } else {
                b[x]++;b[y+1]--;
            }
        }
        int am,bm,suma,sumb;
        am=bm=inf;
        suma=sumb=0;
        for (int i=1;i<=n;i++) {
            suma+=a[i];sumb+=b[i];
            am=min(am,suma);
            bm=min(bm,sumb);
        }
        for (int i=1;i<=am;i++) ans=(ans*2)%mod;
        for (int i=1;i<=bm;i++) ans=(ans*3)%mod;
        printf("%lld\n",ans);
    }
    return 0;
}
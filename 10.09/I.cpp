#include<bits/stdc++.h>
#define mem0(a) memset(a,0,sizeof(a))
#define pb push_back
using namespace std;
const int maxn=1005;
int a[maxn];
vector<int> v[maxn];

int main() {
    int n,m,k,x;
    scanf("%d%d",&n,&m);
    mem0(a);
    scanf("%d",&k);
    for (int i=1;i<=1000;i++) a[i]=-1;
    for (int i=1;i<=k;i++) {
        scanf("%d",&x);
        a[x]=1;
    }
    for (int i=1;i<=n;i++) {
        scanf("%d",&k);
        for (int j=1;j<=k;j++) {
            scanf("%d",&x);
            v[i].pb(x);
            a[x]*=-1;
        }
        int cnt=0;
        for (int j=1;j<=m;j++) {
            if (a[j]==-1) cnt++;
        }
        if (cnt==m) {
            printf("%d\n",i);return 0;
        }
    }
    for (int i=1;i<=n;i++) {
        k=v[i].size();
        for (int j=0;j<k;j++) {
            a[v[i][j]]*=-1;
        }
        int cnt=0;
        for (int j=1;j<=m;j++) {
            if (a[j]==-1) cnt++;
        }
        if (cnt==m) {
            printf("%d\n",i+n);return 0;
        }
    }
    printf("-1");
}
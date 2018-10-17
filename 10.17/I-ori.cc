#include <bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
int a[10][10];
int k;

int rotate (int x,int y) {
    swap(a[x+1][y],a[x][y+1]);
    swap(a[x][y],a[x+1][y]);
    swap(a[x][y+1],a[x+1][y+1]);
    return a[x][y]+a[x+1][y]+a[x][y+1]+a[x+1][y+1];
}

void remedy (int x,int y) {
    swap(a[x][y],a[x+1][y]);
    swap(a[x][y+1],a[x+1][y+1]);
    swap(a[x+1][y],a[x][y+1]);
}

int dfs(int dep) {
    if (dep==k+1) return 0;
    int ans,sum;
    if (dep%2) ans=-inf; else ans=inf;
    for (int i=1;i<=3;i++) {
        for (int j=1;j<=3;j++) {
            sum=rotate(i,j);
            sum+=dfs(dep+1);
            if (dep%2) ans=max(ans,sum); else ans=min(ans,sum);
            remedy(i,j);
        }
    }
    return ans;
}

int main() {
    int cas;
    scanf("%d",&cas);
    while (cas--) {
        scanf("%d",&k);
        k*=2;
        for (int i=1;i<=4;i++) {
            for (int j=1;j<=4;j++) scanf("%d",&a[i][j]);
        }
        int ans=dfs(1);
        printf("%d\n",ans);
    }
}
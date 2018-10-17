#include <bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
int a[10][10];
int k;

void swap_t(int &x, int &y){ x ^= y ^= x ^= y;}

void rotate (int x,int y) {
    swap_t(a[x+1][y],a[x][y+1]);
    swap_t(a[x][y],a[x+1][y]);
    swap_t(a[x][y+1],a[x+1][y+1]);
}

int getsum(int x,int y) {
    return a[x][y]+a[x+1][y]+a[x][y+1]+a[x+1][y+1];
}

void remedy (int x,int y) {
    swap_t(a[x][y],a[x+1][y]);
    swap_t(a[x][y+1],a[x+1][y+1]);
    swap_t(a[x+1][y],a[x][y+1]);
}

int dfs(int dep) {
    int ans,sum;
    if (dep%2) ans=-inf; else ans=inf;
    for (int i=1;i<=3;i++) {
        for (int j=1;j<=3;j++) {
            rotate(i,j);
            sum=getsum(i,j);
            if (dep!=k) sum+=dfs(dep+1);
            if (dep%2) ans=max(ans,sum); else ans=min(ans,sum);
            if (dep!=k) remedy(i,j);
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
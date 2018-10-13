#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
int dp[205][105][6][6][2],head[105];
int p[105][10];
int num=0;

struct Edge{
    int from,to,pre,dist,cost;
};
Edge e[205];

void addedge (int from,int to,int dist,int cost) {
    num++;
    e[num].from=from;e[num].to=to;e[num].dist=dist;e[num].cost=cost;
    e[num].pre=head[from]; head[from]=num;
}

int main(){
    int T; int cn = 0;
    scanf("%d", &T);
    while(T --){
        int n,m,b,K,r,t,A,B,C,D;
        int ans=-1;
        num=0;memset(head,-1,sizeof(head));
        scanf("%d%d%d%d%d%d",&n,&m,&b,&K,&r,&t);
        memset(dp,-1,sizeof(dp));
        for (int i=0;i<K;i++) {
            for (int j=1;j<=n;j++) {
                scanf("%d",&p[i][j]);
            }
        }
        for (int i=1;i<=m;i++) {
            scanf("%d%d%d%d",&A,&B,&C,&D);
            addedge(A,B,C,D);
        }
        dp[0][1][0][0][0]=r;
        for (int i=0;i<=t;i++) {
            for (int q=0;q<2;q++) {
            for (int j=1;j<=n;j++) {
                for (int k=0;k<=b;k++) {
                    for (int l=0;l<K;l++) {
                            if (dp[i][j][k][l][q]==-1) continue;
                        cout << i << ' ' << q << ' ' << j << ' ' << k << ' ' << l << ' ' << dp[i][j][k][l][q] << endl;
                            if (j==n) {
                                if (l==0&&q==0) ans=max(ans,dp[i][j][k][l][q]);
                                continue;
                            }
                        //stay here
                            if (j!=1&&j!=n)
                                dp[1+i][j][k][(l+1)%K][0]=max(dp[1+i][j][k][(l+1)%K][0],dp[i][j][k][l][q]);
                            if (q==0&&j!=1&&j!=n) {
                                if (p[l][j]<=dp[i][j][k][l][q]&&k+1<=b) {
                                    dp[i][j][k+1][l][1]=max(dp[i][j][k+1][l][1],dp[i][j][k][l][q]-p[l][j]);
                                }
                                if (k>0) {
                                    dp[i][j][k-1][l][1]=max(dp[i][j][k-1][l][1],dp[i][j][k][l][q]+p[l][j]);
                                }
                            }
                            for (int s=head[j];s!=-1;s=e[s].pre) {
                                if (e[s].dist+i>t) continue;
                                int to=e[s].to;
                                if (dp[i][j][k][l][q]>=e[s].cost) dp[e[s].dist+i][to][k][l][0]=max(dp[e[s].dist+i][to][k][l][0],dp[i][j][k][l][q]-e[s].cost);
                            }
                        }
                    }
                }
            }
        }
        printf("Case #%d:", ++cn);
        if (ans==-1) printf(" Forever Alone\n"); else printf(" %d\n",ans);
    }
}
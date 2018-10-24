#include<bits/stdc++.h>
#define mem0(a) memset(a,0,sizeof(a))
using namespace std;
typedef long long ll;
const int maxn=105;
int d1[4][2]={{0,1},{1,-1},{1,0},{-1,1}};
const int d2[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
char s[maxn][maxn],ans[maxn][maxn];
int visit[maxn][maxn];

int main() {
    int n;
    while (scanf("%d",&n)!=EOF) {
        for (int i=1;i<=n;i++) {
            scanf("%s",s[i]+1);
        }
        mem0(visit);
        for (int i=0;i<=n+1;i++) {
            visit[0][i]=visit[n+1][i]=visit[i][0]=visit[i][n+1]=1;
        }
        int x,y,X,Y,d,D;
        x=y=X=Y=1;d=D=0;
        for (int i=1;i<=n*n;i++) {
            ans[X][Y]=s[x][y];
            assert(x<=n);assert(y<=n);
            assert(x>0);assert(y>0);
            assert(X<=n);assert(Y<=n);
            assert(X>0);assert(Y>0);
   //         cout << x << ' ' << y << ' ' << X << ' ' << Y << endl;
            visit[X][Y]=1;
            if (i==n*n) break;
            x+=d1[d][0];y+=d1[d][1];
            if (d==0||d==2) d++; else {
                if (d==1&&y==1&&i<=n*n/2) d++;
                if (d==1&&x==n&&i>n*n/2) d++;
                if (d==3&&x==1&&i<=n*n/2) d=0;
                if (d==3&&y==n&&i>n*n/2) d=0;
            }
            int nx,ny;
            nx=X+d2[D][0];ny=Y+d2[D][1];
            if (visit[nx][ny]) D=(D+1)%4;
            X+=d2[D][0];Y+=d2[D][1];
            if (i==n*n/2) {
                swap(d1[0],d1[2]);
            }
        }
        if (d1[0][0]==1) swap(d1[0],d1[2]);
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=n;j++) {
                printf("%c",ans[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
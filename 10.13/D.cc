#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mem0(a) memset(a,0,sizeof(a))
const int maxn=205;
vector<int> v[maxn];
int cnt[maxn],dist[maxn];
bool visit[maxn];

int main() {
    int n,m,x,y;
    while (scanf("%d",&n)!=EOF) {
        if (n==0) break;
        scanf("%d",&m);
        for (int i=1;i<=n;i++) v[i].clear();
        mem0(cnt);
        for (int i=1;i<=m;i++) {
            scanf("%d%d",&x,&y);
            x++;y++;
            v[x].pb(y);v[y].pb(x);
        }
        for (int i=1;i<=n;i++) {
            mem0(visit);mem0(dist);
            queue<int> q;
            q.push(i);visit[i]=1;
            while (!q.empty()) {
                int now=q.front();
                q.pop();
                int size=v[now].size();
                for (int j=0;j<size;j++) {
                    int to=v[now][j];
                    if (!visit[to]) {
                        visit[to]=1;
                        q.push(to);
                        dist[to]=dist[now]+1;
                        cnt[dist[to]]++;
                    }
                }
            }
        }
        int sum=0;
        for (int i=1;i<=n;i++) {
            sum+=cnt[i];
            printf("%d %d\n",i,cnt[i]);
            if (sum==n*(n-1)) break;
        }
    }
}
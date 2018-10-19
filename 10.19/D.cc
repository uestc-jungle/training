#include <bits/stdc++.h>
#define mem0(a) memset(a,0,sizeof(a));
using namespace std;
const int maxn=1000005;
bool cnt[maxn],rcnt[maxn],visit[maxn],d[maxn],R[maxn],D[maxn];
int head[maxn],x[maxn],y[maxn],X1[maxn],Y1[maxn];
char s[maxn];
int num=0;
int ca,cb,f1,f2,n,m;

struct Edge{
    int from,to,pre;
    bool dist;
};
Edge edge[maxn*4];

void addedge(int x,int y,bool dist) {
    edge[num].from=x;edge[num].to=y;edge[num].pre=head[x];
    edge[num].dist=dist;head[x]=num++;
    edge[num].from=y;edge[num].to=x;edge[num].pre=head[y];
    edge[num].dist=dist;head[y]=num++;
}

void bfs(int s) {
    queue<int> q;
    q.push(s);
    d[s]=0;ca=1;cb=0;
	visit[s]=1;
    while (!q.empty()) {
        int now=q.front();
        q.pop();
        rcnt[now/2]^=d[now];
        int tot=now/2;
        if (now%2==0) tot+=f1; else tot+=f2;
        cnt[tot%n]^=d[now];
        for (int i=head[now];i!=-1;i=edge[i].pre) {
            int to=edge[i].to;
            if (!visit[to]) {
                visit[to]=1;
                d[to]=d[now]^edge[i].dist;
                if (!d[to]) ca++; else cb++;
                q.push(to);
            }
        }
    }
}

int main() {
    int cas;
    scanf("%d",&cas);
	// mem0(cnt);mem0(rcnt);
	// memset(head,-1,sizeof(head));
	// memset(x,-1,sizeof(x));
    while (cas--) {
        f1=f2=-1;
        num=0;
        scanf("%d%d",&n,&m);
        memset(head, -1, sizeof(int)*n*2);
        memset(x, -1, sizeof(int)*n*2);
        memset(cnt, false, sizeof(bool)*n*2);
        memset(rcnt, false, sizeof(bool)*n*2);
        int st=0;
        for (int i=0;i<n;i++) {
            scanf("%s",s+st);
            for (int j=0;j<m;j++) {
                if (s[j+st]=='1') {
                    cnt[(i+j)%n]^=1;
                    rcnt[i]^=1;
                }
                if (s[j+st]=='X') {
                    f1=f2;f2=j;
                    if (x[(i+j)%n]==-1) x[(i+j)%n]=i,y[(i+j)%n]=j; else X1[(i+j)%n]=i,Y1[(i+j)%n]=j;
                }
            }
            st+=m;
        }
        scanf("%s",s);
        for (int i=0;i<n;i++) {
            R[i]=(bool)(s[i]-'0');
            if (rcnt[i]==R[i]) addedge(i*2,i*2+1,0); else addedge(i*2,i*2+1,1);
        }
        scanf("%s",s);
        for (int i=0;i<n;i++) {
            D[i]=(bool)(s[i]-'0');
            if (cnt[i]==D[i]) addedge(x[i]*2+(y[i]==f2),X1[i]*2+(Y1[i]==f2),0);
                else addedge(x[i]*2+(y[i]==f2),X1[i]*2+(Y1[i]==f2),1);
        }
     /*   if (n==1) {

        }
        if (m==1) {

        }*/
        int sum=0;
        for (int i=0;i<n*2;i++) {
            if (!visit[i]) {
				bfs(i);
	            if (ca>cb) swap(ca,cb);
	            sum+=ca;
			}
        }
        int flag=1;
        for (int i=0;i<n;i++) {
            if (cnt[i]!=D[i]) flag=0;
            if (rcnt[i]!=R[i]) flag=0;
			cnt[i]=rcnt[i]=0;
        }
        memset(visit, 0, sizeof(bool)*n*2);
		// for (int i=0;i<n*2;i++) head[i]=x[i]=-1,visit[i]=0;
        if (!flag) printf("No Solution\n"); else printf("%d %d\n",sum,n*2-sum);
    }
    return 0;
}
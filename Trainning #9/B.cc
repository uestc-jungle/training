#include<bits/stdc++.h>
#define mem0(a) memset(a,0,sizeof(a))
#define meminf(a) memset(a,0x3f,sizeof(a))
using namespace std;
typedef long long ll;
const int maxn=1005;
int dfn[maxn],low[maxn],color[maxn],head[maxn],val[maxn],c[maxn],cnt[maxn];
ll x[maxn],y[maxn],r[maxn];
bool inst[maxn];
stack<int> st;
int num=0,cnum;

struct Edge {
    int from,to,pre;
};
Edge edge[1000005];

void addedge(int from,int to) {
    edge[num].from=from;edge[num].to=to;
    edge[num].pre=head[from];head[from]=num++;
}

ll sqr(ll x) {
    return x*x;
}

void tarjan(int now) {
    num++;dfn[now]=low[now]=num;
    inst[now]=1;
    st.push(now);
    for (int i=head[now];i!=-1;i=edge[i].pre) {
        int to=edge[i].to;
        if (!dfn[to]) {
            tarjan(to);
            low[now]=min(low[now],low[to]);
        } else if (inst[to]) low[now]=min(low[now],dfn[to]);
    }
    if (dfn[now]==low[now]) {
        inst[now]=0;
        color[now]=++cnum;
        val[cnum]=min(val[cnum],c[now]);
        while (st.top()!=now) {
            color[st.top()]=cnum;
            inst[st.top()]=0;
            val[cnum]=min(val[cnum],c[st.top()]);
            st.pop();
        }
        st.pop();
    }
}

int main() {
    int cas,t=0;
    scanf("%d",&cas);
    while (cas--) {
        t++;
        int n;
        scanf("%d",&n);
        num=0;memset(head,-1,sizeof(head));
        for (int i=1;i<=n;i++) {
            scanf("%lld%lld%lld%d",&x[i],&y[i],&r[i],&c[i]);
        }
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=n;j++) {
                if (i==j) continue;
                if (sqr(r[i])>=sqr(x[i]-x[j])+sqr(y[i]-y[j])) addedge(i,j);
            }
        }
        num=cnum=0;
        mem0(dfn);mem0(inst);meminf(val);
        for (int i=1;i<=n;i++) if (!dfn[i]) tarjan(i);
        int ans=0;
        mem0(cnt);
        for (int i=1;i<=n;i++) {
            for (int j=head[i];j!=-1;j=edge[j].pre) {
                int to=edge[j].to;
                if (color[i]==color[to]) continue;
                cnt[color[to]]++;
            }
        }
        for (int i=1;i<=cnum;i++) if (!cnt[i]) ans+=val[i];
        printf("Case #%d: %d\n",t,ans);
    }
}
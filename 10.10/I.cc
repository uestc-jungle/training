#include<bits/stdc++.h>
#define mem0(a) memset(a,0,sizeof(a))
using namespace std;
typedef long long ll;
const int maxn=100005;
string s[maxn],t[maxn];

struct wayne {
    int f1,f2,r;
    bool m;
};
wayne a[maxn];

bool cmp(wayne a,wayne b) {
    return s[a.r]<s[b.r];
}

bool cmp2(wayne a,wayne b) {
    return t[a.r]<t[b.r];
}

int f[maxn],fm[maxn];
int lowbit(int x) {
    return x&(-x);
}
void update(int pos,int val,int n) {
    for (int i=pos;i<=n;i+=lowbit(i)) {
        f[i]=max(f[i],val);
    }
}
int findmax(int pos) {
    int ans=0;
    for (int i=pos;i>0;i-=lowbit(i)) {
        ans=max(ans,f[i]);
    }
    return ans;
}

void updatem(int pos,int val,int n) {
    for (int i=pos;i<=n;i+=lowbit(i)) {
        fm[i]=max(fm[i],val);
    }
}
int findmaxm(int pos) {
    int ans=0;
    for (int i=pos;i>0;i-=lowbit(i)) {
        ans=max(ans,fm[i]);
    }
    return ans;
}

int main() {
    int cas;
    ios::sync_with_stdio(false);
    cin >> cas;
    while (cas--) {
        int n;
        cin >> n;
        mem0(f);mem0(fm);
        for (int i=1;i<=n;i++) {
            cin >> s[i];
            int len=s[i].length();
            a[i].m=false;
            t[i]="";
            for (int j=1;j<=len;j++) {
                t[i]=t[i]+s[i][len-j];
                if (s[i][j-1]=='m') a[i].m=true;
            }
            a[i].r=i;
        }
        sort(a+1,a+n+1,cmp);
        for (int i=1;i<=n;i++) {
            a[i].f1=i;
        }
        sort(a+1,a+n+1,cmp2);
        for (int i=1;i<=n;i++) {
            a[i].f2=i;
        }
        int ans=1;
        for (int i=1;i<=n;i++) {
            if (a[i].m) {
                int mp=findmaxm(a[i].f1);
                int nans=mp+1;
                update(a[i].f1,nans,n);
                ans=max(ans,nans);
            } else {
                int mp=findmax(a[i].f1);
                int nans=mp+1;
                updatem(a[i].f1,nans,n);
                ans=max(ans,nans);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
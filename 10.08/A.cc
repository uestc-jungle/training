#include<bits/stdc++.h>
#define mem0(a) memset(a,0,sizeof(a))
typedef long long ll;
using namespace std;
const int maxn=100005,inf=0x3f3f3f3f;
const ll mod=998244353;
char s[maxn];

int main() {
    int cas;
    scanf("%d",&cas);
    while (cas--) {
        scanf("%s",s+1);
        int len=strlen(s+1);
        int ans=inf;
        for (int i=0;i<26;i++) {
            for (int j=0;j<26;j++) {
                int cnt=0;
                for (int k=1;k<=len;k++) {
                    if (k%2) {
                        if (s[k]-'a'!=i) cnt++;
                    } else {
                        if (s[k]-'a'!=j) cnt++;
                    }
                }
                ans=min(ans,cnt);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
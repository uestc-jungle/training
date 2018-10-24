#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=105;
int a[maxn],t[maxn];

int main() {
    int n,m,x;
    while (scanf("%d%d%d",&m,&n,&x)!=EOF) {
        for (int i=1;i<=n;i++) {
            scanf("%d",&a[i]);t[i]=0;
        }
        sort(a+1,a+n+1);
        for (int i=1;i<=min(m,n);i++) {
            t[i]=a[i];
        }
        m-=min(m,n);
        for (int i=1;i<=x;i++) {
            for (int j=1;j<=n;j++) {
                if (t[j]>0) t[j]--;
                if (t[j]==0&&m>0&&i!=x) {
                    t[j]+=a[j];
                    m--;
                }
            }
        }
        int cnt=0;
        for (int i=1;i<=n;i++) {
  //          cout << t[i] << ' ';
            if (t[i]!=0) cnt++;
        }
        printf("%d %d\n",m,cnt);
    }
    return 0;
}
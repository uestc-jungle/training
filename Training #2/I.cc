#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
long double a[maxn];
char s[maxn];

int main(){
    int T;
    scanf("%d", &T);
    while(T --){
        int n,m,x;
        scanf("%d%s", &n, s);
        long double ans=0;
        for (int i=1;i<=n;i++) {
            scanf("%d",&x);
            if (x==0) {
                continue;
            }
            a[i]=x;
            if (s[0]=='b') {
                ans+=-log2l(a[i])*a[i];
            } else if (s[0]=='n') {
                ans+=-logl(a[i])*a[i];
            } else {
                ans+=-log10l(a[i])*a[i];
            }
            if (s[0]=='b') {
                ans+= log2l(100.0L) * a[i];
            } else if (s[0]=='n') {
                ans+= logl(100.0L)*a[i];
            } else {
                ans+= log10l(100.0L)*a[i];
            }
        }
        ans /= 100.0L;
        printf("%.12Lf\n",ans);
    }
    return 0;
}
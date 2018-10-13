#include <cstdio>
#include <algorithm>
using namespace std;
char s[105];

struct wayne{
    int cnt;
    char lab;
};
wayne a[10];

bool cmp(wayne a,wayne b) {
    return a.cnt>b.cnt || (a.cnt==b.cnt&&a.lab<b.lab);
}

int main() {
    int n,m;
    while (scanf("%d%d",&n,&m)!=EOF) {
        if (n==0&&m==0) break;
        a[0].lab='A';a[1].lab='C';a[2].lab='D';a[3].lab='E';a[4].lab='G';
        for (int j=0;j<=4;j++) a[j].cnt=0;
        for (int i=1;i<=n;i++) {
            scanf("%s",s+1);
            for (int j=1;j<=m;j++) {
                for (int k=0;k<5;k++) if (a[k].lab==s[j]) a[k].cnt++;
            }
        }
        sort(a,a+5,cmp);
        a[5].cnt=0;
        for (int j=0;j<=5;j++) {
            if (a[j].cnt==0) {
                printf("\n");
                break;
            }
            if (j!=0) printf(" ");
            printf("%c %d",a[j].lab,a[j].cnt);
        }
    }
    return 0;
}
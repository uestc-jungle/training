#include <bits/stdc++.h>
#define mem0(a) memset(a,0,sizeof(a))
#define N 25
#define M 35
using namespace std;
const int inf=0x3f3f3f3f;
char s[N+2][M+2];
int a[N+2][M+2];

int main() {
    int cas;
    scanf("%d",&cas);
    while (cas--) {
        int n,m,t=0,cnt=0,ncnt;
        scanf("%d%d",&n,&m);
        for (int i=1;i<=N;i++) {
            for (int j=1;j<=M;j++) {
                s[i][j]='.';
            }
        }
        for (int i=12;i<n+12;i++) {
            scanf("%s",s[i]+16);
            for (int j=16;j<m+16;j++) {
                if (s[i][j]=='#') cnt++;
            }
            s[i][m+16]='.';
        }
   /*     for (int i=1;i<=N;i++) {
                for (int j=1;j<=M;j++) {
      //              printf("%d",a[i][j]);
                    printf("%c",s[i][j]);
                }
                printf("\n");
            }
            printf("\n");*/
        for (int T=1;T<=50;T++) {
            mem0(a);
            for (int i=1;i<=N;i++) {
                for (int j=1;j<=M;j++) {
                    if (s[i][j]=='.') continue;
                    a[i-1][j-1]++;a[i-1][j]++;a[i-1][j+1]++;
                    a[i][j-1]++;a[i][j+1]++;
                    a[i+1][j-1]++;a[i+1][j]++;a[i+1][j+1]++;
                }
            }
            ncnt=0;
         /*   for (int i=1;i<=N;i++) {
                for (int j=1;j<=M;j++) {
                    printf("%d",a[i][j]);
                }
                printf("\n");
            }
            printf("\n");*/
            for (int i=1;i<=N;i++) {
                for (int j=1;j<=M;j++) {
      //              printf("%d",a[i][j]);
                    if (s[i][j]=='.') {
                        if (a[i][j]==3) {
                            s[i][j]='#';ncnt++;
                        }
                    } else {
                        if (a[i][j]<2||a[i][j]>3) {
                            s[i][j]='.';
                        } else ncnt++;
                    }
                    printf("%c",s[i][j]);
                }
                printf("\n");
            }cout << '\n';
            if (ncnt>cnt) {
                cnt=ncnt;t=T;
            }
        }
        printf("%d %d %d\n",t,cnt,ncnt);
    }
}
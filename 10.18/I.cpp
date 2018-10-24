#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
int d[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
char s[maxn][maxn];

int main() {
    int cas;
    scanf("%d",&cas);
    while (cas--) {
        int n;
        scanf("%d",&n);
        if (n==1) {
            printf("#\n");
            continue;
        }
        if (n==2) {
            printf("##\n");
            printf(" #\n");
            continue;
        }
        if (n==3) {
            printf("###\n");
            printf("  #\n");
            printf("###\n");continue;
        }
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=n;j++) s[i][j]=' ';
        }
        for (int i=1;i<=n;i++) s[1][i]=s[i][n]=s[n][i]='#';
        for (int i=3;i<=n;i++) s[i][1]='#';
        int x=3,y=1,nd=0;
        while (1) {
            int nx=x+d[nd][0],ny=y+d[nd][1];
            if (s[nx+d[nd][0]][ny+d[nd][1]]=='#') {
                nd=(nd+1)%4;
            }
            nx=x+d[nd][0],ny=y+d[nd][1];
            if (s[nx+d[nd][0]][ny+d[nd][1]]=='#') break;
            if (nd==0||nd==2) {
                if (s[nx+d[1][0]][ny+d[1][1]]=='#') break;
                if (s[nx+d[3][0]][ny+d[3][1]]=='#') break;
            } else {
                if (s[nx+d[0][0]][ny+d[0][1]]=='#') break;
                if (s[nx+d[2][0]][ny+d[2][1]]=='#') break;
            }
 //           cout << nx << ' ' << ny << endl;
  //          scanf("%d",&x);
            s[nx][ny]='#';
            x=nx;y=ny;
        }
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=n;j++) printf("%c",s[i][j]);
            printf("\n");
        }
    }
}
#include<bits/stdc++.h>
using namespace std;
char ch[30][30] = {"B", "KB", "MB", "GB", "TB", "PB", "EB", "ZB", "YB" };
char s[105];
int main(){
    int T; int cn = 0;
    scanf("%d", &T);
    while(T --){
        scanf("%s",s+1);
        int len=strlen(s+1),pos;
        for (int i=1;i<=len;i++) {
            if (s[i]=='[') {
                pos=i;break;
            }
        }
        double u,d;
        int cnt=0;
        u=d=1;
        if (s[pos+1]=='B') cnt=0;
        if (s[pos+1]=='K') cnt=1;
        if (s[pos+1]=='M') cnt=2;
        if (s[pos+1]=='G') cnt=3;
        if (s[pos+1]=='T') cnt=4;
        if (s[pos+1]=='P') cnt=5;
        if (s[pos+1]=='E') cnt=6;
        if (s[pos+1]=='Z') cnt=7;
        if (s[pos+1]=='Y') cnt=8;
        u=pow(1000.0,cnt);
        d=pow(1024.0,cnt);
        double ans=(d-u)/d;
        printf("Case #%d: %.2lf%%\n", ++cn, (ans) * 100.0);
    }
}
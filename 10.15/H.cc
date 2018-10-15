#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1000005;
char s[maxn];

int main() {
    int cas,t=0,x,y;
    scanf("%d",&cas);
    while (cas--) {
        t++;
        scanf("%s%d%d",s+1,&x,&y);
        int len=strlen(s+1);
        int f1,f2,m1,m2,flag1,flag2,que=0,con=0,vol=0;
        flag1=flag2=0;
        f1=f2=m1=m2=0;
        for (int i=1;i<=len;i++) {
            if (s[i]=='?') {
                f1++;f2++;que++;
            } else {
                if (s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u') {
                    f2=0;f1++;vol++;s[i]='0';
                } else {
                    f1=0;f2++;con++;s[i]='1';
                }
            }
            m1=max(m1,f1);m2=max(m2,f2);
        }
        if (m1>=x||m2>=y) flag1=1;
        if (x==1) {
            if (vol==0&&que==0) flag2=1;
        }
        if (y==1) {
            if (con==0&&que==0) flag2=1;
        }
        int last=-1,bg=-1,l,r;
        if (x!=1&&y!=1) {
        for (int i=1;i<=len;i++) {
            if (s[i]=='?') {
                if (last==-1) bg=i;
                last=i;
            } else {
                if (last!=-1) {
                    if (bg==1) {
                        for (;last;last--)
                            if (s[last+1]=='0') s[last]='1'; else s[last]='0';
                    } else {
                        if (s[bg-1]=='0') s[bg]='1'; else s[bg]='0';
                        for (;last>bg;last--)
                            if (s[last+1]=='0') s[last]='1'; else s[last]='0';
                    }
                }
                last=-1;
            }
        }
        // from the right side
        if (last!=-1) {
            for (;bg<=len;bg++)
                if (s[bg-1]=='0') s[bg]='1'; else s[bg]='0';
        }
        f1=f2=m1=m2=0;
        for (int i=1;i<=len;i++) {
            if (s[i]=='0') f1++,f2=0; else f2++,f1=0;
            m1=max(m1,f1);m2=max(m2,f2);
        }
        if (m1<x&&m2<y) flag2=1;
        }
        printf("Case #%d: ",t);
        if (flag1&&flag2) printf("SURPRISE\n"); else 
            if (flag1) printf("DISLIKE\n"); else printf("LIKE\n");
        assert(flag1||flag2);
    }
}
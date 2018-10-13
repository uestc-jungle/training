#include<bits/stdc++.h>
using namespace std;
const int maxn = 1024;
char ch[maxn]; int rem;
bool check(){
    int len = strlen(ch+1);
    int sum = 0, minv = maxn;
    for(int i = 1; i <= len; i ++){
        if(ch[i] == '*') sum --;
        else sum ++;
        minv = min(sum, minv);
    }
    if(minv + rem >= 1) return true;
    return false;
}
int main(){
    int T;
    scanf("%d", &T);
    while(T --){
        scanf("%s", ch+1);
        int len = strlen(ch + 1);
        int cnt1=0, cnt2=0;
        for(int i = 1; i <= len; i ++){
            if(ch[i] == '*') cnt2 ++;
            else cnt1 ++;
        }

        rem = (cnt2 + 1 - cnt1 > 0) ? (cnt2 + 1 - cnt1) : 0;
        int cnt = 0, p1 = 1, p2 = len;
        while(!check()){
            for(; ch[p1] != '*'; p1 ++);
            for(; ch[p2] == '*'; p2 --);
            swap(ch[p1], ch[p2]);
            cnt ++;
        }
        printf("%d\n", rem + cnt);
    }
    return 0;
}
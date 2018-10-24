#include<bits/stdc++.h>
using namespace std;
const int maxn = 1001010;
char ch[maxn];
int s[maxn], t[maxn];
int main(){
    int n, T;
    scanf("%d", &T);
    while(T --){
        scanf("%d", &n);
        int st = 1;
        for(int i = 1; i <= n; i ++){
            scanf("%s", ch+st);
            st = strlen(ch+1) + 1;
        }
    }
}
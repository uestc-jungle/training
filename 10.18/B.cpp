#include<bits/stdc++.h>
using namespace std;
char ch[5][5], ans;
void check(){
    for(int i = 1; i <= 3; i ++){
        char tem = ch[i][1];
        for(int j = 1; j <= 3; j ++){
            if(ch[i][j] != ch[i][1]) tem = '\0';
        }
        if(tem && tem != '.')
            ans = tem;
    }
    for(int i = 1; i <= 3; i ++){
        char tem = ch[1][i];
        for(int j = 1; j <= 3; j ++){
            if(ch[j][i] != ch[1][i]) tem = '\0';
        }
        if(tem && tem != '.')
            ans = tem;
    }
    if(ch[1][1] == ch[2][2] && ch[2][2] == ch[3][3] && ch[2][2] != '.') ans = ch[2][2];
    if(ch[1][3] == ch[2][2] && ch[2][2] == ch[3][1] && ch[2][2] != '.') ans = ch[2][2];
}
int main(){
    int T, n;
    scanf("%d", &T);
    while(T --){
        for(int i = 1; i <= 3; i ++){
            scanf("%s", ch[i]+1);
        }
        ans = '\0';
        check();
        // if(!ans){
        //     int cnt = 0;
        //     for(int i = 1; i <= 3; i ++){
        //         for(int j = 1; j <= 3; j ++){
        //             if(ch[i][j] != '.')
        //                 cnt ++;
        //         }
        //     }
        //     char tem = '\0';
        //     if(cnt % 3 == 0) tem = 'C';
        //     else if(cnt % 3 == 1) tem = 'T';
        //     else tem = 'Z';

        //     for(int i = 1; i <= 3; i ++){
        //         for(int j = 1; j <= 3; j ++){
        //             if(ans) break;
        //             if(ch[i][j] == '.') continue;
        //             ch[i][j] = tem;
        //             check();
        //             ch[i][j] = '.';
        //         }
        //     }
        // }

        if(ans)
            printf("%c\n", ans);
        else
            printf("ongoing\n");
    }
}
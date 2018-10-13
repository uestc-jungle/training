#include<bits/stdc++.h>
using namespace std;
int SG[128][128];
int rem[128][128][513];
int main(){
    for(int i = 1; i <= 100; i ++){
        SG[i][i] = SG[i][0] = SG[0][i] = 1;
    }
    for(int i = 1; i <= 100; i ++){
        for(int j = 1; j <= 100; j ++){
            if(i == j) continue;
            for(int k = 1; k <= i; k ++)
                rem[i][j][SG[i-k][j]] = 1;
            for(int k = 1; k <= j; k ++)
                rem[i][j][SG[i][j-k]] = 1;
            for(int k = 1; k <= i && k <= j; k ++)
                rem[i][j][SG[i-k][j-k]] = 1;
            
            for(int k = 0; k < 512; k ++){
                if(!rem[i][j][k]){
                    SG[i][j] = k;
                    break;
                }
            }
        }
    }
    int T, x, y, ans=0, flag = 0;
    scanf("%d", &T);
    for(int i = 1; i <= T; i ++){
        scanf("%d%d", &x, &y);
        if(x == y){
            flag = 1;
        }
        ans ^= SG[x][y];
    }
    printf("%c", (flag || ans) ? 'Y' : 'N');
}    

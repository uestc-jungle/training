#include<bits/stdc++.h>
using namespace std;
int main(){
   int T;
   scanf("%d", &T);
   for(int cas = 1; cas <= T; cas ++){
       int n;
       printf("Case #%d: ", cas);
       scanf("%d", &n);
        if((n & 1) && (n >= 7)){
            printf("Panda\n");
        }
        else if((n % 2 == 0) && n >= 16){
            printf("Sheep\n");
        }
        else
            printf("Draw\n");
   } 
   return 0;
}
#include<bits/stdc++.h>
using namespace std;
int from[128], rem[128];
int n;
int main(){
    scanf("%d", &n);
    for(int i = 2; i <= n; i += 2){
        from[i] = i + 2;
    }
    from[n] = n - 1;

    for(int i = n-1; i > 1; i -= 2){
        from[i] = i - 2;
    }
    from[3] = 2;

    for(int i = 1; i <= n; i ++)
        rem[i] = i;
    
    // for(int i = 1; i <= n; i ++)
    //     printf("%d ", from[i]);
    // return 0;

    for(int tim = 1; tim <= n-1; tim ++){
        for(int i = 1; i <= n; i ++)
            printf("%d ", rem[i]);
        puts("");
        int tem = rem[2];
        for(int i = 2; i <= n; i += 2)
            rem[i] = rem[from[i]];

        for(int i = n-1; i > 1; i -= 2)
            rem[i] = rem[from[i]];
        

        rem[3] = tem;

    }

}
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int n; ll x, y, c;
int main(){
    scanf("%d", &n);
    while(n --){
        scanf("%lld%lld%lld", &x, &y, &c);
        printf("%lld\n", (x-y)*c > 0 ? (x-y)*c : 0);
    }
}
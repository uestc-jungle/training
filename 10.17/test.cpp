#include<bits/stdc++.h>
using namespace std;
int a[10010100];
int main(){
    int n = 10000000;
    for(int i = 1; i <= n; i ++){
        a[i] = i;
    }
    for(int i = 1; i <= n; i ++)
        swap(a[i-1], a[i]);
        // a[i-1] ^= a[i] ^= a[i-1] ^= a[i];
}
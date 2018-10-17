#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
map<ll, bool> mp;
int main(){
    for(ll i = 1; i <= 5e6; i ++){
        if(mp.find(i*(i+1)) != mp.end())
            printf("%lld ", i);
        mp[2*i*(i+1)] = true;
    }

}
#include<bits/stdc++.h>
using namespace std;

int main() {
    int cas;
    scanf("%d",&cas);
    while (cas--) {
        string a,b;
        cin >> a >> b;
        b[0]=(char)(b[0]-'a'+'A');
        cout << b+a << endl;
    }
}
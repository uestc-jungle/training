#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

const int maxn = 300100;
const int ALP = 26;

struct PAM{
    int nex[maxn][ALP];
    int fail[maxn];
    int num[maxn];
    int cnt[maxn];
    int len[maxn];
    int s[maxn];
    int last, n, tot;

    int newnode(int w){
        for(int i = 0; i < ALP; i ++){
            nex[tot][i] = 0;
        }
        cnt[tot] = 0;
        num[tot] = 0;
        len[tot] = w;
        return tot ++;
    }

    void init(){
        tot = 0;
        newnode(0);
        newnode(-1);
        last = 0;
        n = 0;
        s[n] = -1;
        fail[n] = 1;
    }

    int get_fail(int x){
        while(s[n-len[x]-1] != s[n]) x = fail[x];
        return x;
    }

    void add(int c){
        c -= 'a';
        s[++ n] = c;
        int cur = get_fail(last);
        if(!nex[cur][c]){
            int now = newnode(len[cur] + 2);
            fail[now] = nex[get_fail(fail[cur])][c];
            nex[cur][c] = now;
            num[now] = num[fail[now]] + 1;
        }
        last = nex[cur][c];
        cnt[last] ++;
    }

    void count(){
        for(int i = tot-1; i >= 0; i --){
            cnt[fail[i]] += cnt[i];
        }
    }
}A, B;
queue<pair<int, int> > q;
char ch_a[maxn], ch_b[maxn];
int main(){
    int T;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas ++){
        ll ans = 0;
        A.init(); B.init();
        scanf("%s%s", ch_a, ch_b);
        
        for(int i = 0; ch_a[i]; i ++) A.add(ch_a[i]);
        for(int i = 0; ch_b[i]; i ++) B.add(ch_b[i]);

        A.count(); B.count();

        int cur_a = 0, cur_b = 0;
        q.push(make_pair(cur_a, cur_b));
        q.push(make_pair(1, 1));
        while(!q.empty()){
            pair<int, int> tem_x = q.front(); q.pop();
            cur_a = tem_x.first, cur_b = tem_x.second;
            if(cur_a > 1)
                ans += (ll)A.cnt[cur_a] * (ll)B.cnt[cur_b];
            // printf("debug : %lld  %lld\n", (ll)A.cnt[cur_a], (ll)B.cnt[cur_b]);
            for(int i = 0; i < ALP; i ++){
                if(A.nex[cur_a][i] && B.nex[cur_b][i]){
                    q.push(make_pair(A.nex[cur_a][i], B.nex[cur_b][i]));
                }
            }
        }

        printf("Case #%d: %lld\n", cas, ans);
    }
}
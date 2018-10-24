#include<bits/stdc++.h>
using namespace std;
const int maxn = 101010;
typedef long long int ll;
struct QUER{
    int ql, qr, ln, num;
    bool operator < (const QUER &tx){
        if(ln != tx.ln) return ln < tx.ln;
        return qr < tx.qr;
    }
}quer[maxn];
vector<int> v[maxn];
int n, m;
ll prin[maxn];
const int len = 300;
int main(){
    int T, Q;
    scanf("%d", &T);
    while(T --){
        int tx, ty;
        scanf("%d%d%d", &n, &m, &Q);
        for(int i = 1; i <= n; i ++)
            v[i].clear();
        
        for(int i = 1; i <= m; i ++){
            scanf("%d%d", &tx, &ty);
            v[tx].push_back(ty);
            v[ty].push_back(tx);
        }
        for(int i = 1; i <= n; i ++){
            sort(v[i].begin(), v[i].end());
        }

        // scanf("%d", &Q);
        int ql, qr;
        int tl = 1, tr = 1;
        
        long long int ans = 0;
        for(int i = 1; i <= Q; i ++){
            scanf("%d%d", &quer[i].ql, &quer[i].qr);
            quer[i].ln = quer[i].ql / len;
            quer[i].num = i;
        }

        // return 0;


        for(int i = 1; i <= Q; i ++){
            ql = quer[i].ql, qr = quer[i].qr;
            while(tl > ql){
                tl --;
                ans += upper_bound(v[tl].begin(), v[tl].end(), tr) - lower_bound(v[tl].begin(), v[tl].end(), tl);
            }
            while(tr < qr){
                tr ++;
                ans += upper_bound(v[tr].begin(), v[tr].end(), tr) - lower_bound(v[tr].begin(), v[tr].end(), tl);
            }
            while(tl < ql){
                ans -= upper_bound(v[tl].begin(), v[tl].end(), tr) - lower_bound(v[tl].begin(), v[tl].end(), tl);
                tl ++;
            }
            while(tr > qr){
                ans -= upper_bound(v[tr].begin(), v[tr].end(), tr) - lower_bound(v[tr].begin(), v[tr].end(), tl);
                tr --;
            }

            prin[quer[i].num] = ans;
        }   
        for(int i = 1; i <= Q; i ++)
            printf("%lld\n", prin[i]);
    }
}
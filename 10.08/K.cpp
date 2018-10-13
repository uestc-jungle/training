#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int maxn = 101010;
int a[maxn], b[maxn];
ll sum[1024][1024], cnt[1024];
ll oth; const ll inf = 1e12;
int main(){
    int T, n, m;
    // printf("%d", -2/3);
    // return 0;
    scanf("%d", &T);
    while(T --){
        oth = 0;
        memset(cnt, 0, sizeof(cnt));
        memset(sum, 0, sizeof(sum));
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i ++){
            scanf("%d", &a[i]);
        }
        for(int i = 1; i <= n; i ++){
            scanf("%d", &b[i]);
        }
        for(int i = 1; i <= n; i ++){
            oth += b[i] / a[i];

            for(int j = b[i]%a[i]; j < a[i]; j ++)
                sum[a[i]][j] ++;
            cnt[a[i]] ++;
        }

        while(m--){
            int k, tx, ty;
            scanf("%d", &k);

            if(k == 1){
                scanf("%d%d", &tx, &ty);

                for(int j = b[tx]%a[tx]; j < a[tx]; j ++)
                    sum[a[tx]][j] --;
                cnt[a[tx]] --; oth -= b[tx]/a[tx];
                
                for(int j = b[tx] % ty; j < ty; j ++){
                    sum[ty][j] ++;
                }
                cnt[ty] ++; oth += b[tx] / ty;
                a[tx] = ty;
            }
            else if(k == 2){
                scanf("%d%d", &tx, &ty);
                for(int j = b[tx]%a[tx]; j < a[tx]; j ++)
                    sum[a[tx]][j] --;
                oth -= b[tx] / a[tx];

                for(int j = ty % a[tx]; j < a[tx]; j ++)
                    sum[a[tx]][j] ++;
                oth += ty / a[tx];
                b[tx] = ty;
            }
            else if(k == 3){
                scanf("%d", &tx);
                ll ql = 1, qr = inf;
                while(ql < qr){
                    ll mid = (ql + qr) / 2;
                    ll tsum = -oth;
                    for(int j = 1; j < 1024; j ++){
                        tsum += cnt[j] * (mid / j) - (sum[j][j-1] - sum[j][mid%j]);
                    }
                    if(tsum >= tx)
                        qr = mid;
                    else
                        ql = mid + 1;
                    // printf("%lld <-- \n", tsum);
                }
                // ll tsum = -oth;
                // for(int i = 1; i < 1024; i ++){
                //     tsum += cnt[i] * (ql / i) - (sum[i][i-1] - sum[i][ql%i]);
                // }
                // printf("%lld\n", oth);
                printf("%lld\n", ql);
            }
        }
    }
}
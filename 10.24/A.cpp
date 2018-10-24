#include<bits/stdc++.h>
using namespace std;
const int maxn = 51010;
int A[maxn], B[maxn];
struct Ques{
    int ask, num;
    bool operator < (const Ques & tx){
        return ask > tx.ask;
    }
}que[maxn];
bool ans[maxn];
bitset<maxn> a, b, tem;

int main(){
    int T, n, m, q;
    scanf("%d", &T);
    while(T --){
        a.reset(); b.reset();
        scanf("%d%d%d", &n, &m, &q);
        for(int i = 1; i <= n; i ++){
            scanf("%d", &A[i]);
            a.set(A[i]);
        }

        for(int i = 1; i <= m; i ++)
            scanf("%d", &B[i]);
        sort(B+1, B+1+m);

        for(int i = 1; i <= q; i ++){
            scanf("%d", &que[i].ask);
            que[i].num = i;
        }
        sort(que+1, que+1+q);

        // cout << a.count() << endl; 

        int pos = m;
        for(int i = 1; i <= q; i ++){
            while(B[pos] > que[i].ask){
                for(int j = 0; j * B[pos] < maxn; j ++){
                    b.flip(j*B[pos]);
                }
                pos --;
            }
            tem = a & (b << que[i].ask);

            // printf("%d\n", tem.count());
            ans[que[i].num] = tem.count() & 1;
            // printf("Debug : %d\n", que[i].num);
        }
        // for(int j = 0; j < 10; j ++)
        //     printf("%d ", b[j]);
        // cout << b.count() << endl;
        for(int i = 1; i <= q; i ++) printf("%d\n", ans[i]);
    }
    return 0;
}
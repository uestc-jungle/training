#include <bits/stdc++.h>

using namespace std;

namespace jspace {

typedef long long int ll;
const int maxn = 100100;

int N, K; ll M;
int A[maxn];

bool check(int x)
{
    ll s = 0;
    int cnt = 0;
    int i = 0, j = 0;
    for (i = 0; i < N; i++)
    {
        if (A[i] >= x) cnt++;
        if (cnt == K)
        {
            s += N - i;
            while (A[j] < x)
            {
                s += N - i;
                j++;
            }
            cnt --;
            j ++;
        }
    }
    // printf("Debug : %lld\n", s);
    // for(int i = 0;)
    return (s >= M);
}

int ans(void)
{
    int l = 1, r = 1e9;
    while (l < r)
    {
        int mid = ((l + r) >> 1) + 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    return l;
}

void main(void)
{
    scanf("%d%d%lld", &N, &K, &M);
    for (int i = 0; i < N; i++) scanf("%d", A+i);
    // check(1);
    printf("%d\n", ans());
}

}

int main(void)
{
    int T;
    scanf("%d", &T);
    while (T--) jspace::main();
    return 0;
}
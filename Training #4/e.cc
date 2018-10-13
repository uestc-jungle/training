#include <bits/stdc++.h>

using namespace std;

typedef double jfloat;
const double inf = 1e9;

int gcd(int m, int n) { return (0 == n) ? m : gcd(n, m % n); }

jfloat x;
int ap, aq;
jfloat aerr;

inline void upd(int tp, int tq)
{
    jfloat dp = tp, dq = tq;
    jfloat tx = dp / dq;
    if (fabs(x - tx) < aerr)
    {
        aerr = fabs(x - tx);
        ap = tp; aq = tq;
    }
}

void proc(void)
{
    static int K, M, g;
    scanf("%d%d%lf", &K, &M, &x);
    aerr = inf;
    for (int q = (M >> 1); q <= M; q++)
    {
        static int p;
        p = round(((double)q) * x);
        upd(p, q);
        // upd(p + 1, q);
    }
    g = gcd(ap, aq);
    ap /= g; aq /= g;
    printf("%d %d/%d\n", K, ap, aq);
}

int main(void)
{
    int P;
    scanf("%d", &P);
    while (P--) proc();
    return 0;
}

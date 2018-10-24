#include <bits/stdc++.h>

using namespace std;

namespace jspace {

typedef long long int ll;
typedef double jf;
const int maxn = 50500;

int N;
int a[maxn], b[maxn];

// const jf eps = 1e-8;
const jf k = log(2.) / log(3.);
/* return -1 if i < j, 0 if i == j, 1 if i > j */
int cmp(int i, int j)
{
    jf pi = k * a[i] + b[i];
    jf pj = k * a[j] + b[j];
    return (pi < pj) ? (-1) : (1);
}

int ansa[2], ansb[2];
void output(void)
{
    printf("%d %d %d %d\n", ansa[0], ansb[0], ansa[1], ansb[1]);
}

void all_lcm(void)
{
    ansa[0] = a[0]; ansb[0] = b[0];
    for (int i = 1; i < N; i++)
    {
        ansa[0] = max(ansa[0], a[i]);
        ansb[0] = max(ansb[0], b[i]);
    }
    ansa[1] = ansa[0];
    ansb[1] = ansb[0];
}
void all_gcd(void)
{
    ansa[0] = a[0]; ansb[0] = b[0];
    for (int i = 1; i < N; i++)
    {
        ansa[0] = min(ansa[0], a[i]);
        ansb[0] = min(ansb[0], b[i]);
    }
    ansa[1] = ansa[0];
    ansb[1] = ansb[0];
}
void middle(void)
{
    ansa[0] = a[0]; ansb[0] = b[0];
    ansa[1] = a[0]; ansb[1] = b[0];
    for (int i = 1; i < N; i++)
    {
        ansa[0] = max(ansa[0], a[i]);
        ansb[0] = max(ansb[0], b[i]);
        ansa[1] = min(ansa[1], a[i]);
        ansb[1] = min(ansb[1], b[i]);
    }
}

void do_gcd(int r)
{
    int ra = a[r], rb = b[r];
    int oa = -1, ob = -1;
    for (int i = 0; i < N; i++)
        if (i != r)
        {
            oa = max(oa, a[i]);
            ob = max(ob, b[i]);
        }
    a[N] = min(oa, ra); b[N] = min(ob, rb);
    a[N+1] = ansa[1]; b[N+1] = ansb[1];
    if (-1 == cmp(N, N+1))
    {
        ansa[1] = a[N];
        ansb[1] = b[N];
    }
}
void single_gcd(void)
{
    int mini = 0, mina = 0, minb = 0;
    ansa[0] = a[0]; ansb[0] = b[0];
    for (int i = 1; i < N; i++)
    {
        ansa[0] = max(ansa[0], a[i]);
        ansb[0] = max(ansb[0], b[i]);
        if (-1 == cmp(i, mini)) mini = i;
        if (a[i] == a[mina] && b[i] < b[mina]) mina = i;
        if (b[i] == b[minb] && a[i] < a[minb]) minb = i;
        if (a[i] < a[mina]) mina = i;
        if (b[i] < b[minb]) minb = i;
    }
    ansa[1] = 1000; ansb[1] = 1000;
    do_gcd(mini);
    do_gcd(mina);
    do_gcd(minb);
}

void do_lcm(int r)
{
    int oa = 1024, ob = 1024;
    for (int i = 0; i < N; i++)
        if (i != r)
        {
            oa = min(oa, a[i]);
            ob = min(ob, b[i]);
        }
    a[N] = max(oa, a[r]); b[N] = max(ob, b[r]);
    a[N+1] = ansa[0]; b[N+1] = ansb[0];
    if (-1 == cmp(N+1, N))
    {
        ansa[0] = a[N];
        ansb[0] = b[N];
    }
}
void single_lcm(void)
{
    int maxi = 0, maxa = 0, maxb = 0;
    ansa[1] = a[0]; ansb[1] = b[0];
    for (int i = 1; i < N; i++)
    {
        ansa[1] = min(ansa[1], a[i]);
        ansb[1] = min(ansb[1], b[i]);
        if (-1 == cmp(maxi, i)) maxi = i;
        if (a[i] == a[maxa] && b[i] > b[maxa]) maxa = i;
        if (b[i] == b[maxb] && a[i] > a[maxb]) maxb = i;
        if (a[i] > a[maxa]) maxa = i;
        if (b[i] > b[maxb]) maxb = i;
    }
    ansa[0] = 0; ansb[0] = 0;
    do_lcm(maxi); do_lcm(maxa); do_lcm(maxb);
}

void update(int ta, int tb)
{
    a[N] = ansa[0]; b[N] = ansb[0];
    a[N+1] = ansa[1]; b[N+1] = ansb[1];
    a[N+2] = ta; b[N+2] = tb;
    if (-1 == cmp(N, N+2))
    {
        ansa[0] = ta; ansb[0] = tb;
    }
    if (-1 == cmp(N + 2, N + 1))
    {
        ansa[1] = ta;
        ansb[1] = tb;
    }
}

void main(void)
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d %d", a+i, b+i);
    all_lcm(); output();
    if (N > 3)
    {
        single_gcd(); output();
        middle();
        for (int i = 2; i < N - 2; i++) output();
        single_lcm(); output();
    } else if (3 == N) {
        int id[] = {0, 1, 2};
        ansa[0] = 0; ansb[0] = 0;
        ansa[1] = 1024; ansb[1] = 1024;
        do
        {
            int ga = a[id[0]], gb = b[id[0]];
            int la = a[id[0]], lb = b[id[0]];
            ga = min(ga, a[id[1]]); gb = min(gb, b[id[1]]);
            ga = max(ga, a[id[2]]); gb = max(gb, b[id[2]]);
            update(ga, gb);
            la = max(la, a[id[1]]); lb = max(lb, b[id[1]]);
            la = min(la, a[id[2]]); lb = min(lb, b[id[2]]);
            update(la, lb);
        } while (next_permutation(id, id + 3));
        output();
    }
    if (N > 1) { all_gcd(); output(); }
}

}

int main(void)
{
    jspace::main();
    return 0;
}
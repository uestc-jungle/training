#include <bits/stdc++.h>

using namespace std;

#ifdef JDEBUGMODE
#define jdebug(...) fprintf(stderr, __VA_ARGS__)
#define jshow(...) fprintf(stderr, "%s\n", #__VA_ARGS__)
#else
#define jdebug(...) (void (0))
#define jshow(...) (void (0))
#endif

namespace jspace {

typedef long long int ll;
const int maxl = 500500;

int sl, tl;
char s[maxl], t[maxl << 1];
int p[maxl << 1];

const int maxn = maxl << 1;
ll f[maxn];
inline int lowbit(int x) { return x & (-x); }
void upd(int i, int d)
{
    while (i < tl)
    {
        f[i] += d;
        i += lowbit(i);
    }
}
ll sum(int i)
{
    ll ret = 0;
    while (i > 0)
    {
        ret += f[i];
        i -= lowbit(i);
    }
    return ret;
}
ll sum(int l, int r)
{
    return sum(r) - sum(l - 1);
}

struct pal
{
    int i, r;
    pal(int pos = 0, int right = 0) : i(pos), r(right) {}
    bool operator<(const pal &b) const { return r > b.r; }
};
priority_queue<pal> q;

void clear(void)
{
    memset(f, 0, (sizeof(int)) * (tl + 10));
    while (!q.empty()) q.pop();
}

ll run(void)
{
    ll ans = 0;
    int pos = 0, mxr = 0;
    clear();
    for (int i = 1; i < tl; i++)
    {
        if (i <= mxr) p[i] = min(p[2 * pos - i], mxr - i + 1);
        else p[i] = 1;
        while ( t[i - p[i]] == t[i + p[i]] ) p[i]++;
        if (i + p[i] - 1 > mxr)
        {
            mxr = i + p[i] - 1;
            pos = i;
        }
        jshow(i, p[i], is);
        jdebug("%d(%c): %d\n", i, t[i], p[i]);
        if (0 == (i & 1))
        {
            while ( !q.empty() && q.top().r < i )
            {
                upd(q.top().i, -1);
                jdebug("(%d,%d) will be poped\n", q.top().i, q.top().r);
                q.pop();
            }
            if (p[i] > 2)
            {
                #ifdef JDEBUGMODE
                ll d = sum(i - p[i] + 1, i - 1);
                #endif
                ans += sum(i - p[i] + 1, i - 1);
                jdebug("at %d, %lld added, got %lld\n", i, d, ans);
                jdebug("(%d,%d) will be pushed in\n", i, i + p[i] - 1);
                q.push(pal(i, i + p[i] - 1));
                upd(i, +1);
            }
        }
    }
    return ans;
}

void main(void)
{
    scanf("%s", s);
    tl = 0;
    t[tl++] = '^';
    for (char *p = s; *p; p++)
    {
        t[tl++] = '#';
        t[tl++] = *p;
    }
    t[tl++] = '#';
    t[tl] = '$';
    printf("%lld\n", run());
}

}

int main(void)
{
    int T;
    scanf("%d", &T);
    while (T--) jspace::main();
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 6;
const int MAXSI = 20;
const int MAXL = 100;

#ifdef JDEBUGMODE
#define jdebug(format, ...) fprintf(stderr, "Line %d: " format, __LINE__, __VA_ARGS__)
#else
#define jdebug(...) (void (0))
#endif

namespace acm {

const int ABSZ = 2;
const int TOTLEN = 256;
const int FIRSTA = '0';

struct vtx {
    vtx *fail, *nxt[ABSZ];
    int end[2]; /* 0 for original and reversed, 1 for sliced */
    bool vis[MAXL + 10][1 << MAXN];
    int dp[MAXL + 10][1 << MAXN];
    vtx(bool clear = false)
    {
        if (clear)
        {
            fail = NULL;
            nxt[0] = nxt[1] = NULL;
            end[0] = end[1] = 0;
            memset(dp, 0, sizeof dp);
            memset(vis, 0, sizeof vis);
        }
    }
}V[TOTLEN];
int nv;
vtx *new_node(void)
{
    vtx *ret = V + nv;
    *ret = vtx(true);
    nv++;
    return ret;
}

vtx *rt;

void init(void)
{
    nv = 0;
    rt = new_node();
}

void ins(const char *s, int type, int id)
{
    vtx *u = rt;
    jdebug("t: %d, id: %d, %s\n", type, id, s);
    for (const char *p = s; *p; p++)
    {
        int of = (*p) - FIRSTA;
        if (NULL == u->nxt[of])
            u->nxt[of] = new_node();
        u = u->nxt[of];
        jdebug("%c is %lu\n", *p, u - V);
    }
    u->end[type] |= (1 << id);
    jdebug("done-----------%c", '\n');
    // jdebug("%x, %d, %d\n", u->end[type], type, id);
}

void build(void)
{
    queue<vtx *> q;
    vtx *u = rt;
    for (int i = 0; i < ABSZ; i++)
        if (u->nxt[i])
        {
            q.push(u->nxt[i]);
            u->nxt[i]->fail = u;
        } else {
            u->nxt[i] = u;
        }
    u->fail = NULL;
    while (!q.empty())
    {
        u = q.front(); q.pop();
        if (u->fail)
        {
            u->end[0] |= u->fail->end[0];
            u->end[1] |= u->fail->end[1];
            // jdebug("end: %x, %x\n", u->end[0], u->end[1]);
        }
        for (int i = 0; i < ABSZ; i++)
            if (u->nxt[i])
            {
                q.push(u->nxt[i]);
                u->nxt[i]->fail = u->fail->nxt[i];
            } else {
                u->nxt[i] = u->fail->nxt[i];
            }
    }
}

}

namespace jspace {

typedef long long int ll;
const int m = 998244353;
inline int add(const int a, const int b)
{
    ll z = 0ll + a + b;
    if (z >= m) z -= m;
    return z;
}
inline int mul(const int a, const int b)
{
    ll z = 1ll * a * b;
    z -= z / m * m;
    return z;
}

int n, L;

using acm::vtx;

struct status
{
    vtx *u;
    int l;
    int S;
    status(vtx *uu = NULL, int ll = 0, int SS = 0)
        : u(uu), l(ll), S(SS)
    {}
};


int dp(void)
{
    int ans = 0;
    queue<status> q;
    q.push(status(acm::rt, 0, 0));
    acm::rt->dp[0][0] = 1;
    while(!q.empty())
    {
        status s = q.front(); q.pop();
        vtx *u = s.u;
        jdebug("dig into %lu,%d,%d v: %d\n", s.u - acm::V, s.l, s.S, u->dp[s.l][s.S]);
        assert(u != NULL);
        if (s.l == L)
        {
            if (s.S == ((1 << n) - 1))
                ans = add(ans, u->dp[L][(1 << n) - 1]);
        } else {
            for (int i = 0; i < acm::ABSZ; i++)
            {
                vtx *v = u->nxt[i];
                assert(v != NULL);
                int ns = s.S | v->end[0];
                // jdebug("%x, %x,%x\n", ns, v->end[0], v->end[1]);
                if (s.l == L - 1) ns |= v->end[1];
                v->dp[s.l + 1][ns] = add(v->dp[s.l + 1][ns], u->dp[s.l][s.S]);
                if (v->vis[s.l + 1][ns] == false)
                {
                    q.push(status(v, s.l + 1, ns));
                    v->vis[s.l + 1][ns] = true;
                }
            }
        }
    }
    return ans;
}

int len;
char s[32], t[32];
void main(void)
{
    acm::init();
    scanf("%d%d", &n, &L);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", s);
        len = strlen(s);
        acm::ins(s, 0, i);
        for (int j = 0; j < len; j++)
            t[j] = '1' + '0' - s[len - j - 1];
        t[len] = 0; acm::ins(t, 0, i);
        for (int j = 0; j < len - 1; j++)
        {
            bool ok = true;
            int sz = min(j + 1, len - 1 - j);
            for (int k = 0; k < sz; k++)
                if (s[j - k] == s[j + 1 + k])
                {
                    ok = false;
                    break;
                }
            if (ok)
            {
                int l = max(j + 1, len - 1 - j);
                for (int k = 0; k <= j; k++)
                    t[l - 1 - k] = s[j - k];
                for (int k = j + 1; k < l; k++)
                    t[l - 1 - k] = '1' + '0' - s[j + 1 + k];
                t[l] = 0;
                // jdebug("sep: %s\n", t);
                acm::ins(t, 1, i);
            }
        }
    }
    acm::build();
    printf("%d\n", dp());
    jdebug("---------------------------%c", '\n');
}

}

int main(void)
{
    int t;
    scanf("%d", &t);
    while (t--) jspace::main();
    return 0;
}

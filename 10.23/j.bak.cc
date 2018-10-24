#include <bits/stdc++.h>

using namespace std;

namespace acm {

const int ALPHASZ = 2;
const int FIRSTA = '0';
const int maxv = 1001000;

struct vtx
{
    vtx *fail, *nxt[ALPHASZ];
    int end;
    vtx(int clear = 0)
    {
        if (clear)
        {
            end = 0;
            fail = NULL;
            nxt[0] = nxt[1] = NULL;
        }
    }
}v[maxv];
int cntv;
vtx *new_vtx(void)
{
    vtx *ret = v + cntv;
    *ret = vtx(1);
    cntv++;
    return ret;
}

vtx *root;
void init(void)
{
    cntv = 0;
    root = new_vtx();
}

void ins(const char *s)
{
    vtx *u = root;
    for (const char *p = s; *p; p++)
    {
        int of = (*p) - FIRSTA;
        if (NULL == u->nxt[of])
            u->nxt[of] = new_vtx();
        u = u->nxt[of];
    }
    u->end = 1;
}

void build(void)
{
    queue<vtx *> q;
    vtx *u = root;
    for (int i = 0; i < ALPHASZ; i++)
    {
        if (u->nxt[i])
        {
            q.push(u->nxt[i]);
            u->nxt[i]->fail = u;
        } else {
            u->nxt[i] = u;
        }
    }
    u->fail = NULL;
    while (!q.empty())
    {
        u = q.front(); q.pop();
        if (u->fail) u->end |= u->fail->end;
        for (int i = 0; i < ALPHASZ; i++)
        {
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

int d[maxv];
void dfs(void)
{
    for (int i = 0; i < cntv; i++)
    {
        for (int j = 0; j < ALPHASZ; j++)
        {
            if (v[i].end) continue;
            vtx *u = v[i].nxt[j];
            if (u && !(u->end))
                ++deg[u - v];
        }
    }
    queue<vtx *> q;
    for (int i = 0; i < cntv; i++)
        if (0 == deg[i] && !(v[i].end))
        {
            d[i] = 0;
            q.push(v + i);
        }
    while (!q.empty())
    {
        vtx *u = q.front(); q.pop();
        for (int i = 0; i < ALPHASZ; i++)
        {
            vtx *y = u->nxt[i];
            if (y && !(y->end))
            {
                d[y - v] = d[u - v] + 1;
                q.push(y);
            }
        }
    }
}

}

namespace jspace {

const int maxl = 200200;
char s[maxl];
void main(void)
{
    int N;
    scanf("%d", &N);
    acm::init();
    while (N--)
    {
        scanf("%s", s);
        acm::ins(s);
    }
}

}

int main(void)
{
    jspace::main();
    return 0;
}
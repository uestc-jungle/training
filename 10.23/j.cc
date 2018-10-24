#include <bits/stdc++.h>

using namespace std;

namespace acm {

const int ALPHASZ = 2;
const int FIRSTA = '0';
const int maxv = 5001000;

struct vtx
{
    vtx *fail, *nxt[ALPHASZ];
    int d;
    bool vis;
    bool in;
    int end;
    vtx(int clear = 0)
    {
        if (clear)
        {
            d = 0;
            end = 0;
            vis = false;
            in = false;
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

int dfs(vtx *u)
{
    u->d = 0;
    u->vis = true;
    u->in = true;
    for (int i = 0; i < ALPHASZ; i++)
    {
        vtx *y = u->nxt[i];
        if (y->end) continue;
        if (!(y->vis))
        {
            if (dfs(y)) return -1;
        } else if (y->in) {
            return -1;
        }
        u->d = max(u->d, y->d + 1);
    }
    u->in = false;
    return 0;
}

vector<char> path;
int findpath(vtx *u)
{
    if (u->d == 0) return 1;
    for (int i = 0; i < ALPHASZ; i++)
    {
        vtx *y = u->nxt[i];
        if (y->end) continue;
        if (y->d + 1 == u->d)
        {
            path.push_back('0' + i);
            if (findpath(y)) return 1;
            path.pop_back();
        }
    }
    return 0;
}

void work(void)
{
    int r = dfs(root);
    if (-1 == r) puts("-1");
    else
    {
        findpath(root);
        for (auto b : path) putchar(b);
        puts("");
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
    acm::build();
    acm::work();
}

}

int main(void)
{
    jspace::main();
    return 0;
}
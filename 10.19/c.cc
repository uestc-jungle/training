#include <bits/stdc++.h>

using namespace std;

namespace jspace {

const int maxn = 300300;

struct node
{
    static int cnt;
    int v;
    node *n;
}nodes[maxn + 10];
int node::cnt;
node *new_node(int vv, node *nn)
{
    node *ret = &(nodes[ node::cnt ]);
    node::cnt++;
    ret->v = vv;
    ret->n = nn;
    return ret;
}

node *top[maxn + 10], *bot[maxn + 10];

void updtop(int s, node *newtop)
{
    top[s] = newtop;
    if (NULL == bot[s]) bot[s] = newtop;
}
void push(int s, int v)
{
    node *item = new_node(v, top[s]);
    top[s] = item;
    if (NULL == bot[s]) bot[s] = item;
}
int pop(int s)
{
    if (NULL == top[s]) return 0;
    int ret = top[s]->v;
    top[s] = top[s]->n;
    if (NULL == top[s]) bot[s] = NULL;
    return ret;
}
void concat(int s, int t)
{
    if (top[t])
    {
        bot[t]->n = top[s];
        top[s] = top[t];
        if (NULL == bot[s]) bot[s] = bot[t];
        top[t] = bot[t] = NULL;
    }
}

int n;

void clear(void)
{
    node::cnt = 0;
    for (int i = 1; i <= n; i++) top[i] = bot[i] = NULL;
}

void main(void)
{
    int q;
    scanf("%d%d", &n, &q);
    clear();
    while (q--)
    {
        int op, s, opend;
        int tmp;
        scanf("%d%d", &op, &s);
        if (1 == op)
        {
            scanf("%d", &opend);
            assert(opend > 0);
            push(s, opend);
        } else if (2 == op) {
            tmp = pop(s);
            // tmp ? printf("%d\n", tmp) : puts("EMPTY");
            if (tmp) printf("%d\n", tmp);
            else puts("EMPTY");
        } else if (3 == op) {
            scanf("%d", &opend);
            concat(s, opend);
        } else {
            assert(0);
        }
        // printf("%d on %d: %d\n", op, s, top[s] ? top[s]->v : 0);
    }
}

}

int main(void)
{
    int T;
    scanf("%d", &T);
    while (T--) jspace::main();
    return 0;
}

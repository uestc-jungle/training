#include <bits/stdc++.h>

using namespace std;

namespace jspace {

const int maxn = 500000;
char s[maxn + 100];

struct node
{
    static int cnt;
    char t;  /* 3 for |, 2 for &, 1 for !, 0 for literals */
    bool v;  /* 0 for F, 1 for T */
    bool b;  /* if it is surrounded by () */
    node *l, *r;
}nodes[maxn << 1];
int node::cnt;
node *new_node(char tt, bool vv, bool bb)
{
    node *ret = nodes + node::cnt;
    node::cnt++;
    ret->t = tt;
    ret->v = vv;
    ret->b = bb;
    ret->l = ret->r = NULL;
    return ret;
}

int op_top;
char op_stk[maxn + 100];
int expr_top;
node *expr_stk[maxn + 100];

void clear()
{
    node::cnt = 0;
    op_top = 0;
    expr_top = 0;
}

inline int op_id(int op)
{
    return ('|' == op) ? 3 :
           ('&' == op) ? 2 :
           ('!' == op) ? 1 : 9;
}
void inspect_op(void) { printf("op stack:"); for (int i = 0; i < op_top; i++) printf(" %d", op_stk[i]); puts(""); }
inline void push_op(int t)
{
    // int t = ('|' == op) ? 3 :
    //         ('&' == op) ? 2 :
    //         ('!' == op) ? 1 : 9;
    op_stk[op_top++] = t;
}
inline bool empty_op(void) { return op_top == 0; }
inline int top_op(void) { return op_stk[op_top - 1]; }
inline void pop_op(void) { if (!empty_op()) op_top--; }

void inspect_expr(void) { printf("expr stack:"); for (int i = 0; i < expr_top; i++) printf(" %d", expr_stk[i]->v); puts(""); }
inline void push_expr(node *e)
{
    expr_stk[expr_top++] = e;
}
inline bool empty_expr(void) { return 0 == expr_top; }
inline node *top_expr(void) { return expr_stk[expr_top - 1]; }
inline void pop_expr(void) { if (!empty_expr()) expr_top--; }

void do_calculation_once(void)
{
    /* TODO: */
    int op = top_op(); pop_op();
    node *o = new_node(op, false, false);
    if (1 == op)
    {
        node *e = top_expr(); pop_expr();
        o->l = e;
        o->v = !(e->v);
        o->b = true;
    } else {
        node *r = top_expr(); pop_expr();
        node *l = top_expr(); pop_expr();
        o->l = l; o->r = r;
        if (2 == op) o->v = (l->v) && (r->v);
        else o->v = (l->v) || (r->v);
    }
    push_expr(o);
}

/* aim is always true */
int dfs(node *u)
{
    if (u->b) return 1;
    if (0 == u->t) return 1;
    if (1 == u->t) return 1;
    if (2 == u->t) /* & */
    {
        if (false == u->l->v && false == u->r->v) return 0;
        if (false == u->l->v) return dfs(u->l);
        return dfs(u->r);
    }
    if (3 == u->t) /* | */
    {
        if (false == u->l->v) return dfs(u->l) ? 1 : dfs(u->r);
        return dfs(u->r);
    }
}

int proc()
{
    for (char *p = s; *p; p++)
    {
        // printf("at %c\n", *p);
        // inspect_op(); inspect_expr();
        if ('(' == *p) {
            push_op(9);
        } else if (')' == *p) {
            while (9 != top_op()) do_calculation_once();
            assert(9 == top_op()); pop_op();
            node *e = top_expr(); pop_expr();
            e->b = true;
            push_expr(e);
        } else if ('!' == *p) {
            int t = 1;
            while(*(p + 1) == '!') { p++; t++; }
            if (t & 1) push_op(1);
        } else if ('&' == *p) {
            while (!empty_op() && top_op() < op_id('&')) do_calculation_once();
            push_op(op_id('&'));
        } else if ('|' == *p) {
            while (!empty_op() && top_op() < op_id('|')) do_calculation_once();
            push_op(op_id('|'));
        } else {
            assert('T' == *p || 'F' == *p);
            push_expr(new_node(0, 'T' == *p, true));
        }
    }
    while (!empty_op()) do_calculation_once();
    assert(1 == expr_top);
    /* TODO: the root is expr_stk[0] */
    node *rt = expr_stk[0];
    if (rt->v) return 0;
    return dfs(rt) ? 1 : (1e9 + 7);
}

void main(void)
{
    clear();
    scanf("%s", s);
    printf("%d\n", min(2, proc()));
}

}

int main(void)
{
    int T;
    scanf("%d", &T);
    while (T--) jspace::main();
    return 0;
}

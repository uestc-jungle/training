/* Mudanjiang */
#include <bits/stdc++.h>

using namespace std;

inline void scann(int &x)
{
    scanf("%d", &x);
}
inline void scans(char *s)
{
    scanf("%s", s);
}

char global[5000500];
char query[5000500];
int ql, qr;

typedef unordered_map<string, int> usi;
int usedkeys;
unordered_map<string, int> keys[10010];
int new_mk(void)
{
    int ret = usedkeys;
    usedkeys++;
    keys[ret].clear();
    return ret;
}

struct jungle
{
    static int used;
    int l, r;
    int mapid;  /* if this is an object, mapid > -1*/
    jungle(int ll = -1, int rr = -1, int mm = -1)
    {
        l = ll;
        r = rr;
        mapid = mm;
    }
    void init(int ll = -1, int rr = -1, int mm = -1)
    {
        l = ll;
        r = rr;
        mapid = mm;
    }
}jo[20020];
int jungle::used;
int new_jo(int ll = -1, int rr = -1, int mm = -1)
{
    int ret = jungle::used;
    jungle::used++;
    jo[ret].init(ll, rr, mm);
    return ret;
}

void ask(void)
{
    static string field;
    int root = 0;
    char *p = query;
    ql = qr = -1;
    for(p = query; *p; p++)
    {
        field.clear();
        assert('"' == (*p));
        for (p++; '"' != (*p); ++p) field += (*p);
        assert(root < jungle::used);
        int mid = jo[root].mapid;
        if (-1 == mid) return;
        usi &okeys = keys[jo[root].mapid];
        auto it = okeys.find(field);
        if (it == okeys.end()) return;
        root = it->second;
        if ('.' == *(p + 1)) p++;
    }
    if (root < jungle::used)
    {
        ql = jo[root].l;
        qr = jo[root].r;
    }
}

int stk[20020], stop;

void jinit(void)
{
    usedkeys = 0;
    jungle::used = 0;
    stop = -1;
}

void parse(void)
{
    char *p;
    for (p = global; *p; p++)
    {
        if ('{' == (*p))
        {
            stk[++stop] = new_jo(p - global, -1, new_mk());
        } else if ('}' == (*p)) {
            int prev = stk[stop--];
            jo[prev].r = p - global;
        } else if (',' == (*p)) {
            continue;
        } else {
            static string key;
            assert('"' == (*p));
            key.clear();
            /* key is without quotes */
            for(p++; '"' != (*p); ++p)
                key += (*p);
            assert('"' == (*p));
            p++;
            assert(':' == (*p));
            p++;
            assert('"' == (*p) || ('{' == (*p)));
            int ch = new_jo(p - global);
            keys[jo[stk[stop]].mapid][key] = ch;
            if ('"' == (*p)) {
                for (p++; '"' != (*p); p++);
                assert('"' == (*p));
                jo[ch].r = p - global;
            } else {
                jo[ch].mapid = new_mk();
                stk[++stop] = ch;
            }
        }
    }
}

void proc(void)
{
    static int Q;
    jinit();
    scans(global);
    parse();
    scann(Q);
    while (Q--)
    {
        scans(query);
        ask();
        if (-1 == ql)
        {
            puts("Error!");
        } else {
            for (int i = ql; i <= qr; i++) putchar(global[i]);
            puts("");
        }
    }
}

int main(void)
{
    int T;
    scann(T);
    while (T--) proc();
    return 0;
}

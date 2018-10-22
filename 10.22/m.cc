#include <bits/stdc++.h>

using namespace std;

namespace jspace {

typedef long long int ll;
typedef double jf;
const int maxn = 100100;
const jf eps = 1e-6;

/* return -1 if a < b, 0 if a == b, 1 if a > b */
inline int cmp(jf a, jf b = 0.)
{
    if (fabs(a - b) <= eps) return 0;
    return (a < b) ? (-1) : (1);
}
inline jf sq(jf x) { return x * x; }

struct point
{
    jf x, y;
    point(jf xx = jf(), jf yy = jf()) : x(xx), y(yy) {}
    void scan(void) { scanf("%lf%lf", &x, &y); }
    jf norm2(void) { return sq(x) + sq(y); }
    jf norm(void) { return sqrt(norm2()); }
    point operator+(const point &b) const { return point(x + b.x, y + b.y); }
    point operator-(const point &b) const { return point(x - b.x, y - b.y); }
    point operator->*(const point &b) const { return (b - (*this)); }
    point operator*(const jf k) const { return point(x * k, y * k); }
    point operator/(const jf k) const { return point(x / k, y / k); }
    jf operator*(const point &b) const { return (x * b.x + y * b.y); }
    jf operator^(const point &b) const { return (x * b.y - b.x * y); }
    point _(void) const { return point(y, -x); }
}P[maxn];

struct line
{
    point a, b;
    line(point s = point(), point t = point()) : a(s), b(t) {}
    bool parallel(const line &o) const
    {
        return !cmp((a - b) ^ (o.a - o.b));
    }
    bool make_point(const line &o, point &res) const
    {
        if (parallel(o)) return false;
        jf s1 = (a - o.a) ^ (o.b - o.a);
        jf s2 = (b - o.a) ^ (o.b - o.a);
        res = (b * s1 - a * s2) / (s1 - s2);
        return true;
    }
};

int N;

point O;
jf r;

int jrandom(void)
{
    ll x = 1ll * rand() * rand();
    return x % N;
}

typedef point Point;
Point CircumCenter(Point a,Point b,Point c){  //三角形的外心
    Point cp;
    double a1 = b.x-a.x,b1 = b.y-a.y,c1 = (a1*a1 + b1*b1)/2;
    double a2 = c.x-a.x,b2 = c.y-a.y,c2 = (a2*a2 + b2*b2)/2;
    double d = a1*b2 - a2*b1;
    cp.x = a.x + (c1*b2-c2*b1)/d;
    cp.y = a.y + (a1*c2-a2*c1)/d;
    return cp;
}
// --------------------- 
// 作者：wchhlbt 
// 来源：CSDN 
// 原文：https://blog.csdn.net/wchhlbt/article/details/78510455 
// 版权声明：本文为博主原创文章，转载请附上博文链接！

bool god_bless(void)
{
    int i, j, k;
    i = jrandom();
    do { j = jrandom(); } while (i == j);
    do { k = jrandom(); } while (i == k || j == k);
    // point AB = P[i]->*P[j], AC = P[i]->*P[k];
    // point D = (P[i] + P[j]) * 0.5, E = (P[i] + P[k]) * 0.5;
    // bool ok = line(D, D + (AB._())).make_point(line(E, E + (AC._())), O);
    // if (!ok) return false;
    O = CircumCenter(P[i], P[j], P[k]);
    if (fabs(O.x) > 1e9 || fabs(O.y) > 1e9) return false;
    r = (O ->* P[i]).norm();
    jf r2 = (O ->* P[i]).norm();
    int cnt = 0;
    for (int l = 0; l < N; l++)
    {
        jf tr = (O ->* P[l]).norm();
        if (0 == cmp(r2, tr)) cnt++;
    }
    return ((cnt << 1) >= N);
}

void main(void)
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++) P[i].scan();
    if (1 == N)
    {
        O = P[0];
        printf("%.12lf %.12lf 0\n", O.x, O.y);
        return;
    } else if (4 >= N) {
        point M = (P[0] + P[1]) * 0.5;
        printf("%.12lf %.12lf %.12lf\n", M.x, M.y, (P[0]->*M).norm());
        return;
    }
    while (1)
    {
        if (god_bless())
        {
            printf("%.12lf %.12lf %.12lf\n", O.x, O.y, r);
            return;
        }
    }
    // ((void (*)(void))NULL)();
}

}

int main(void)
{
    int T;
    srand(time(NULL));
    scanf("%d", &T);
    while (T--) jspace::main();
    return 0;
}

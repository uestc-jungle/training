#include<bits/stdc++.h>
using namespace std;

typedef double jf;
const jf eps = 1e-8;

int jcmp(jf a, jf b = 0.)
{
    if (fabs(a - b) <= eps) return 0;
    return (a < b) ? (-1) : 1;
}

struct point{
    jf x, y;
    point(jf xx = jf(), jf yy = jf()) : x(xx), y(yy) {}
    jf sq(jf x) { return x * x; }
    jf norm2(void) { return sq(x) + sq(y); }
    jf norm(void) { return sqrt(norm2()); }
    point operator+(const point &b) const { return point(x + b.x, y + b.y); }
    point operator-(const point &b) const { return point(x - b.x, y - b.y); }
    jf operator*(const point &b) const { return x * b.x + y * b.y; }
    jf operator^(const point &b) const { return x * b.y - b.x * y; }
};

jf R, l, w;
jf A, B;

jf dis(const point p, const point s, const point t)
{
    if (jcmp((p - s) * (t - s)) < 0) return (p - s).norm();
    if (jcmp((p - t) * (s - t)) < 0) return (p - t).norm();
    return fabs( ((s-p) ^ (t-p)) / ((s-t).norm()) );
}
jf ldis(point s1, point t1, point s2, point t2)
{
    return min(
        min(dis(s1, s2, t2), dis(t1, s2, t2)),
        min(dis(s2, s1, t1), dis(t2, s1, t1))
    );
}

jf answer(void)
{
    scanf("%lf%lf", &A, &B);
    point P1(-1., w), P2(0., w), P3(l, w), P5(l, 0), P7(1000., w);
    point P4 = P3 + point(-cos(A) * l, sin(A) * l);
    point P6 = P5 + point(-cos(B) * l, sin(B) * l);
    jf ans = 1e9;
    ans = min(ans, ldis(P1, P2, P3, P4));
    // printf("%lf\n", ans);
    ans = min(ans, ldis(P5, P6, P3, P4));
    // printf("%lf\n", ans);
    ans = min(ans, ldis(P5, P6, P3, P7));
    // printf("%lf\n", ans);
    return min(ans * 0.5, R);
}

int main(){
    scanf("%lf%lf%lf", &R, &l, &w);
    int T;
    scanf("%d", &T);
    while (T--) printf("%.8lf\n", answer());
    return 0;
}
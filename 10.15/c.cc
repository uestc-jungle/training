#include <bits/stdc++.h>

using namespace std;

namespace jspace {

typedef double jf;

jf proc(void)
{
    int N;
    jf ans = .0;
    scanf("%d", &N);
    for (int i = 0; i <= N; i++)
    {
        int si;
        scanf("%d", &si);
        ans += si;
    }
    jf maxbi = .0;
    for (int i = 0; i < N; i++)
    {
        jf bi;
        scanf("%*lf%lf", &bi);
        maxbi = max(maxbi, bi);
    }
    ans += maxbi;
    return ans;
}

int casid;
void main(void)
{
    printf("Case #%d: %.12lf\n", ++casid, proc());
}

}

int main(void)
{
    int T;
    scanf("%d", &T);
    while (T--) jspace::main();
    return 0;
}

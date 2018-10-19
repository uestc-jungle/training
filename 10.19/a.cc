#include <bits/stdc++.h>

using namespace std;

namespace jspace {

void main(void)
{
    int n, m, A, B;
    scanf("%d%d%d%d", &n, &m, &A, &B);
    int cnt = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            static int aij;
            scanf("%d", &aij);
            cnt += (aij < A || aij > B);
        }
    if (A > B) puts("No Solution");
    else printf("%d\n", cnt);
}

}

int main(void)
{
    int T;
    scanf("%d", &T);
    while (T--) jspace::main();
    return 0;
}

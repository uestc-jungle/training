#include <bits/stdc++.h>

using namespace std;

namespace jspace {

const int maxn = 1 << 5;

int n, p;
int g[maxn][maxn];


#define jor(i,s,t) for (int i = s; i < t; i++)

bool check(int x, int y, int z, int w)
{
    int u[] = {x, y, z, w};
    jor(i, 0, 4) jor(j, i+1, 4)
        if (0 == g[u[i]][u[j]])
            return false;
    return true;
}

void clear(void)
{
    memset(g, 0, sizeof g);
}
void proc(void)
{
    scanf("%d%d", &n, &p);
    while (p--)
    {
        int i, j;
        scanf("%d%d", &i, &j);
        g[i][j] = g[j][i] = 1;
    }
    jor(i, 0, n) jor(j, i+1, n) jor(k, j+1, n) jor(l, k+1, n)
    {
        if (check(i, j, k, l))
        {
            puts("N");
            return;
        }
    }
    puts("Y");
}

void main(void)
{
    clear();
    proc();
}

}

int main(void)
{
    int T;
    scanf("%d", &T);
    while (T--) jspace::main();
    return 0;
}
